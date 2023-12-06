#ifndef SOLUTION_H
#define SOLUTION_H

#include "Problem.h"
#include <vector>
#include <map>

struct Item;
class Problem;

// You can think of Neighbor as a Solution prototype. 
// It only has a few attributes since recreating all attributes would be costly
struct Neighbor {
public:
    int deltaPrize;
    // float heuristic;
    std::vector<int> addedItems;
    std::vector<int> removedItems;
};

class Solution {
public:
    Solution(Problem* problem, std::vector<int> initialItems);
    Problem& problem;

    int prize;
    int availableCapacity;
    std::vector<bool> itemInBackpack;
    std::vector<Neighbor>& neighbors;

    std::vector<Neighbor>& getNeighbors();
    void step(int neighborId);

private:
    int prizeChangeAdding(int itemId);
    int prizeChangeRemoving(int itemId);
};

#endif // SOLUTION_H
