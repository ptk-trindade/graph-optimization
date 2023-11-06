#include "Solution.h"
#include "Problem.h"
#include "SolutionStep.h"
#include "Item.h"

int main() {
    // Create an example Problem
    Problem problem;
    // Set problem data (items and capacity)
    
    // Create an example Solution
    Solution solution;
    solution.problem = problem;

    // Perform some operations on the solution using SolutionStep
    SolutionStep step;
    // Set step data

    solution = solution.step(step);

    // Output or further manipulate the updated solution

    return 0;
}
