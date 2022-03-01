// --------------
// UnitTests3.cpp
// --------------

// https://github.com/google/googletest
// https://github.com/google/googletest/blob/master/docs/reference/assertions.md

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(UnitTestsFixture, test1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(UnitTestsFixture, test2) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST(UnitTestsFixture, test3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% ./UnitTests3
Running main() from /tmp/googletest-20210612-68642-1k2ka09/googletest-release-1.11.0/googletest/src/gtest_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test1
[       OK ] UnitTestsFixture.test1 (0 ms)
[ RUN      ] UnitTestsFixture.test2
[       OK ] UnitTestsFixture.test2 (0 ms)
[ RUN      ] UnitTestsFixture.test3
[       OK ] UnitTestsFixture.test3 (0 ms)
[----------] 3 tests from UnitTestsFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.
*/
