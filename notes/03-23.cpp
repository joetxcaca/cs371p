// -----------
// Wed, 23 Mar
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
iteration
arrays2
*/

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // !=

using namespace std;

using std::rel_ops::operator!=;

#define TEST0
#define TEST1
#define TEST2
#define TEST3
#define TEST4

template <typename T>
class DigitsIterator {
    friend bool operator == (const DigitsIterator& lhs, const DigitsIterator& rhs) {
            return (lhs == rhs);}

    public:
        using iterator_category = input_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

    private:
        T _v;

    public:
        DigitsIterator (const T& v) :
                _v (v)
            {}

        T operator * () const {
            return _v % 10;}

        DigitsIterator& operator ++ () {   // pre-increment
            _v /= 10;
            return *this;}

        DigitsIterator operator ++ (int) { // post-increment
            DigitsIterator x = *this;
            ++*this;
            return x;}};

for (Jack i = 0; i != s; ++i)
	...

#ifdef TEST0
void test0 () {
    const DigitsIterator<int> b = 0;
    assert(*b == 0);}
#endif

#ifdef TEST1
void test1 () {
    const DigitsIterator<int> b = 0;
    const DigitsIterator<int> e = 0;
    assert(b == e);}
#endif

#ifdef TEST2
void test2 () {
    DigitsIterator<int> b = 2;
    DigitsIterator<int> e = 0;
    assert(b  != e);
    assert(*b == 2);
    DigitsIterator<int>& p = ++b;
    assert(&p == &b);
    assert(b  == e);}
#endif

#ifdef TEST3
void test3 () {
    DigitsIterator<int> b = 23;
    DigitsIterator<int> e = 0;
    assert(b  != e);
    assert(*b == 3);
    ++b;
    assert(b  != e);
    assert(*b == 2);
    DigitsIterator<int> p = b++;
    assert(&p != &b);
    assert(b  == e);}
#endif

#ifdef TEST4
void test4 () {
    DigitsIterator<int> b = 234;
    DigitsIterator<int> e = 0;
    assert(equal(b, e, begin({4, 3, 2})));}
#endif


/*
input
	==, !=, * (read), ++
output
	* (write), ++
forward
	==, !=, * (read/write), ++
bidirectional
	==, !=, * (read/write), ++, --
random-access
	==, !=, * (read/write), ++, --, +, -, <, >, <=, >=
*/





























