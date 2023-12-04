#include "../include/Problem.h"
#include "../include/Solution.h"
#include <fstream>
#include <iostream>

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
        int penalty;
        file >> penalty;

        for (int i = 0; i < numItems; ++i) {
            int synergy;
            file >> synergy;
            items[i].synergies.push_back(std::make_pair(penalty, synergy));
        }
    }

    file.close();

    return;
}

Solution Problem::generateInitialSolution() {
    std::vector<int> initialItems;
    int availableCapacity = capacity;
    int prize = 0;
    int total_items = items.size();
    int checked_items = 0;

    std::vector<bool> itemsInBackpack = std::vector<bool>(total_items);

    while (availableCapacity > 0) {
        int randomItem = rand() % total_items;
        if (!itemsInBackpack[randomItem]) {
            if (items[randomItem].weight <= availableCapacity) {
                itemsInBackpack[randomItem] = true;
                availableCapacity -= items[randomItem].weight;
                prize += items[randomItem].prize;
                initialItems.push_back(randomItem);
            }
            checked_items++;
        }
        if (checked_items == total_items) {
            break;
        }
    }

    Solution solution(this, initialItems);
    return solution;
}