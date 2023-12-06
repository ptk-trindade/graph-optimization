#include "../include/Solution.h"
#include "../include/Problem.h"

#include <iostream>
#include <chrono>

Solution* grasp(Problem problem, float alpha) {
    Solution* bestKnapsack = new Solution(problem.generateInitialSolution());
    std::cout << "prize inicial grasp: " << bestKnapsack->prize << std::endl;

    // current time
    std::chrono::time_point<std::chrono::system_clock> currentTime, endTime;
    currentTime = std::chrono::system_clock::now();
    endTime = currentTime + std::chrono::seconds(10);
    while (currentTime < endTime) {
        
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
            std::cout << "prize atualizado: " << solution.prize << std::endl;
            bestKnapsack = new Solution(solution);
        }

        currentTime = std::chrono::system_clock::now();
    }

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

    std::cout << "File: " << filename << std::endl;

    float alpha = 0.7;

    // Read file and create Problem
    Problem problem(filename);

    // Call the grasp function with the initial solution and alpha
    Solution* bestKnapsack = grasp(problem, alpha);
    std::cout << "prize inicial main: " << bestKnapsack->prize << std::endl;

    // Print the best solution found
    std::cout << "prize:" << bestKnapsack->prize << std::endl;
    for (int i = 0; i < int(bestKnapsack->itemInBackpack.size()); i++) {
        if (bestKnapsack->itemInBackpack[i]) {
            std::cout << i << " ";
        }
    }
    
    std::cout << std::endl;

    return 0;
}
