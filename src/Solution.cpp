#include "Solution.h"

Solution::Solution(Problem* problem, std::vector<int> initialItems) {
    Problem* problem = problem;
    int availableCapacity = (*problem).capacity;
    int prize = 0;
    int total_items = (*problem).items.size();

    std::vector<bool> itemsInBackpack = std::vector<bool>(total_items);
    
    std::vector<Neighbor> *neighbors = &std::vector<Neighbor>(0);

    
    for (int itemId : initialItems) {
        if (itemId >= 0 && itemId < total_items) {
            itemsInBackpack[itemId] = true;
        } else {
            throw std::out_of_range("Invalid ID");
        }
    }
}



const std::vector<Neighbor>& Solution::getNeighbors() {

    if (!neighbors.empty()) { // neighbors already calculated
            return neighbors;
    }


    // TODO - for each item in the backpack, prizeChangeRemoving
    // and for each item not in the backpack, prizeChangeAdding
    // fill vector this.neighbors (with possible steps)
    // and return a const reference to the vector

    
}

void Solution::step(int neighborId) {
    // TODO - change current solution based on the given step
}

void Solution::randomWalk(float randomness) {
    // TODO - Randomlly adds/removes items from the backpack
}

// --- Private methods
void Solution::add(int itemId) {
    // TODO
}

int prizeChangeAdding(int itemId) {
    // TODO
}

void Solution::remove(int itemId) {
    // TODO
}

int prizeChangeRemoving(int itemId) {
    // TODO
}