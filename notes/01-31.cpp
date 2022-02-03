// -----------
// Mon, 31 Jan
// -----------

/*
Class Modality
	online until further notice

Cold Calling
	you're only called ONCE per rotation
	it's totally fine to not know the answer, the idea is to discuss and to learn

Lectures
	MWF 1 pm

Help Sessions
	W 5-7 pm

Office Hours
	Glenn Downing
		Th 3-4 pm, Zoom

	Philo Lin (undergrad, '23)
		M 2-3 pm, Zoom

	Serdjan Rolovic (grad, '22)
		Th 2-3 pm, Zoom

Canvas
	personal questions
	please message all 3 of us

Ed Discussion (EdStem), replaces Piazza
	class questions
	ask and answer questions
	please be proactive

GitLab, like GitHub, do a git clone, later git pull, on	 a regular basis
	notes
	examples
	exercises

HackerRank, competitive programming platform
	exercises

Perusall, collaborative annotation tool (you must go through the Canvas assignment)
	annotate a series of papers
	the first one will be the syllabus

Zoom
	5.9.3
	must use UT EID credentials (@eid.utexas.edu)
	classes recorded
	published later that day

Specifications Grading
	please ask about this if you don't undestand it
	please use the Google Sheet that we're providing to track your grades

Website
	https://www.cs.utexas.edu/users/downing/cs371p/Schedule.html

Discord
	https://discord.gg/Qd3DVQZG

Grades Tracker Google Sheet
	https://docs.google.com/spreadsheets/d/1nt_FXi5vYuZlsxTPnanItjcivtZy8Gu4AADpPsdBWhM/

Virtual Token Google Form
	https://forms.gle/yoiKV2Vw1cSWbxBQ7
*/

/*
cold calling
specifications grading
very much a C++ class
*/

/*
Paper #02: Makefile
remember to go to Perusall THROUGH Canvas
*/

/*
Project #1: Collatz
Poll: Project #1: Collatz
Academic Integrity Quiz
*/

/*
lazy cache
	on HackerRank, caching when we read
eager cache
	on HackerRank, caching before the first read
meta cache
	NOT on HackerRank, caching hardwired values in the source file, < 50k
*/

/*
what if we cached max cycle lengths
what if we cached max cycle length for particular ranges

1-1000
1001-2000
2001-3000
...
999001-1000000
*/

/*
mcl(2500, 4500)
lookup
	3001-4000
compute
	2500-3000
	4001-4500
*/

/*
I want a range size that results in the most ranges than can fit in 50k
*/

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
% g++-11 -pedantic -std=c++17 -O3 -Wall UnitTests1.cpp -o UnitTests1 -lgtest -lgtest_main -pthread



% ./UnitTests1
Running main() from /usr/local/src/googletest-master/googletest/src/gtest_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test0
Assertion failed: (c > 0), function cycle_length, file UnitTests1.cpp, line 22.
*/






// --------------
// UnitTests2.cpp
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

TEST(UnitTestsFixture, test0) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(UnitTestsFixture, test1) {
    ASSERT_EQ(cycle_length( 5), 5);}

TEST(UnitTestsFixture, test2) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% ./UnitTests2
Running main() from /usr/local/src/googletest-master/googletest/src/gtest_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test0
[       OK ] UnitTestsFixture.test0 (0 ms)
[ RUN      ] UnitTestsFixture.test1
UnitTests2.cpp:29: Failure
Expected equality of these values:
  cycle_length( 5)
    Which is: 6
  5
[  FAILED  ] UnitTestsFixture.test1 (0 ms)
[ RUN      ] UnitTestsFixture.test2
[       OK ] UnitTestsFixture.test2 (0 ms)
[----------] 3 tests from UnitTestsFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 2 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] UnitTestsFixture.test1

 1 FAILED TEST
*/




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
Running main() from /usr/local/src/googletest-master/googletest/src/gtest_main.cc
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
% g++-11 --coverage -pedantic -std=c++17 -O3 -Wall Coverage1.cpp -o Coverage1 -lgtest -lgtest_main -pthread



% ./Coverage1
Running main() from /usr/local/src/googletest-master/googletest/src/gtest_main.cc
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
-rw-r--r--@ 1 downing  staff   1502 Sep  4 14:44 Coverage1.cpp
-rw-r--r--@ 1 downing  staff   3011 Sep  4 14:43 Coverage1.cpp.gcov
drwxr-xr-x@ 3 downing  staff     96 Sep  4 14:43 Coverage1.dSYM
-rw-r--r--@ 1 downing  staff   3712 Sep  4 14:43 Coverage1.gcda
-rw-r--r--@ 1 downing  staff  54816 Sep  4 14:43 Coverage1.gcno



% gcov-11 Coverage1.cpp | grep -B 2 "cpp.gcov"
File 'Coverage1.cpp'
Lines executed:66.67% of 12
Creating 'Coverage1.cpp.gcov'
*/



// -------------
// Coverage2.cpp
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
    ASSERT_EQ(cycle_length(2), 2);}

/*
% ./Coverage2
Running main() from /usr/local/src/googletest-master/googletest/src/gtest_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.



% gcov-11 Coverage2.cpp | grep -B 2 "cpp.gcov"
File 'Coverage2.cpp'
Lines executed:91.67% of 12
Creating 'Coverage2.cpp.gcov'
*/


// -------------
// Coverage3.cpp
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
    ASSERT_EQ(cycle_length(3), 8);}

/*
% ./Coverage3
Running main() from /usr/local/src/googletest-master/googletest/src/gtest_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.



% gcov-11 -b Coverage3.cpp | grep -B 2 "cpp.gcov"
File 'Coverage3.cpp'
Lines executed:100.00% of 12
Creating 'Coverage3.cpp.gcov'
*/
