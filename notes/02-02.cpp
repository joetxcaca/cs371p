// -----------
// Wed,  2 Feb
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
Paper #03: Continuous Integration
remember to go to Perusall THROUGH Canvas
*/

/*
Project #1: Collatz
Poll: Project #1: Collatz
Academic Integrity Quiz

Add
SHELL := /bin/bash
to the Makefile.
*/

/*
first exercise, warm up

on HackerRank

1. e-mail (any e-mail)
2. password (I will provide password)
3. name (names of ALL of the students)
4. EID  (EIDs  of ALL of the students)

breakout room

ONE of you to volunteer to drive
EVEYONE else please turn ON your video
please collaborate
ask for help BEFORE you submit
*/

/*
broken tests can hide broken code
*/

// ------------
// IsPrimeH.cpp
// ------------

// https://en.wikipedia.org/wiki/Primality_test

#include <cassert>  // assert
#include <cmath>    // sqrt
#include <iostream> // cout, endl

using namespace std;

bool is_prime (int n) {
    assert(n > 0);
    if (n == 2)
    	return True;
    if ((n == 1) || ((n % 2) == 0))
        return false;
    for (int i = 3; i < std::sqrt(n) + 1; i += 2)
        if ((n % i) == 0)
            return false;
    return true;}

void test0 () {
    assert(!is_prime( 1));}

void test1 () {
    assert( is_prime( 2));} // broken

void test2 () {
    assert( is_prime( 3));}

void test3 () {
    assert(!is_prime( 4));}

void test4 () {
    assert( is_prime( 5));}

void test5 () {
    assert( is_prime( 7));}

void test6 () {
    assert(!is_prime( 9));} // broken

void test7 () {
    assert(!is_prime(27));}

void test8 () {
    assert( is_prime(29));}

/*
1. run the code as is, confirm success
2. identify and remember and fix the broken tests
3. run the code again, confirm failure
4. identify and remember and fix the broken code
5. run the code again, confirm success
*/

https://hr.gs/cs371p-spring-2022-is-prime
1234
