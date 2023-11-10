#include "Solution.h"

Solution::Solution(Problem* problem, std::vector<int> initialItems) {
    Problem* problem = problem;
    int availableCapacity = (*problem).capacity;
    int prize = 0;

    std::vector<Item> items = std::vector<Item>(0);
    std::map<int, int> itemsInBackpack = std::map<int, int>();
    std::vector<Neighbor>& neighbors;
    
    for (int itemId : initialItems) {
        this.add(itemId);
    }
}

const std::vector<Neighbor>& Solution::getNeighbors() {
    if (this.neighbors != nullptr) { // neighbors already calculated
        return const this.neighbors;
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