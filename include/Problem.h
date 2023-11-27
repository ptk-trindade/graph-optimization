#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <map>

struct Item {
    int prize;
    int weight;
    std::vector<int,int> synergies;
};

class Problem {
public:
    std::vector<Item> items;
    int capacity;

};

#endif // PROBLEM_H
