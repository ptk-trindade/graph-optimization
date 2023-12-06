#include "../include/Solution.h"
#include "../include/Problem.h"

#include <iostream>
#include <chrono>
#include <vector>
#include <math.h>

void printStatistics(int bestKnapsackPrize, std::vector<float> timesTaken, std::vector<int> bestPrizes) {

    float avgTime = 0;
    float avgPrize = 0;
    for (int i = 0; i < int(timesTaken.size()); i++) {
        avgTime += timesTaken[i];
        avgPrize += bestPrizes[i];
    }

    avgTime /= timesTaken.size();
    avgPrize /= bestPrizes.size();

    float cvTime = 0;
    float cvPrize = 0;
    for (int i = 0; i < int(timesTaken.size()); i++) {
        cvTime += (timesTaken[i] - avgTime) * (timesTaken[i] - avgTime);
        cvPrize += (bestPrizes[i] - avgPrize) * (bestPrizes[i] - avgPrize);
    }

    cvTime /= timesTaken.size();
    cvPrize /= bestPrizes.size();

    cvTime = sqrt(cvTime) / avgTime;
    cvPrize = sqrt(cvPrize) / avgPrize;

    std::cout << bestKnapsackPrize << "\t" << avgPrize << "\t" << cvPrize << "\t" << avgTime << "\t" << cvTime << std::endl;

}

Solution* grasp(Problem problem, float alpha) {
    // statistics
    std::vector<float> timesTaken;
    std::vector<int> bestPrizes;

    Solution* bestKnapsack = new Solution(problem.generateInitialSolution());

    // current time
    std::chrono::time_point<std::chrono::system_clock> currentTime, endTime;
    currentTime = std::chrono::system_clock::now();
    endTime = currentTime + std::chrono::minutes(1);
    while (currentTime < endTime) {
        // cronometro
        auto statisticsTime = std::chrono::system_clock::now();

        // Get initial Solution
        Solution solution = problem.generateInitialSolution();
        std::vector<Neighbor>& neighbors = solution.getNeighbors();

        int iterations = 0;
  
        float maxHeuristic = -1.0f;
        for (Neighbor neighbor : neighbors) {
            if (neighbor.heuristic > maxHeuristic) {
                maxHeuristic = neighbor.heuristic;
            }
        }

        std::vector<int> bestNeighbors;
        float threshold = alpha * maxHeuristic;
        for (int i = 0; i < neighbors.size(); ++i) {
            if (neighbors[i].heuristic >= threshold) {
                bestNeighbors.push_back(i);
            }
        }

        if (!bestNeighbors.empty()) {
            int randomIndex = rand() % bestNeighbors.size();
            solution.step(bestNeighbors[randomIndex]);
        }

        if (bestKnapsack == nullptr || bestKnapsack->prize < solution.prize) {
            bestKnapsack = new Solution(solution);
        }

        currentTime = std::chrono::system_clock::now();
        timesTaken.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - statisticsTime).count());
        bestPrizes.push_back(solution.prize);
    }

    printStatistics(bestKnapsack->prize, timesTaken, bestPrizes);

    return bestKnapsack;
}


int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <numItems> <fileId>" << std::endl;
        return 1;
    }

    // Get numItems and fileId from command line arguments
    const std::string numItems = argv[1];
    const std::string fileId = argv[2];
    const std::string filename = "data/sum_instances/" + numItems + "/kpf_" + fileId + "_sum.txt";

    std::cout << numItems << "/kpf_" << fileId << "_sum.txt" << "\t";

    float alpha = 0.8;

    // Read file and create Problem
    Problem problem(filename);

    // Call the grasp function with the initial solution and alpha
    grasp(problem, alpha); // Solution* bestKnapsack = 

    // // Print the best solution found
    // std::cout << "prize:" << bestKnapsack->prize << std::endl;
    // for (int i = 0; i < int(bestKnapsack->itemInBackpack.size()); i++) {
    //     if (bestKnapsack->itemInBackpack[i]) {
    //         std::cout << i << " ";
    //     }
    // }
    
    // std::cout << std::endl;

    return 0;
}
