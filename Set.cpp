/// @file Set.cpp
/// @author Sujin Lee
/// @date 2/4/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief source file for assignment pa11
/// @note 9hr
#include "Bag.h"
#include "Bag.h"  // include guard
#include "Set.h"
#include "Set.h"  // include guard

#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

/// Inserts an item into the bag.
/// Internally, the items are not maintained in any particular order.
/// @pre size() < CAPACITY
/// @param value Element value to insert.
void Set::insert(const value_type& value) {
    assert(size() < CAPACITY);
    if (count(value) == static_cast<size_type>(0)) {
        Bag::insert(value);
    }
}
