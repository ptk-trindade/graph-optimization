#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <map>

struct Item {
    int prize;
    int weight;
    std::vector<std::pair<int, int>> synergies; // id, synergy
};

class Problem {
public:
    std::vector<Item> items;
    int capacity;

};

#endif // PROBLEM_H
