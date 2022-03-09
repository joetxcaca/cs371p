// ------------
// ReverseT.cpp
// ------------

// http://en.cppreference.com/w/cpp/algorithm/reverse

#include <algorithm>  // equal, swap, reverse
#include <functional> // function
#include <list>       // list

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename BI>
void my_reverse (BI b, BI e) {
    while ((b != e) && (b != --e)) {
        swap(*b, *e);
        ++b;}}




using ReverseArraySignature = function<void (int*, int*)>;

struct ReverseArrayFixture : TestWithParam<ReverseArraySignature>
    {};

INSTANTIATE_TEST_SUITE_P(
    ReverseArrayInstantiation,
    ReverseArrayFixture,
    Values(
           reverse<int*>,
        my_reverse<int*>));

TEST_P(ReverseArrayFixture, test0) {
    {
    int a[] = {2, 3, 4};
    GetParam()(a, a);
    ASSERT_TRUE(equal(a, a + 3, begin({2, 3, 4})));
    }}

TEST_P(ReverseArrayFixture, test1) {
    {
    int a[] = {2, 3, 4};
    GetParam()(a, a + 1);
    ASSERT_TRUE(equal(a, a + 3, begin({2, 3, 4})));
    }}



using ReverseListSignature = function<void (list<int>::iterator, list<int>::iterator)>;

struct ReverseListFixture : TestWithParam<ReverseListSignature>
    {};

INSTANTIATE_TEST_SUITE_P(
    ReverseListInstantiation,
    ReverseListFixture,
    Values(
           reverse<list<int>::iterator>,
        my_reverse<list<int>::iterator>));

TEST_P(ReverseListFixture, test2) {
    list<int>           x = {2, 3, 4};
    list<int>::iterator e = begin(x);
    ++++e;
    GetParam()(begin(x), e);
    ASSERT_TRUE(equal(begin(x), end(x), begin({3, 2, 4})));}

TEST_P(ReverseListFixture, test3) {
    list<int> x = {2, 3, 4};
    GetParam()(begin(x), end(x));
    ASSERT_TRUE(equal(begin(x), end(x), begin({4, 3, 2})));}
