// -----------
// Mon, 28 Feb
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
please track your grades
please be responsive on Canvas
*/

/*
Paper #6: Open-Closed Principle
remember to go to Perusall THROUGH Canvas

this is the first of a 5-paper series
SOLID design
*/

/*
Project #2: Voting
	1. write code to only handle the I/O
	2. use a single bucket (vector of vector)
	3. use a bucket per candidate
	4. can NOT use new/delete, use the STL (e.g., vector, list, etc.)
Canvas poll
crowd source checktestdata schema
best to remove make run-all from .gitlab-ci.yml, until you're really done
if you're working with a partner, you MUST join a Canvas group BEFORE you submit
*/

void f (...) {
	...
	if (...)
		throw Tiger(...) // this must be on the stack, it MUST be copied
	...}

void g (...) {
	...
	try {
		...
		f(...);
		...}
	catch (Mammal e) { // catch by value, ANOTHER copy, we also potentially lose data
		...}

/*
never catch by value
*/

void f (int i) {
	...}

int j = 3;
f(j);



void f (...) {
	...
	if (...)
		Tiger t(...); // this must be on the stack
		throw &t;
	...}

void g (...) {
	...
	try {
		...
		f(...);
		...}
	catch (Mammal* e) { // catch by address, BAD address
		...}

/*
never catch by value
*/

void f (int i) {
	...}

void f (...) {
	...
	if (...)
		throw new Tiger(...); // this must be on the heap
	...}

void g (...) {
	...
	try {
		...
		f(...);
		...}
	catch (Mammal* e) { // catch by address, now WE are responsible for delete
		...}

/*
never catch by value
never catch by address
*/



void f (int i) {
	...}

void f (...) {
	...
	if (...)
		throw Tiger(...); // this must be on the stack, copied
	...}

void g (...) {
	...
	try {
		...
		f(...);
		...}
	catch (Mammal& e) { // catch by reference, NO second copy, access to all of the data
		...}

/*
never catch by value
never catch by address
always catch by reference
*/

// ----------
// Consts.cpp
// ----------

// https://www.cplusplus.com/doc/tutorial/constants/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void test1 () {
    int i = 2;
    ++i;
    assert(i == 3);}

void test2 () {
//  const int ci;     // error: uninitialized const 'ci'
    const int ci = 4;
//  ++ci;             // error: increment of read-only variable 'ci'
    assert(ci == 4);}

void test3 () {
    // read/write, many-location pointer
    // mutable int, mutable pointer
          int i  = 2;
    const int ci = 3;
    int*      p;
    p = &i;
    ++*p;
    assert(i == 3);
//  p = &ci;        // error: invalid conversion from 'const int*' to 'int*'
    assert(ci);}

void test4 () {
    // read-only, many-location pointer
    // immutable int, mutable pointer
          int  i  = 2;
    const int  ci = 3;
    const int* pc;
    pc = &ci;
//  ++*pc;                         // error: increment of read-only location
//  int* p = pc;                   // error: invalid conversion from 'const int*' to 'int*'
    int* p = const_cast<int*>(pc); // this does NOT change pc
    assert(p == pc);
//  ++*p;                          // undefined
    pc = &i;                       // ?
    p = const_cast<int*>(pc);
    ++*p;
    assert(i == 3);}

void f (const int* p) { // this is EVIL
	int* r = const_cast<int*>(p);
	++*r;} // this WILL change int i!!!

int i = 2;
const int* q = &i;
f(q);

/*
C casts with ()
C++ casts with
	const_cast
	static_cast
	dynamic_cast
	reinterpret_cast
*/



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

int main () {
    cout << "Consts.cpp" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    cout << "Done." << endl;
    return 0;}











/*
catch by reference
consts
arrays
*/
























