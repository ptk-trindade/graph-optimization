#include "../include/Solution.h"
#include <stdexcept>
#include <iostream>

Solution::Solution(Problem* problem, std::vector<int> initialItems) : problem(*problem), neighbors(*new std::vector<Neighbor>())
 {
    this->problem = *problem;
    this->availableCapacity = problem->capacity;
    this->neighbors = *new std::vector<Neighbor>();
    prize = 0;
    int total_items = problem->items.size();

    itemInBackpack = std::vector<bool>(total_items);
    
    for (int itemId : initialItems) {
        if (itemId >= 0 && itemId < total_items) {
            availableCapacity -= problem->items[itemId].weight;
            prize += prizeChangeAdding(itemId);
            itemInBackpack[itemId] = true;
        } else {
            throw std::out_of_range("Invalid ID");
        }
    }
}



std::vector<Neighbor>& Solution::getNeighbors() {

    if (!neighbors.empty()) { // neighbors already calculated
        return neighbors;
    }
    
    for (int i = 0; i < int(itemInBackpack.size()); i++) {        
    // TODO - for each item in the backpack, prizeChangeRemoving
    // and for each item not in the backpack, prizeChangeAdding
    // fill vector this.neighbors (with possible steps)
    // and return a const reference to the vector

        
        if (itemInBackpack[i]) {
            int prizeChange = prizeChangeRemoving(i);
            if (prizeChange > 0) {
                Neighbor neighbor;
                neighbor.deltaPrize = prizeChange;
                neighbor.addedItems = std::vector<int>();
                neighbor.removedItems = std::vector<int>(1, i);
                neighbor.heuristic = float(prizeChange) / problem.items[i].weight;
                neighbors.push_back(neighbor);
            }
        } else {
            int prizeChange = prizeChangeAdding(i);
            if (prizeChange > 0 && problem.items[i].weight <= availableCapacity) {
                Neighbor neighbor;
                neighbor.deltaPrize = prizeChange;
                neighbor.addedItems = std::vector<int>(1, i);
                neighbor.removedItems = std::vector<int>();
                neighbor.heuristic = float(prizeChange) / problem.items[i].weight;
                neighbors.push_back(neighbor);
            }
        }
    }

    return neighbors;    
}

void Solution::step(int neighborId) {
    Neighbor neighbor = neighbors[neighborId];

    for (int itemId : neighbor.addedItems) {
        itemInBackpack[itemId] = true;
    }

    for (int itemId : neighbor.removedItems) {
        itemInBackpack[itemId] = false;
    }

    prize += neighbor.deltaPrize;
    neighbors = *new std::vector<Neighbor>();
}

void Solution::randomWalk(float randomness) {
    // TODO - Randomlly adds/removes items from the backpack
}


int Solution::prizeChangeAdding(int itemId) {
    int prizeDelta;
    prizeDelta = problem.items[itemId].prize;

    // synergy: id, synergy
    for (auto synergy : problem.items[itemId].synergies) {
        if (itemInBackpack[synergy.first]) {
            prizeDelta -= synergy.second;
        }
    }

    return prizeDelta;
}

void Solution::remove(int itemId) {
    // TODO
}

int Solution::prizeChangeRemoving(int itemId) {
    int prizeDelta;
    prizeDelta = -this->problem.items[itemId].prize;

    // synergy: id, synergy
    for (auto synergy : this->problem.items[itemId].synergies) {
        if (this->itemInBackpack[synergy.first]) {
            prizeDelta += synergy.second;
        }
    }

    return prizeDelta;
}