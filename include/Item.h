#ifndef ITEM_H
#define ITEM_H

#include <map>

struct Item {
    int prize;
    int weight;
    std::map<int, int> synergies;
};

#endif // ITEM_H
