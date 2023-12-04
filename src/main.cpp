#include "../include/Solution.h"
#include "../include/Problem.h"

#include <iostream>

Solution* grasp(const Solution& initialSolution, float alpha) {
    Solution* bestKnapsack = new Solution(initialSolution);

    bool stopCriteria;
    while (!stopCriteria) {
        Solution solution(initialSolution);

        bool reachedLocalMax;
        while(!reachedLocalMax) {
            const std::vector<Neighbor>& neighbors = solution.getNeighbors();

            // Choose solution randomly based on alpha (break if no neighbor is better)
            int neighborId;
            solution.step(neighborId);
        }


        if (bestKnapsack == nullptr || bestKnapsack->prize < solution.prize) {
            bestKnapsack = &solution;
        }

    }

    return bestKnapsack;
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <numItems> <fileId>" << std::endl;
        return 1;
    }

    // Get numItems and fileId from command line arguments
    const std::string numItems = argv[1];
    const std::string fileId = argv[2];
    const std::string filename = "../data/sum_instances/" + numItems + "/kpf_" + fileId + "_sum.txt";

    float alpha = 0.7;

    // Read file and create Problem
    Problem problem(filename);

    // Get initial Solution
    Solution initialSolution = problem.generateInitialSolution();

    // Call the grasp function with the initial solution and alpha
    Solution* bestSolution = grasp(initialSolution, alpha);

    return 0;
}
