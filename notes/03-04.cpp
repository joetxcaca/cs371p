// -----------
// Fri,  4 Mar
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
arrays

first significant OO design choice by C++ which is to encapsulate built-in arrays with
user-defined array types
	array<T>,  for arrays on the stack
	vector<T>, for arrays on the heap
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

bool equal (const int* b1, const int* e1, const int* b2) {
	// b1, e1, and b2 are all read-only, many-location pointers
	while (b1 != e1) {
		if (*b1 != *b2)
			return false;
		++b1;
		++b2;}
	return true;}

template <typename T>
bool equal (const T* b1, const T* e1, const T* b2) {
	// b1, e1, and b2 are all read-only, many-location pointers
	while (b1 != e1) {
		if (*b1 != *b2)
			return false;
		++b1;
		++b2;}
	return true;}

/*
what are the requirements on T1 and T2
	T1 != T2 better work
*/

template <typename T1, typename T2>
bool equal (const T1* b1, const T1* e1, const T2* b2) {
	// b1, e1, and b2 are all read-only, many-location pointers
	// b1 is inclusive
	// e1 is exclusive
	while (b1 != e1) {
		if (*b1 != *b2)
			return false;
		++b1;
		++b2;}
	return true;}

template <typename T1, typename T2>
bool equal (T1 b1, T1 e1, T2 b2) {
	// b1, e1, and b2 are all read-only, many-location pointers
	// b1 is inclusive
	// e1 is exclusive
	while (b1 != e1) {
		if (*b1 != *b2)
			return false;
		++b1;
		++b2;}
	return true;}


template <typename T>
class list {
	...
	class iterator {
		...};
	...};

int  a[] = {2, 3, 4};        // type of a is: int* const, read-write, one-location pointer
long b[] = {2, 3, 4};
assert(equal(a, a + 3, b)); // T1 -> int*, T2 -> long*

#include <list> # list

list<int>           x  = {2, 3, 4}; // like Java's LinkedList, doubly linked list
list<int>::iterator b1 = begin(x);  // x.begin() an iterator to the first element
list<int>::iterator e1 = end(x);    // x.end()   an iterator to one PAST the last element

list<long>           y  = {2, 3, 4};
list<long>::iterator b2 = begin(y);

cout << *b; // 2
++b;
cout << *b; // 3

cout << equal(b1, e1, b2); // T1 -> list<int>::iterator, T2 -> list<long>::iterator

/*
why don't containers directly respond to next
rather, we must obtain an iterator and call next on that
*/

cout << equal(a + 5, a + 10, b + 15);

/*
what is the smallest that a could be? 10
what is the smallest that b could be? 20
*/

void test5 () {
    int a[] = {2, 3, 4};        // type of a is: int* const, read-write, one-location pointer
    long b[] = {2, 3, 4};
    assert(a != b);             // pointer comparison
    assert(equal(a, a + 3, b));
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}
