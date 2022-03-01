// -------------
// Coverage1.cpp
// -------------

// https://gcc.gnu.org/onlinedocs/gcc/Gcov.html

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

TEST(CoverageFixture, test) {
    ASSERT_EQ(cycle_length(1), 1);}

/*
% clang++ --coverage -g -std=c++17 -Wall -Wextra -Wpedantic Coverage1.cpp -o Coverage1



% ./Coverage1
Running main() from /tmp/googletest-20210612-68642-1k2ka09/googletest-release-1.11.0/googletest/src/gtest_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.



% ls -al Coverage1.*
-rw-r--r--@ 1 downing  staff    1558 Sep  4 14:44 Coverage1.cpp
-rw-r--r--@ 1 downing  staff    2678 Mar  1 16:09 Coverage1.cpp.gcov
-rw-r--r--@ 1 downing  staff    8764 Mar  1 16:09 Coverage1.gcda
-rw-r--r--@ 1 downing  staff  131168 Mar  1 16:09 Coverage1.gcno


% llvm-cov gcov Coverage1.cpp | grep -B 2 "cpp.gcov"
File 'Coverage1.cpp'
Lines executed:66.67% of 12
Creating 'Coverage1.cpp.gcov'
*/
