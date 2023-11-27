#ifndef SOLUTION_H
#define SOLUTION_H

#include "Problem.h"
#include <vector>
#include <map>

// You can think of Neighbor as a Solution prototype. 
// It only has a few attributes since recreating all attributes would be costly
struct Neighbor {
public:
    int prize;
    bool adding; // true = add; false = remove
    int itemId; // item to be added/removed
};

class Solution {
public:
    Solution(Problem *problem, std::vector<int> initialItems);
    Problem& problem;

    std::vector<Item> items;
    int prize;
    int availableCapacity;
    std::map<int, int> itemsInBackpack;
    std::vector<Neighbor>& neighbors;

    const std::vector<Neighbor>& getNeighbors();
    void step(int neighborId);
    void randomWalk(float randomness);

private:
    void add(int itemId);
    void remove(int itemId);

    void calculatePrize();
};

#endif // SOLUTION_H
