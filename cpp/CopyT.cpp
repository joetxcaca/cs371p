// ---------
// CopyT.cpp
// ---------

// https://en.cppreference.com/w/cpp/algorithm/copy

#include <algorithm>  // copy, equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II, typename OI>
OI my_copy (II b1, II e1, OI b2) {
    while (b1 != e1) {
        *b2 = *b1;
        ++b1;
        ++b2;}
    return b2;}



using CopyArraySignature = function<int* (const int*, const int*, int*)>;

struct CopyArrayFixture : TestWithParam<CopyArraySignature>
    {};

INSTANTIATE_TEST_SUITE_P(
    CopyArrayInstantiation,
    CopyArrayFixture,
    Values(
           copy<const int*, int*>,
        my_copy<const int*, int*>));

TEST_P(CopyArrayFixture, test0) {
    const int  a1[]  = {2, 3, 4};
    int        a2[5] = {};
    const int* b1    = begin(a1);
    const int* e1    = end(a1);
    int*       b2    = begin(a2) + 1;
    int*       e2    = GetParam()(b1, e1, b2);
    ASSERT_EQ(e2, begin(a2) + 4);
    ASSERT_TRUE(equal(begin(a2), end(a2), begin({0, 2, 3, 4, 0})));}



using CopyListSignature = function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator)>;

struct CopyListFixture : TestWithParam<CopyListSignature>
    {};

INSTANTIATE_TEST_SUITE_P(
    CopyListInstantiation,
    CopyListFixture,
    Values(
           copy<list<int>::const_iterator, vector<int>::iterator>,
        my_copy<list<int>::const_iterator, vector<int>::iterator>));

TEST_P(CopyListFixture, test1) {
    const list<int>           x1 = {2, 3, 4};
    vector<int>               x2(5);
    list<int>::const_iterator b1 = begin(x1);
    list<int>::const_iterator e1 = end(x1);
    vector<int>::iterator     b2 = begin(x2) + 1;
    vector<int>::iterator     e2 = GetParam()(b1, e1, b2);
    ASSERT_EQ(e2, begin(x2) + 4);
    ASSERT_TRUE(equal(begin(x2), end(x2), begin({0, 2, 3, 4, 0})));}
