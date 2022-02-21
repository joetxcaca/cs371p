// -----------
// Mon, 21 Feb
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
	https://forms.gle/yoiKV2Vw1cSWbxBQ7/
*/

/*
cold calling
specifications grading
very much a C++ class
*/

/*
Paper #5: Single Responsibility Principle
remember to go to Perusall THROUGH Canvas

this is the first of a 5-paper series
SOLID design
*/

/*
Project #2: Voting
	1. write code to only handle the I/O
	2. use a single bucket
	3. use a bucket per candidate
	4. can NOT use new/delete, use the STL (e.g., vector, list, etc.)
Canvas poll
crowd source checktestdata schema
best to remove make run-all from .gitlab-ci.yml, until you're really done
*/

/*
values
pointers
references
*/

void f (int v) { // pass by value, we're making a copy
	++v;}

int i = 2;
f(i);
cout << i; // 2



void g (int* p) { // pass by address, p is a pointer to j
	++p;}

int j = 3;
g(j);      // no
g(&j);
cout << j; // 3



void g (int* p) { // pass by address, p is a pointer to j
	++*p;
	int k = 4;
	p = &k;
	++*p;         // modifying k
	...}

int j = 3;
g(j);      // no
g(&j);
cout << j; // 4



void h (int& r) { // pass by reference, r IS k
	++*r;         // no
	++r;}

int k = 4;
h(&k);     // no
h(k);
cout << k; // 5



int  i = 2;
int* p = &i;
++*p;
cout << i; // 3
int k = 4;
p = &k;    // make p point other places

int  j = 3;
int& r = 5; // no, int& needs an l-value
int& r = j; // r becomes an alias for j
++r;
cout << j; // 4
// there is NO way to disconnect r from j
int m = 5;
r = m;     // changing j to have the value m



/*
three annotations
	1. the call
	2. the parameter
	3. the use
*/

void g (int* p) { // pass by address, p is a pointer to j
			      // paranoid that p might be 0 or the nullptr
	++*p;}

int j = 3;
g(&j);
cout << j;  // 4
g(0);       // runtime error
// the right way to do that
g(nullptr);


/*
one annotation
	1. the parameter
*/

void h (int& r) { // pass by reference, r IS k
	++r;}

int k = 4;
h(k);      // this call is a little more opaque
cout << k; // 5
h(0);      // no

/*
reasons for passing address:
	1. I want the pointer argument to take on various values
	2. I'm handing an array
*/

// -------------
// Arguments.cpp
// -------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void by_value (int v) { // making a copy
    ++v;}

void test1 () {
    const int i = 2;
    by_value(i);
    assert(i == 2);}



void by_address (int* p) {
    assert(p);
    ++*p;}

void test2 () {
    int j = 3;
    by_address(&j);
    assert(j == 4);
    const int cj = 5;
//  by_address(&cj);  // error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
//  by_address(185);  // error: invalid conversion from 'int' to 'int*' [-fpermissive]
//  by_address(0);    // Assertion failed: (p), function by_address, file Arguments.cpp, line 14.
    }



void by_reference (int& r) { // must be an l-value!!!
    ++r;}

void test3 () {
    int k = 4;
    by_reference(k);
    assert(k == 5);
    const int ck = 6;
//  by_reference(ck);  // error: binding reference of type 'int&' to 'const int' discards qualifiers
//  by_reference(185); // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
//  by_reference(0);   // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    }



int main () {
    cout << "Arguments.cpp" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}




// -----------
// Returns.cpp
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

int f () {          // return by value
    int i = 2;
    return i;}      // a copy i

void test1 () {
    int v = f();
    assert(v == 2);
//  int* p = &f();  // error: lvalue required as unary ‘&’ operand
//  int& r = f();   // error: invalid initialization of non-const reference of type ‘int&’ from a temporary of type ‘int’
    }



int* g () {          // return by address
    int j = 2;
    return &j;}      // warning: address of local variable 'j' returned

void test2 () {
//  int v = *g();    // Segmentation fault

    int* p = g();
//  assert(*p == 2); // Segmentation fault

    int& r = *g();
//  assert(r == 2);  // Segmentation fault
    }



int& h () {          // return by reference
    int k = 2;
    return k;}       // warning: reference to local variable 'k' returned

void test3 () {
//  int v = h();     // Segmentation fault

    int* p = &h();
//  assert(*p == 2); // Segmentation fault

    int& r = h();
//  assert(r == 2);  // Segmentation fault
    }

int main () {
    using namespace std;
    cout << "Returns.cpp" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}


/*
you need to be confident about
	1. values
	2. pointers
	3. references

in three contexts:
	1. top level
	2. arguments
	3. returns
*/

cout << "hi" << "badr";

// what exactly

cout << "hi"

// returning by reference
