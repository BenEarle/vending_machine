#ifndef ITEM_SELECTION_H
#define ITEM_SELECTION_H

#include <iostream>

struct item_selection_t {
    float price;
    int item_id;

    // Constructor
    item_selection_t(float p = 0.0, int id = 0) : price(p), item_id(id) {}

    // Overloading the ostream operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const item_selection_t& item) {
        os << "item_selection_t { item_id: " << item.item_id << ", price: " << item.price << " }";
        return os;
    }
};

#endif // ITEM_SELECTION_H
