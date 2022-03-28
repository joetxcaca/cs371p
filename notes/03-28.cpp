// -----------
// Mon, 28 Mar
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
Paper #9: Dependency Inversion Principle
remember to go to Perusall THROUGH Canvas

this is the fifth of a 5-paper series
SOLID design
*/

/*
Takeaways:

 1. assertions are not good for testing
 2. assertions are not good for user errors
 3. don't use equality on floating point
 4. prefer pre-increment
 5. always catch by reference
 6. built-in stack arrays are always passed by address
 7. built-in stack arrays are DO NOT know their size
 8. built-in stack arrays are NOT comparable
 9. built-in stack arrays are NOT copyable
10. built-in stack arrays are NOT assignable
11. std::array<> DOES know its size
12. std::array<> IS comparable
13. std::array<> IS copyable
14. std::array<> IS assignable
12. std::array<> is to a built-in array as std::string is to a built-in char array
*/

/*
Integrated 5-Year CS BS/MS Program
https://www.cs.utexas.edu/undergraduate/academics/curriculum-degree-plans/5-year-cs-bsms/
Info Session
Tue, 29 Mar, 6 pm
Zoom
*/

/*
P3 moved to Tue, 29 Mar
iterators
arrays2, test 6
deque
list
stack
queue
priority_queue
*/

// -----------
// Arrays2.c++
// -----------

#include <cstdio>

#include <algorithm> // copy, count, equal, fill
#include <cassert>   // assert
#include <cstddef>   // ptrdiff_t, size_t
#include <iostream>  // cout, endl
#include <memory>    // unique_ptr
#include <string>    // string
#include <vector>    // vector

using namespace std;


struct Mammal {
    int i;

    string f () {
        return "A::f";}};

struct Tiger : Mammal { // child of A
    int j;

    string f () {
        return "B::f";}};

/*
const_cast
reinterpret_cast
static_cast
one more coming
*/

void test6 () {
//  Tiger*  const a = new Mammal[10];     // error: invalid conversion from ‘A*’ to ‘B*’
    Mammal* const a = new Tiger[10];     // dangerous
    assert(a[0].f() == "A::f");
//  assert(a[1].f() == "A::f"); // undefined
//  delete [] a;                // undefined
    Tiger* b = static_cast<Tiger*>(a);  // clang-check warning: Potential leak of memory pointed to by 'a'
    assert(b[1].f() == "B::f");
    delete [] b;}               // ~B::B() and ~A::A()

Tiger   x(...);
Mammal* p = &x; // see mammal properties

void test7 () {
    const ptrdiff_t   s = 10;
    const int         v =  2;
    unique_ptr<int[]> a(new int[s]); // automatically manage the memory and automatically delete
    fill(a.get(), a.get() + s, v);
    assert(count(a.get(), a.get() + s, v) == s);
    assert(a.get()[1] == v);
    f(a.get());
    assert(a.get()[1] == v + 2);}

void test8 () {
    const size_t s = 10;
    const int    v =  2;
    vector<int>  x(s, v);    // O(n), T(T), s times
    assert(x.size() == s);
    assert(x[0]     == v);   // index
    vector<int> y(x);        // copy, O(n), T(T), s times
    assert( x    ==  y);     // compare
    assert(&x[1] != &y[1]);
    vector<int> z(2 * s, v);
    x = z;                   // assign and resize
    assert( x    ==  z);
    assert(&x[1] != &z[1]);}

void h1 (vector<int>& y) {
    vector<int>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test9 () {
    vector<int> x = {2, 3, 4};
    h1(x);
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}

void h2 (vector<int> y) {
    vector<int>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test10 () {
    vector<int> x = {2, 3, 4};
    h2(x);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

int main () {
    cout << "Arrays2.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    cout << "Done." << endl;
    return 0;}

/*
cost of adding to the front
cost of adding to the middle
cost of adding to the back

cost of removing from the front
cost of removing from the middle
cost of removing from the back

cost of indexing
*/

/*
vector
front-loaded array on the heap
like Java's ArrayList

cost of adding to the front:  O(n)
cost of adding to the middle: O(n)
cost of adding to the back:   amortized O(1)

cost of removing from the front:  O(n)
cost of removing from the middle: O(n)
cost of removing from the back:   O(1)

cost of indexing: O(1)
*/

vector<int> x(10, 2);
cout << x.size();      // 10
cout << x.capacity();  // 10

vector<int>::iterator b = begin(x);
int*                  b = begin(x);

cout << *b; // 2

x.push_back(3);
cout << x.size();      // 11
cout << x.capacity();  // 20

cout << *b; // undefined!!!!
