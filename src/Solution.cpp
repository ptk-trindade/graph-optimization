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
                    
    for (int i = 0; i < items.size(); i++) {

        
    // TODO - for each item in the backpack, prizeChangeRemoving
    // and for each item not in the backpack, prizeChangeAdding
    // fill vector this.neighbors (with possible steps)
    // and return a const reference to the vector

        
        if (itemInBackpack[i]) {
            int prizeChange = prizeChangeRemoving(i);
            if (prizeChange > 0) {
                Neighbor neighbor;
                neighbor.prize = prizeChange;
                neighbor.addedItems = std::vector<int>();
                neighbor.removedItems = std::vector<int>(1, i);
                neighbors.push_back(neighbor);
            }
        } else {
            int prizeChange = prizeChangeAdding(i);
            if (prizeChange > 0) {
                Neighbor neighbor;
                neighbor.prize = prizeChange;
                neighbor.addedItems = std::vector<int>(1, i);
                neighbor.removedItems = std::vector<int>();
                neighbors.push_back(neighbor);
            }
        }
    }

    return neighbors;

    
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