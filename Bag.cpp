/// @file Bag.cpp
/// @author Sujin Lee
/// @date 1/30/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief cpp file for assignment #1
/// @note 40hr
#include <iostream>
#include "Bag.h"
using namespace std;

/// Inserts an item into the bag.
/// Internally, the items are not maintained in any particular order.
/// @pre size() < CAPACITY
/// @param value Element value to insert.
void Bag::insert(const value_type& value) {
    assert(size() < CAPACITY);
    data[used++] = value;
}

/// If target was in the bag, then one copy has been removed;
/// otherwise the bag is unchanged.
/// Internally, the items are not maintained in any particular order.
/// @param target Key value of the items to remove.
/// @return true if one copy was removed; false if nothing removed.
bool Bag::erase_one(const Bag::value_type& target) {
    bool found = false;  // loop cintrol

    for (size_type i=0; !found && i < size(); ++i) {
        if (data[i] == target) {
            data[i] = data[--used];
            found = true;
        }
    }

    return found;
}

/// Returns the number of items equal to the target.
/// @param target Key value of the item(s) to count.
/// @returns Number of items with value equal to the target.
Bag::size_type Bag::count(const value_type& target) const {
    Bag::size_type counter = 0;

    for (size_type i = 0; i < size(); ++i) {
        if (data[i] == target) {
            ++counter;
        }
    }

    return counter;
}

/// Writes all items to an output stream in the format: {42,73,0,-59,7}
/// @param output The output stream (defaults to std::cout).
void Bag::write(std::ostream& output) const {
    char separator[2] = "";  // string ro print before each element

    output << '{';

    for (size_type i = 0; i < size(); ++i) {
        output << separator << data[i];
        separator[0] = ',';
    }
    output << '}';
}
