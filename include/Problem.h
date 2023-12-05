#ifndef PROBLEM_H
#define PROBLEM_H

#include "Solution.h"
#include <map>
#include <string>
#include <tuple>
#include <vector>

class Solution;

struct Item {
    int prize;
    int weight;
    std::vector<std::pair<int, int>> synergies; // id, synergy
};

class Problem {
public:
    Problem(const std::string& filename);
    std::vector<Item> items;
    int capacity;

    Solution generateInitialSolution();
};

#endif // PROBLEM_H
