// -----------
// Fri, 11 Feb
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
Paper #4: 2022-02-13: Pair Programming
remember to go to Perusall THROUGH Canvas
*/

/*
first competitive programming contest
Fri, 11 Feb, 5:30 - 8 pm CT
Zoom or GDC auditorium
free food!
*/

/*
two tokens:   *, &
two contexts: next to a variable, next to a type
*/

int i = 2;
int j = i; // making a copy
++i;
cout << j; // 2

int* p = i;  // no
int* p = &i; // & takes the address
++p;         // legal to point to a crazy place
cout << *p;  // * dereferences a pointer
cout << *i;  // no

int* q = &i;
++*q;        // dereferences and increments

// -----------
// StrCmpH.cpp
// -----------

// https://en.cppreference.com/w/c/string/byte/strcmp
// https://gcc.gnu.org/onlinedocs/gcc-10.2.0/libstdc++/api/a00332_source.html

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

#define TEST0
#define TEST1
#define TEST2
#define TEST3
#define TEST4
#define TEST5

#ifdef TEST0
void test0 () {
    assert(my_strcmp("",    "")    == 0);}
#endif

int my_strcmp (const char* s, const char* t) {
	...}

/*
turn on your video
collaborate on solving
ONE person volunteers to drive, share their screen
ask for help or when you're done before you submit
*/

5182

#ifdef TEST1
void test1 () {
    assert(my_strcmp("abc", "abc") == 0);}
#endif

#ifdef TEST2
void test2 () {
    assert(my_strcmp("abc", "ab")  >  0);}
#endif

#ifdef TEST3
void test3 () {
    assert(my_strcmp("abc", "aba") >  0);}
#endif

#ifdef TEST4
void test4 () {
    assert(my_strcmp("ab",  "abc") <  0);}
#endif

#ifdef TEST5
void test5 () {
    assert(my_strcmp("aba", "abc") <  0);}
#endif
