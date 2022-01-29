// -----------
// Fri, 28 Jan
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
	https://docs.google.com/forms/d/1paG6AnfFj_NtSWUai-mKBFdG8mw-JsxNgPfsI79p9QI/
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

n + (n >> 1) + 1

/*
cycle length
even, divide   by 2
odd,  multiply by 3 and add 1
*/

3n + 1 // n is odd

int cycle_length (int n) {
    assert(n > 0);
    int c = 0;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
            ???
        ++c;}
    assert(c > 0);
    return c;}

(3n + 1) / 2
3n/2 + 1/2   // n is odd, integer arithmetic
3n/2 + 1
n + n/2 + 1
n + (n >> 1) + 1

mcl(10, 100)
b = 10
e = 100
m = (e/2 + 1) = 51
if m > b
mcl(10, 100) = mcl(51, 100)
// we have to be convinced that
mcl(10, 50) // doesn't matter

mcl(200, 300)
b = 200
e = 300
m = 151
m is NOT > b
NO claim

mcl(1, 10)

/*
first step
always write the simplest solution
NO optimizations
*/

/*
use that (slow) solution to produce lots of tests
use checktestdata to produce a set of random pairs
run your solution to produce the correct corresponding triples
*/

/*
optimize in the smallest simplest steps
rerun the tests
*/

/*
second step
implement the optimizations of the quiz
rerun the tests

tests are run automatically on GitLab via .gitlab-ci.yml in there continuous integration setup
*/

/*
third step
three kinds of cache
	1. lazy cache: cache the values in response to reading the test cases
		a. only store the cycle lengths of the actual values
		b. store the intermediate
		what should the size of the cache be?
			a. let's try 1,000,000
				it's not obvious that that is optimal
			b. try different sizes
	2. eager cache: cache values before the first read
		what should the size of the cache be?
			a. let's try 1,000,000
				it's not obvious that that is optimal
			b. try different sizes
	3. meta cache (NOT happening on HackerRank)
		precompute values and store them in the source file
		HackerRank has a 50k source file size limit
*/
