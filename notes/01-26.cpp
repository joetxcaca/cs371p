// -----------
// Wed, 26 Jan
// -----------

/*
Class Modality
	first two weeks on Zoom, you're welcome to go to physical room (JGB 2.218)

Cold Calling
	you're only called ONCE per rotation
	it's totally fine to not know the answer, the idea is to discuss and to learn

Lectures
	MWF 1 pm

Help Sessions
	W 6-8 pm

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
*/

cout << "hi" << 2 << 3.4 << endl;

(cout << "hi") << 2
(cout << 2) << 3.4

// sample input

1 10
100 200
201 210
900 1000

// sample output

1 10 20
100 200 125
201 210 89
900 1000 174

/*
read a pair of ints
compute an answer
print the original pair and the answer

compute the cycle length on all of the numbers in the range specified by the pair
compute the max cycle length
*/

/*
read, eval, print (REPL)
*/

// sample output (alternative)

4
1 10 20
100 200 125
201 210 89
900 1000 174

// sample output (alternative)

1 10 20
100 200 125
201 210 89
900 1000 174
<sentinel>

/*
three styles of describing input
	1. just the input, expecting read to eventually fail
	2. specify the number of test cases beforehand
	3. use a sentinel at the end
*/

/*
the skeleton has three parts
	1. Collatz.hpp / Collatz.cpp; the kernel, where the computation happens
	2. TestCollatz.cpp;           test harness, which will use Google Test, a unit test framework
	3. RunCollatz.cpp;            run harness, which will the program they way HackerRank wants
*/

/*
you need to MERGE Collatz.cpp and RunCollatz.cpp -> MyHackerRank.cpp
*/

// ---------------
// TestCollatz.cpp
// ---------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Collatz.hpp" // the kernel

using namespace std;

// ----------------
// max_cycle_length
// ----------------

TEST(CollatzFixture, max_cycle_length_0) {
    ASSERT_EQ(max_cycle_length(1, 10), 20u);}

TEST(CollatzFixture, max_cycle_length_1) {
    ASSERT_EQ(max_cycle_length(100, 200), 125u);}

TEST(CollatzFixture, max_cycle_length_2) {
    ASSERT_EQ(max_cycle_length(201, 210), 89u);}

TEST(CollatzFixture, max_cycle_length_3) {
    ASSERT_EQ(max_cycle_length(900, 1000), 174u);}

// --------------
// RunCollatz.cpp
// --------------

// --------
// includes
// --------

#include <iostream> // cin, cout, endl
#include <sstream>  // istringstream
#include <string>   // getline, string

#include "Collatz.hpp" // the kernel, max_cycle_length

using namespace std;

// ----
// main
// ----

int main () {
    string s;
    while (getline(cin, s)) { // what is getline() return type? istream, cin
    					 	  // there must be a conversion from istream -> bool
        // ----
        // read
        // ----

        istringstream iss(s); // istringstream acts like, both, an istream and a string
        unsigned i, j;
        iss >> i >> j;        // iss is acting like an istream

        // ----
        // eval
        // ----

        unsigned v = max_cycle_length(i, j);

        // -----
        // print
        // -----
        cout << i << " " << j << " " << v << endl;}

    return 0;}


// -----------
// Collatz.cpp
// -----------

// --------
// includes
// --------

#include <cassert> // assert

#include "Collatz.hpp"

using namespace std;

// ----------------
// max_cycle_length
// ----------------

unsigned max_cycle_length (unsigned i, unsigned j) {
    assert(i > 0);
    assert(j > 0);

    // <your code>
    unsigned v = i + j; // replace!

    assert(v > 0);
    return v;}
