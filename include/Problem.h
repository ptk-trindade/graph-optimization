#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <map>
#include <tuple>

struct Item {
    int prize;
    int weight;
    std::vector<std::tuple<int, int>> synergies;
};

class Problem {
public:
    Problem(const std::string& filename);
    std::vector<Item> items;
    int capacity;

    Solution generateInitialSolution();
};

#endif // PROBLEM_H
