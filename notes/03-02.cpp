// -----------
// Wed,  2 Mar
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
consts
arrays
*/

void test4 () {
    // read-only, many-location pointer
    // immutable int, mutable pointer
          int  i  = 2;
    const int  ci = 3;
    const int* pc;
    pc = &ci;
//  ++*pc;                         // error: increment of read-only location
//  int* p = pc;                   // error: invalid conversion from 'const int*' to 'int*'
    int* p = const_cast<int*>(pc);
    assert(p == pc);
//  ++*p;                          // undefined
    pc = &i;                       // ?
    p = const_cast<int*>(pc);
    ++*p;
    assert(i == 3);}

void test5 () {
    // read/write, one-location pointer
    // mutable int, immutable pointer
          int  i  = 2;
    const int  ci = 3;
//  int* const cp;       // error: uninitialized const 'cp'
//  int* const cp = &ci; // error: invalid conversion from 'const int*' to 'int*'
    int* const cp = &i;
//  ++cp;                // error: cannot assign to variable 'cp' with const-qualified type 'int *const'
    ++*cp;
    assert(i == 3);
    assert(ci);}

void test6 () {
    // read-only, one-location pointer
    // immutable int, immutable pointer
          int        i   = 2;
    const int        ci  = 3;
//  const int* const cpc;       // error: uninitialized const 'cpc'
    const int* const cpc = &ci;
    const int* const cqc = &i;
//  ++cqc;                      // error: cannot assign to variable 'cqc' with const-qualified type 'const int *const'
//  ++*cqc;                     // error: increment of read-only location
    assert(cpc);
    assert(cqc);}

void test7 () {
    // read/write reference
    // mutable int
          int i  = 2;
    const int ci = 3;
//  int&      r;      // error: 'r' declared as reference but not initialized
//  int&      r = ci; // error: invalid initialization of reference of type 'int&' from expression of type 'const int'
    int&      r = i;
    ++r;
    assert(i == 3);
    assert(ci);}

void test8 () {
    // read-only reference
    // immutable int
          int  i  = 2;
    const int  ci = 3;
//  const int& rc;      // error: 'rc' declared as reference but not initialized
    const int& rc = ci;
    const int& sc = i;
//  ++sc;               // error: increment of read-only reference 'sc'
    assert(rc);
    assert(sc);}

const int  i  = 2;
const int* pc = &i;
++*pc;              // no

int* q = const_cast<int*>(pc);
++*q;               // this compiles, undefined at run time


int        i  = 2;
const int* pc = &i;
++*pc;              // no

int* q = const_cast<int*>(pc);
++*q;               // fine




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

void test1 () {
    int a[] = {2, 3, 4}; // arrays are like pointers, pointers are like arrays, int* const
    assert(*a == a[0]);
    assert(a  == &a[0]);
    assert(sizeof(a)     != sizeof(&a[0]));
    assert(sizeof(a)     == 12);
    assert(sizeof(&a[0]) == 8);
//  ++a;                                    // error: lvalue required as left operand of assignment
    ++a[1];
    ++*(a + 1);
    assert(a[1]     == 5);
    assert(*(a + 1) == 5);
//  assert(a[3]     == 0);                  // undefined
//  assert(*(a + 3) == 0);                  // undefined
    }

class A {
	int i;}

{
A x; // A(), zero-arg, default constructor, leave int i uninitialized

// y better NO exist
A y(x); // A(A), one-arg, copy constructor, copy int i

// y MUST exist
y = x; // =(A), copy assignment operator, copy int i
}

// ~A(), destructor





A x;          // an A object on the stack

A* p = new A; // an A object on the heap





void test2 () {
    const size_t s    = 10;
    const int    a[s] = {2, 3, 4}; // what are the other values? 0
    assert(sizeof(a) == 40);       // 10 * 4 = 40
    assert(a[1]      ==  3);
    assert(*(a + 1)  ==  3);
    assert(a[s - 1]  ==  0);
//  ++a;                           // error: lvalue required as left operand of assignment
//  ++a[1];                        // error: increment of read-only location
    }

T a[10] = {2, 3, 4};
/*
for T, a builtin type:
2, 3, 4, 0, 0, 0, 0, 0, 0, 0

for T, a user-defined type:
T(int), 3 times
T(),    7 times
*/





void test3 () {
    const size_t s = 10;
//  const int    a[s];       // error: uninitialized const 'a'
    int a[s];                // what are the values? NOT 0!!!!
    assert(sizeof(a) == 40);
//  assert(a[0]      ==  0); // undefined
    }

T a[10];
/*
for T, a builtin type:
undefined

for T, a user-defined type:
T(), 10 times
*/





void test4 () {
    const size_t s    = 10;
    const int    a[s] = {}; // ALL 0s
    assert(sizeof(a) == 40);
    assert(a[0]      ==  0);}

T a[10] = {};
/*
for T, a builtin type:
0, 0, 0, 0, 0, 0, 0, 0, 0, 0

for T, a user-defined type:
T(), 10 times
*/
