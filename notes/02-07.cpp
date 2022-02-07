// -----------
// Mon,  7 Feb
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

.gitlab-ci.yml
make run-all
*/

/*
virtual tokens
*/

/*
Quiz #7
*/

/*
assertions are not good for user errors
exceptions are
*/

/*
let's pretend that we don't have exceptions
as an example C doesn't have exceptions
*/

// use the return

int f (...) {
	...
	if (...)
		// something wrong
		return /* special value */
	...}

int g (...) {
	...
	int i = f(...);
	if (i == /* special value */)
		// do something about it
	...}

// use a global

int h = 0;

int f (...) {
	...
	if (...)
		// something wrong
		h = /* special value */
		return ...
	...}

int g (...) {
	...
	h = 0;
	int i = f(...);
	if (h == /* special value */)
		// do something about it
	...}

// use a parameter, doesn't work, because int is passed by value (copy)

int f (..., int e2) { // e2 is a copy of e
	...
	if (...)
		// something wrong
		e2 = /* special value */
		return ...
	...}

int g (...) {
	...
	int e = 0;
	int i = f(..., e);
	if (e == /* special value */)
		// do something about it
	...}

// let's use Java
// use a parameter, doesn't work, because int is passed by value (copy)

int f (..., Integer e2) { // e2 is a copy of e
	...
	if (...)
		// something wrong
		e2 = /* special value */ // this work, but it creates a new object
		return ...
	...}

int g (...) {
	...
	Integer e = 0;              // does this work? YES, because of autoboxing
	Integer e = new Integer(0); // e is a reference (address) of an Integer object
	int i = f(..., e);
	if (e == /* special value */)
		// do something about it
	...}

// let's use Java
// use a parameter

int f (..., int[] e2) { // e2 is a copy of e
	...
	if (...)
		// something wrong
		e2 = /* special value */ // this work, but it creates a new object
		e2[0] = /* special value */
		return ...
	...}

int g (...) {
	...
	int[] e = {0}; // e is a reference (address) to an array object
	int i = f(..., e);
	if (e[0] == /* special value */)
		// do something about it
	...}

// use a parameter

int f (..., int& e2) { // e2 another name for e
	...
	if (...)
		// something wrong
		e2 = /* special value */
		return ...
	...}

int g (...) {
	...
	int e = 0;
	int i = f(..., e);
	if (e == /* special value */)
		// do something about it
	...}

// use exceptions

int f (...) {
	...
	if (...)
		// something wrong
		throw E();          // E is an exception type
	...}

int g (...) {
	...
	try {
		...
		int i = f(...);
		...}
	catch (E e) {
		// do something about it
		}
	...}

/*
f does NOT throw E
	rest of f()
	rest of try body
	NO catch
	rest of g()
*/

/*
f does throw E
	NO rest of f()
	NO rest of try body
	catch
	rest of g()
*/

int f (...) {
	...
	if (...)
		// something wrong
		throw E();          // E is an exception type
	...}

int g (...) {
	...
	try {
		...
		int i = f(...);
		...}
	catch (F e) { // F is unrelated to E
		// do something about it
		}
	...}

/*
f does throw E
	NO rest of f()
	NO rest of try body
	NO catch
	NO rest of g()
	go to the caller of g()
		1. there is NO try catch block:                         go to the caller of the caller
		2. there is a try catch block, but it does NOT catch E: go to the caller of the caller
		3. there is a try catch block that catches E:           catch and then rest of caller
*/

/*
Java has a finally clause, C++ does NOT
Python has a finally clause and an else clause, and C++ does NOT have an else clause either
*/
