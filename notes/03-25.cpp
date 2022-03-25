// -----------
// Fri, 25 Mar
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
arrays2
*/

// -------------
// Iterators.cpp
// -------------

// https://en.cppreference.com/w/cpp/iterator

#include <algorithm>    // copy, fill, reverse, sort
#include <cassert>      // assert
#include <forward_list> // forward_list
#include <iostream>     // cout, endl
#include <iterator>     // istream_iterator, ostream_iterator
#include <list>         // list
#include <sstream>      // istringstream, ostringstream
#include <vector>       // vector

using namespace std;

void test1 () {
    istringstream         sin("2 3 4");
    ostringstream         sout;
    istream_iterator<int> b(sin);
    istream_iterator<int> e;
    ostream_iterator<int> x(sout, " ");
    copy(b, e, x);
    assert(sout.str() == "2 3 4 ");}

/*
    ostringstream         sout;
    ostream_iterator<int> b(sout, " ");
    ostream_iterator<int> e(sout);
    const int v = 2;
    fill(b, e, v);                      // error: no matching function for call to '__fill'
*/

void test2 () {
    forward_list<int> x(3);
    const int v = 2;
    fill(begin(x), end(x), v);
    assert(equal(begin(x), end(x), begin({2, 2, 2})));}

/*
    forward_list<int> x = {2, 3, 4};
    reverse(begin(x), end(x));       // error: no matching function for call to '__reverse'
*/

void test3 () {
    list<int> x = {2, 3, 4};
    reverse(begin(x), end(x));
    assert(equal(begin(x), end(x), begin({4, 3, 2})));}

/*
    list<int> x = {2, 3, 4};
    sort(begin(x), end(x));  // error: invalid operands to binary expression ('std::__1::__list_iterator<int, void *>' and 'std::__1::__list_iterator<int, void *>')
*/

void test4 () {
    vector<int> x = {4, 2, 3};
    sort(begin(x), end(x));
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

int main () {
    cout << "Iterators.cpp" << endl;
    test1();
    test2();
    test3();
    test4();
    cout << "Done." << endl;
    return 0;}










/*
char*, C string, built-in
can't compare
can't copy
can't assign
it doesn't know its size
can't resize

std::string, C++ string
can compare
can copy
can assign
it does know it size
CAN resize
*/

/*
T*, stack array, built-in
can't compare
can't copy
can't assign
it doesn't know its size
can't resize

std::array<T>
can compare
can copy
can assign
it does know it size
can't resize
*/


/*
T*, heap array, built-in
can't compare
can't copy
can't assign
it doesn't know its size
can't resize

std::vector<T>
construction is actually cheaper!!!
can compare
can copy
can assign
it does know it size
CAN resize
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

void f (int p[]) {
    assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

void test1 () {
    const size_t s = 10;
    const int       v =  2;
    int*  const     a = new int[s]; // O(1), no initialization
    assert(sizeof(a) == 8);
    fill(a, a + s, v);              // O(n)
    assert(count(a, a + s, v) == s);
    assert(a[1] == v);
    f(a);
    assert(a[1] == v + 2);
	delete    a;  // undefined runtime
    delete [] a;}

struct Max {
	Max (int)        {...}             // int    constructor
	Max (double)     {...}             // double constructor
	Max (const Max&) {...}             // copy   constructor
	Max& operator = (const Max&) {...} // copy assignment

Max* a = new Max[s]; // O(n), Max(),  s times
Max  v(...);
fill(a, a+s, v);     // O(n), =(Max), s times
delete [] a;         // O(n), ~Max(), s times


template <typename T>
class vector {
	vector (size_t s, const T& v)}

vector<Max> x(s, v); // O(n), Max(Max), s times
vector<Max> x(s, 2); // O(n), Max(int), once, Max(Max), s times

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

void test2 () {
    const ptrdiff_t s = 10;
    const int       v = 2;
    int* const      a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    assert(count(a, a + s, v) == s);
    assert(a[1] == v);
    g(a);
    assert(a[1] == v + 2);
    delete [] a;}

void h (int j) {
	...}

const int i = 2;
h(i);

void test3 () {
    const size_t  s = 10;
    const int     v = 2;
    int*  const   a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* const b = a;
    assert(&a[1] == &b[1]);
    delete [] a;}

void test4 () {
    const size_t  s = 10;
    const int     v = 2;
    int*  const   a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* const x = new int[s];
    copy(a, a + s, x);         // O(n), =(T), s times
    assert( a[1] ==  x[1]);
    assert(&a[1] != &x[1]);
    delete [] a;
    delete [] x;}

vector<Max> x(s, v); //
vector<Max> y(x);    // O(n), Max(Max), s times

void test5 () {
    const size_t s = 10;
    const int    v =  2;
    int*  const  a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* b = new int[s];
    fill(b, b + s, v);
//  b = a;                           // memory leak
    copy(a, a + s, b);
    assert( a[1] ==  b[1]);
    assert(&a[1] != &b[1]);
    delete [] a;
    delete [] b;}

vector<Max> x(s,   v);
vector<Max> y(2*s, v);

x = y;            // ~Max(), s times; Max(Max), 2*s times
cout << (x == y); // true


vector<Max> x(s,   v);
vector<Max> y(2*s, v);
vector<Max> z(2*s, v);

y = x;            // ~Max(), s times
cout << (x == y); // true

y = z; // O(n), =(Max), s times; Max(Max), s times
