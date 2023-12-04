#include "../include/Solution.h"
#include "../include/Problem.h"

#include <iostream>

Solution* grasp(Problem* problem, float alpha) {
    Solution* bestKnapsack;

    bool stopCriteria;
    while (!stopCriteria) {
        // Create random Solution
        Solution solution(problem, std::vector<int>());

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

    // Create filename based on numItems and fileId
    const std::string filename = "../data/sum_instances/" + numItems + "/kpf_" + fileId + "_sum.txt";

    // Read file and create Problem
    Problem problem(filename);
    float alpha = 0.7;

    // Call your existing function with the problem and alpha
    grasp(&problem, alpha);

    return 0;
}