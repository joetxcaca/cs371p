// -----------
// Mon,  7 Mar
// -----------

/*
Class
	MWF 1-2 pm CT

Website
	https://www.cs.utexas.edu/users/downing/cs371p/Schedule.html

Help Sessions
	W 5-7 pm

Office Hours
	Glenn Downing
		Th 3-4 pm, Zoom

	Philo Lin (undergrad, '23)
		M 2-3 pm, Zoom

	Serdjan Rolovic (grad, '22)
		Th 2-3 pm, Zoom

Cold Calling
	you're only called ONCE per rotation
	it's totally fine to not know the answer, the idea is to discuss and to learn

Notes
	these notes will be posted on GitLab

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
	5.9.6
	must use UT EID credentials (@eid.utexas.edu)
	classes recorded
	published later that day

Specifications Grading
	please ask about this if you don't undestand it
	please use the Google Sheet that we're providing to track your grades

Discord
	https://discord.gg/Qd3DVQZG

Grades Tracker Google Sheet
	https://docs.google.com/spreadsheets/d/1nt_FXi5vYuZlsxTPnanItjcivtZy8Gu4AADpPsdBWhM/

Virtual Token Google Form
	https://forms.gle/yoiKV2Vw1cSWbxBQ7/
*/

/*
cold calling
specifications grading
very much a C++ class
*/

/*
please track your grades
please be responsive on Canvas
*/

/*
Paper #7: Liskov Substitution Principle
remember to go to Perusall THROUGH Canvas

this is the third of a 5-paper series
SOLID design
*/

/*
Takeaways:

 1. assertions are not good for testing
 2. assertions are not good for user errors
 3. don't use equality on floating point
 4. prefer pre-increment
 5. always catch by reference
 6. built-in stack arrays are always passed by address
 7. built-in stack arrays are DO NOT know their size
 8. built-in stack arrays are NOT comparable
 9. built-in stack arrays are NOT copyable
10. built-in stack arrays are NOT assignable
11. std::array<> DOES know its size
12. std::array<> IS comparable
13. std::array<> IS copyable
14. std::array<> IS assignable
*/

/*
arrays
*/

template <typename II1, typename II2>
bool my_equal (II1 b1, II1 e1, II2 b2) {
    while (b1 != e1) {
        if (*b1 != *b2)
            return false;
        ++b1;
        ++b2;}
    return true;}

/*
input iterator (II)

!=, ==
*  (read only)
++
*/

// -----------
// Arrays1.cpp
// -----------

// https://en.cppreference.com/w/cpp/container/array

#include <cstdio>

#include <algorithm> // copy, equal
#include <array>     // array
#include <cassert>   // assert
#include <iostream>  // cout, endl

using namespace std;

int i = 2;
int j = i; // ints are copyable

// built-in stack array are NOT copyable
// built-in stack arrays do NOT know their size
// built-in stack arrays are NOT comparable

void test6 () {
    int a[] = {2, 3, 4};
//  int b[] = a;                    // error: initializer fails to determine size of 'b'
    int* b  = a;
    assert(a         == b);
    assert(sizeof(a) != sizeof(b));
    assert(sizeof(a) == 12);
    assert(sizeof(b) ==  8);
    ++b[1];
    assert(equal(a, a + 3, begin({2, 4, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

template <typename II, typename OI>
OI my_copy (II b1, II e1, OI b2) {
    while (b1 != e1) {
    	*b2 = *b1;
        ++b1;
        ++b2;}
    return b2;}

/*
output iterator (OI)

!=, ==
* (write only)
++
*/

void test7 () {
    int          a[] = {2, 3, 4};
    const size_t s   = sizeof(a) / sizeof(a[0]);
    int b[s];
    copy(a, a + s, b); // II -> int*; OI -> int*
    assert(a != b);
    assert(equal(a, a + s, b));
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

// built-in stack array are NOT assignable

void test8 () {
    int a[] = {2, 3, 4};
    int b[] = {5, 6, 7};
//  b = a;                                     // error: invalid array assignment
    const size_t s = sizeof(a) / sizeof(a[0]);
    copy(a, a + s, b);
    assert(a != b);
    assert(equal(a, a + s, b));
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

void f (int p[]) {          // NOT a copy of the array, but just another pointer to the array!!!
    assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

void test9 () {
    int a[] = {2, 3, 4};
    f(a);
    assert(equal(a, a + 3, begin({2, 5, 4})));}

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

void test10 () {
    int a[] = {2, 3, 4};
    g(a);
    assert(equal(a, a + 3, begin({2, 5, 4})));}

void test11 () {
    array<int, 3> x = {2, 3, 4};
    assert(x.size() == 3);       // std::array DOES know its size
    assert(x[1]     == 3);
    array<int, 3>  y(x);         // std::array IS copyable
    array<int, 4>  z(x);         // NO!!!!
    array<long, 3> t(x);         // NO!!!!
    assert( x    ==  y);         // std::array IS comparable
    assert(&x[1] != &y[1]);}

void test12 () {
    array<int, 3> x = {2, 3, 4};
    array<int, 3> y = {5, 6, 7};
    x = y;                       // std::array IS assignable
    assert( x    ==  y);
    assert(&x[1] != &y[1]);}

void m1 (int& r) // by reference

void h1 (array<int, 3>& y) {
    array<int, 3>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test13 () {
    array<int, 3> x = {2, 3, 4};
    h1(x);
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}

void m2 (int i) // by value

void h2 (array<int, 3> y) {
    array<int, 3>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test14 () {
    array<int, 3> x = {2, 3, 4};
    h2(x);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}
