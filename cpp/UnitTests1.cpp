// --------------
// UnitTests1.cpp
// --------------

// https://github.com/google/googletest
// https://github.com/google/googletest/blob/master/docs/reference/assertions.md

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

int cycle_length (int n) {
    assert(n > 0);
    int c = 0;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(UnitTestsFixture, test0) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(UnitTestsFixture, test1) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST(UnitTestsFixture, test2) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% clang++ --coverage -g -std=c++17 -Wall -Wextra -Wpedantic UnitTests1.cpp -o UnitTests1



% ./UnitTests1
Running main() from /tmp/googletest-20210612-68642-1k2ka09/googletest-release-1.11.0/googletest/src/gtest_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test0
Assertion failed: (c > 0), function cycle_length, file UnitTests1.cpp, line 22.
*/
