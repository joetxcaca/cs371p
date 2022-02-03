// -----------
// Mon, 24 Jan
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
	5.9.1
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
Google Sheet: grades tracker
Google Form: virtual tokens
Twitter: #utcsoopswe
*/


// ---------
// Hello.cpp
// ---------

// https://en.cppreference.com
// https://en.cppreference.com/w/cpp/io
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html

// line comment

#include <iostream> // cout, endl; is this the same as Java's import? NO

int main () {
    using namespace std; // this is the equivalent to Java's import
    cout << "Nothing to be done." << endl;
    return 0;}

/*
what is the type of cout? ostream
<< is an operator
that takes an ostream on the left and a string on the right
what is the return type of << in this case: ostream
*/

cout << "hi" << 2 << "Justin" << 3.4;

// endl is adding a "\n", flush the output buffer

int i = 2;
int j = 3;
int k = (i + j); // +' args are two ints, +'s return type is also an int
k = (i + j + k); // i+j must return something that is acceptable as the LHS of another +

/* block comment
Developed in 1978 by Bjarne Stroustrup of Denmark.
C++ is procedural, object-oriented, statically typed, and not garbage collected.

C++98
C++03
C++11
C++14
C++17
C++20
C++23



% which clang++
/usr/bin/clang++



% clang++ --version
Apple clang version 13.0.0 (clang-1300.0.29.30)
Target: x86_64-apple-darwin21.2.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin


// compilation of the program
% clang++ -g -std=c++17 -Wall -Wextra -Wpedantic Hello.cpp -o Hello
...


// the running of the program
% ./Hello // look in the local directory for this executable
Nothing to be done.
*/

/*
OSes have execution paths
are collections of folder that will be searched when running a program
/usr/bin/ is on that path
*/

/*
assertions
	validate the state of a computation
*/

/*
Collatz Conjecture (1930s)

take a pos int
if even, divide   it by 2
if odd,  multiply it by 3 and add 1
repeat until 1

no one in 90 years has been able to prove mathematically that this true for all pos ints
*/

5 16 8 4 2 1

/*
cycle length of  5 is 6
cycle length of 10 is 7
*/

// --------------
// Assertions.cpp
// --------------

// https://en.cppreference.com/w/cpp/error/assert

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

int cycle_length (int n) {
    assert(n > 0); // precondition
    int c = 0;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0); // post condition
    return c;}

void test () {
    assert(cycle_length( 1) == 1);  // use assert for testing
    assert(cycle_length( 5) == 6);
    assert(cycle_length(10) == 7);}

int main () {
    cout << "Assertions.cpp" << endl;
    test();
    cout << "Done." << endl;
    return 0;}

/*
% clang++ -g -std=c++17 -Wall -Wextra -Wpedantic Assertions.cpp -o Assertions
% ./Assertions
Assertions.cpp
Assertion failed: (c > 0), function cycle_length, file Assertions.cpp, line 21.



Turn OFF assertions at compile time with -DNDEBUG
% clang++ -g -std=c++17 -DNDEBUG -Wall -Wextra -Wpedantic Assertions.cpp -o Assertions
% ./Assertions
Assertions.cpp
Done.
*/

/*
assertions
	good for programmer errors
	BAD  for testing
	what is good for testing is a unit test framework, like JUnit for Java; Google Test for C++
	BAD  for user errors
	what is good for user errors will be exceptions
*/
