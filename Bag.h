/// @file Bag.h
/// @author Sujin Lee
/// @date 1/30/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Header file for Bag.cpp
/// @note 40hr
#ifndef BAG_H
#define BAG_H

#include <cassert>
#include <iostream>

/// A Bag is a general-purpose container that stores a set of possibly
/// non-unique values of type int. Internally, the items are not maintained
/// in any particular order.

class Bag {
public:
    using value_type = int;
    using size_type  = std::size_t;

    static const size_type CAPACITY = 20;  ///< Maximum storage capacity.

    /// Constructs the Bag.
    Bag() { used = 0;}

    /// Returns the number of items in the bag.
    /// @returns The number of items in the bag.
    size_type size() const { return used; }

    /// Checks if the bag has no items, ie whether size() == 0
    /// @returns true if the bag has no items, false otherwise.
    bool empty() const { return size() == 0; }

    /// Inserts an item into the bag.
    /// Internally, the items are not maintained in any particular order.
    /// @pre size() < CAPACITY
    /// @param value Element value to insert.
    void insert(const value_type& value);

    /// If target was in the bag, then one copy has been removed;
    /// otherwise the bag is unchanged.
    /// Internally, the items are not maintained in any particular order.
    /// @param target Key value of the items to remove.
    /// @return true if one copy was removed; false if nothing removed.
    bool erase_one(const value_type& target);

    /// After this call, size() returns zero.
    void clear() { used = 0; }

    /// Returns the number of items equal to the target.
    /// @param target Key value of the item(ues) to count.
    /// @returns Number of items with value equal to the target.
    size_type count(const value_type& target) const;

    /// Writes all items to an output stream in the format: {42,73,0,-59,7}
    /// @param output The output stream (defaults to std::cout).
    void write(std::ostream& output) const;

private:
    size_type  used;            ///< Number of items in Bag.
    value_type data[CAPACITY];  ///< Array of items.
};

#endif  /* BAG_H */
/*
///documentation for a function
/// @brief The function foo.
///
/// Description of what the function does. This part may refer to the
/// parameters of the function, like @p param1 or @p param2.
///
/// @pre Pre-conditions
/// @post Post-conditions
///
/// @param param1 Description of the first parameter of the function.
/// @param param2 The second parameter, which follows @p param1.
/// @return Describe what the function returns.
///
/// @see http://website/
/// @note Something to note.
/// @warning Warning.
*/
