// -----------
// Wed,  9 Feb
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
Paper #4: 2022-02-13: Pair Programming
remember to go to Perusall THROUGH Canvas
*/

/*
first competitive programming contest
Fri, 11 Feb, 5:30 - 8 pm CT
Zoom or GDC auditorium
free food!
*/

// --------------
// Exceptions.cpp
// --------------

// https://en.cppreference.com/w/cpp/language/exceptions

#include <cassert>   // assert
#include <cstring>   // strcmp
#include <iostream>  // cout, endl
#include <stdexcept> // domain_error
#include <string>    // string

using namespace std;

int f (bool b) {
    if (b)
    	throw new domain_error("abc"); // this is legal, but a bad idea, the object would be on the heap
        throw domain_error("abc");     // creates a domain_error object, calling one-arg constructor that takes a string
    return 0;}

void test1 () {
    try {
        assert(f(false) == 0);
        }
    catch (domain_error& e) {
        assert(false);}}      // this line will never be reached

void test2 () {
    try {
        assert f(true) == 1;
        assert(false);        // this line will never be reached
        }
    catch (domain_error& e) { // e is a reference to a domain_error object
//      assert(       e                == "abc");   // error: no match for ‘operator==’ in ‘e == "abc"’
//      assert(       e.what()         != "abc");   // warning: comparison with string literal results in unspecified behavior
        assert(strcmp(e.what(), "abc") == 0);
        assert(string(e.what())        == "abc");}}

void test3 () {
    domain_error x("abc");
    logic_error& y = x;
    exception&   z = y;
    assert(&x == &z);}

int main () {
    cout << "Exceptions.cpp" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}

/*
there is NO operator that takes a domain_error on the left and a string on the right
what() must be returning a string
then we're comparing strings (char*)
but we're actually comparing two pointers

let's call strcmp, which takes two pointers
under the hood, strcmp uses a loop to compare all of the chars
strcmp returns 0, if the two strings are equal
strcmp return a pos, if the right string is further in the dictionary than the left string
strcmp return a net, if the left string is further in the dictionary than the right string

let's build a string object, a one-arg constructor that takes a char*
*/

char s[] = "abc"; // char*, C string
char w[] = "abc";
cout << (s == w); // false

string t("abc");  // C++ string
string u("abc");
cout << (t == u);   // true
cout << (&t == &u); // false

/*
== on a C++ string on the left and a C string (char*) on the right
*/

/*
possible explanations for being able to compare a C++ string to a C string
1. someone is automatically converting the C string into a C++ string *****
2. there is an == that takes a C++ string and a C string
*/
