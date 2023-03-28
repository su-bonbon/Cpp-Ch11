/// @file Set.h
/// @author Sujin Lee
/// @date 2/4/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Header file for Set.cpp
/// @note 9hr
#ifndef SET_H
#define SET_H

#include <cassert>
#include <iostream>
#include "Bag.h"

class Set: public Bag{
public:

    /// Inserts an item into the bag if it doesn't exist in the bag.
    /// Internally, the items are not maintained in any particular order.
    /// @pre size() < CAPACITY
    /// @param value Element value to insert.
    void insert(const value_type& value);
};
#endif  /* BAG_H */
