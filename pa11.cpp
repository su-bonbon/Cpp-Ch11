/// @file pa11.cpp
/// @author Sujin Lee
/// @date 2/4/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Catch unot testing framework for Set and Bag classes
/// @note 9hr
#include "Bag.h"
#include "Bag.h"  // include guard
#include "Set.h"
#include "Set.h"  // include guard

#define CATCH_CONFIG_MAIN
#include <catch.hpp>  // include catch2 framework
#include <iostream>
#include <cassert>
#include <sstream>

using std::cout;


TEST_CASE("Bag::constructor") {
    const Bag bag;

    CHECK(bag.empty() == true);
    CHECK(bag.size() == 0);

}

TEST_CASE("Bag::size") {
    Bag bag;

    for (Bag::size_type i = 1; i <= Bag::CAPACITY; ++i) {
        bag.insert(static_cast<Bag::value_type>(i));
        CHECK(bag.size() == i);
    }

}

TEST_CASE("Bag::empty") {
    Bag bag;

    CHECK(bag.empty() == true);
    bag.insert(44);
    CHECK(bag.empty() == false);

}

TEST_CASE("Bag::insert") {
    Bag bag;

    for (Bag::size_type i = 1; i <= Bag::CAPACITY; ++i) {
        bag.insert(static_cast<Bag::value_type>(i));
        CHECK(bag.count(static_cast<Bag::value_type>(i)) == 1);
    }
}

TEST_CASE("Set::insert") {
    Bag bag;
    Set set;

    for (Set::size_type i = 1; i <= Set::CAPACITY; ++i) {
        set.insert(static_cast<Set::value_type>(i));
        CHECK(set.count(static_cast<Set::value_type>(i)) == 1);
    }  // full capacity

    set.erase_one(11);  // delete one item (randomly 11)

    set.insert(static_cast<Set::value_type>(1));  // insert existing num
    CHECK(set.count(static_cast<Set::value_type>(1)) == 1);

    CHECK(set.erase_one(1) == true);
    set.insert(static_cast<Set::value_type>(99));  // insert nonexisting num
    CHECK(set.count(99) == 1);

}

TEST_CASE("Bag::erase_one") {
    Bag bag;

    bag.insert(8);
    bag.insert(4);
    bag.insert(8);

    CHECK(bag.count(42) == 0);
    CHECK(bag.erase_one(42) == false);
    CHECK(bag.size() == 3);

    CHECK(bag.erase_one(8) == true);
    CHECK(bag.count(8) == 1);
    CHECK(bag.size() == 2);

    CHECK(bag.erase_one(4) == true);
    CHECK(bag.count(4) == 0);
    CHECK(bag.size() == 1);

    CHECK(bag.erase_one(8) == true);
    CHECK(bag.count(8) == 0);
    CHECK(bag.size() == 0);
}

TEST_CASE("BAG::clear") {
    Bag bag;

    bag.insert(8);
    bag.insert(4);
    bag.insert(8);

    CHECK(bag.empty() == false);
    CHECK(bag.size() == 3);

    bag.clear();

    CHECK(bag.empty() == true);
    CHECK(bag.size() == 0);

    cout << __FUNCTION__ << "passed\n";
}

TEST_CASE("Bag::count") {
    Bag bag;

    for (int i = 1; i <= 5; ++i){
        for(int j = 0; j < i; ++j){
            bag.insert(i);
        }
        CHECK(bag.count(i) == static_cast<Bag::size_type>(i));
    }
}

TEST_CASE("Bag::write") {
    std::ostringstream output;

    Bag bag;

    bag.write(output);
    CHECK(output.str() == "{}");

    output.str("");

    bag.insert(8);
    bag.insert(4);
    bag.insert(8);

    bag.write(output);
    CHECK(output.str() == "{8,4,8}");
}
