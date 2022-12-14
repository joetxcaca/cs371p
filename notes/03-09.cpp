// -----------
// Wed,  9 Mar
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
*/

/*
input iterator

==, !=
* (read only)
++

istream_iterator
*/


/*
output iterator, no comparison

* (write only)
++

ostream_iterator
*/

/*
forward iterator

==, !=
* (read write only)
++

forward_list, singly-linked list
*/

/*
bidirectional iterator

==, !=
* (read write only)
++, --

list, doubly-linked list, like LinkedList
*/

/*
random-access iterator

==, !=
* (read write only)
++, --
[], +, -, <, <=, >, >=

vector, front-loaded array, like ArrayList
*/


template <typename RI>
void my_reverse_1 (RI b, RI e) {
    while (b < --e) {
        swap(*b, *e);
        ++b;}}

template <typename BI>
void my_reverse_2 (BI b, BI e) {
    while ((b != e) && (b != --e)) {
        swap(*b, *e);
        ++b;}}

#ifdef TEST0
void test0 () {
    int a[] = {2, 3, 4};
    my_reverse(a, a);
    assert(equal(a, a + 3, begin({2, 3, 4})));}
#endif

#ifdef TEST1
void test1 () {
    int a[] = {2, 3, 4};
    my_reverse(a, a + 1);
    assert(equal(a, a + 3, begin({2, 3, 4})));}
#endif

#ifdef TEST2
void test2 () {
    list<int>           x = {2, 3, 4};
    list<int>::iterator e = begin(x);
    ++++e;
    my_reverse(begin(x), e);
    assert(equal(begin(x), end(x), begin({3, 2, 4})));}
#endif

#ifdef TEST3
void test3 () {
    list<int> x = {2, 3, 4};
    my_reverse(begin(x), end(x));
    assert(equal(begin(x), end(x), begin({4, 3, 2})));}
#endif
