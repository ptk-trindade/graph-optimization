#ifndef SOLUTION_H
#define SOLUTION_H

#include "Problem.h"
#include "SolutionStep.h"
#include <vector>
#include <map>

class Solution {
public:
    Problem problem;

    std::vector<Item> items;
    int prize;
    int availableCapacity;
    std::map<int, int> itemsInBackpack;

    std::vector<SolutionStep> neighbors();
    Solution step(SolutionStep);

private:
    void add(int itemId);
    void remove(int itemId);
};

#endif // SOLUTION_H
