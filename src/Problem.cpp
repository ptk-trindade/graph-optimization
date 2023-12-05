#include "../include/Problem.h"
#include "../include/Solution.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

Problem::Problem(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        if (file.fail()) std::cerr << "Fail bit is set (stream state is bad)" << std::endl;
        if (file.eof())  std::cerr << "End-of-file reached" << std::endl;
        if (file.bad())  std::cerr << "Stream is corrupted" << std::endl;
        return;
    }

    int numItems, numPenalties;
    
    file >> numItems >> numPenalties >> capacity;

    items.resize(numItems);

    // Read prizes
    for (int i = 0; i < numItems; ++i) {
        file >> items[i].prize;
    }

    // Read weights
    for (int i = 0; i < numItems; ++i) {
        file >> items[i].weight;
    }

    // Read penalties
    for (int p = 0; p < numPenalties; ++p) {
        int synergy, discard, item1, item2;
        file >> discard >> synergy >> discard;
        file >> item1 >> item2;

        items[item1].synergies.push_back(std::make_pair(item2, synergy));
        items[item2].synergies.push_back(std::make_pair(item1, synergy));
    }

    file.close();

    return;
}

Solution Problem::generateInitialSolution() {
    std::vector<int> initialItems;
    int availableCapacity = capacity;
    int totalItems = items.size();
    int addedItems = 0;
    std::vector<bool> itemInBackpack = std::vector<bool>(totalItems, false);

    int emptySpace = capacity - (rand() % capacity);
    // std::cout << "random: " << emptySpace << std::endl;

    while (emptySpace < availableCapacity && addedItems < totalItems) {
        int randomItem = rand() % totalItems;
        if (!itemInBackpack[randomItem]) {
            if (items[randomItem].weight <= availableCapacity) {
                itemInBackpack[randomItem] = true;
                availableCapacity -= items[randomItem].weight;
                initialItems.push_back(randomItem);
            }
            addedItems++;
        }
    }

    Solution solution(this, initialItems);
    return solution;
}