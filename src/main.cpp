#include "Solution.h"
#include "Problem.h"


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


int main() {
    // Read file and create Problem
    Problem problem;
    float alpha = 0.7;

    grasp(&problem, alpha);

    return 0;
}