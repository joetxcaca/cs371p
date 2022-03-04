// ----------
// EqualT.cpp
// ----------

// https://en.cppreference.com/w/cpp/algorithm/equal

#include <algorithm> // equal
#include <list>      // list
#include <vector>    // vector

#include "gtest/gtest.h"

using namespace std;

template <typename II1, typename II2>
bool my_equal (II1 b1, II1 e1, II2 b2) {
    while (b1 != e1) {
        if (*b1 != *b2)
            return false;
        ++b1;
        ++b2;}
    return true;}

TEST(EqualFixture, test0) {
    const int  a1[] = {2, 3, 4};
    const int  a2[] = {0, 2, 3, 4, 0};
    const int* b1   = begin(a1);
    const int* e1   = end(a1);
    const int* b2   = begin(a2);
    ASSERT_FALSE(   equal(b1, e1, b2));
    ASSERT_FALSE(my_equal(b1, e1, b2));}

TEST(EqualFixture, test1) {
    const int  a1[] = {2, 3, 4};
    const int  a2[] = {0, 2, 3, 4, 0};
    const int* b1   = begin(a1);
    const int* e1   = end(a1);
    const int* b2   = begin(a2) + 1;
    ASSERT_TRUE(   equal(b1, e1, b2));
    ASSERT_TRUE(my_equal(b1, e1, b2));}

TEST(EqualFixture, test2) {
    const list<int>             x1 = {2, 3, 4};
    const vector<int>           x2 = {0, 2, 3, 4, 0};
    list<int>::const_iterator   b1 = begin(x1);
    list<int>::const_iterator   e1 = end(x1);
    vector<int>::const_iterator b2 = begin(x2) + 1;
    ASSERT_TRUE(   equal(b1, e1, b2));
    ASSERT_TRUE(my_equal(b1, e1, b2));}
