// -----------
// Fri, 18 Feb
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
Paper #5: Single Responsibility Principle
remember to go to Perusall THROUGH Canvas

this is the first of a 5-paper series
SOLID design
*/

/*
Project #2: Voting
	1. write code to only handle the I/O
	2. use a single bucket
	3. use a bucket per candidate
	4. can NOT use new/delete, use the STL (e.g., vector, list, etc.)
Canvas poll
crowd source checktestdata schema
best to remove make run-all from .gitlab-ci.yml, until you're really done
*/

/*
two tokens:   *, &
two contexts: modifying a type, modifying a variable
*/

int i = 2;
int v = i; // copy
++v;
cout << i; // 2

int  i = 2;
int* p = i;  // no
int* p = &i; // * declares a pointer; & takes an address, & needs an l-value
cout << *p;  // 2; * dereferences, * needs a pointer, * is okay with an r-value
++p;         // moving the pointer to point to illegal memory
cout << *p;  // runtime error

int  i = 2;
int* q = &i;
++*q;        // increment i
cout << i;   // 3

int a[] = {2, 3, 4}; // arrays are really pointers to the first element
cout << *a;          // 2
cout << *(a + 1);    // 3

int  i = 2;
int& r = &i; // no
inr& r = i;  // r becomes a permanent alias to i

i = 3; // change the value of i/r from 2 to 3
r = 3; // change the value of i/r from 2 to 3

int  i = 2;
int* p;    // not required to initialize
p = &i;
int  j = 3;
p = &j;

int  i = 2;
int& r;     // required to initialize

void test1 () {
    int i = 2;
    int v = i;
    ++v;
    assert(i  == 2);
    assert(v  == 3);
    assert(&i != &v);}

void test2 () {
    int  j = 2;
    int* p;
//  p = j;             // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    p = &j;
    ++*p;
    assert(j  == 3);
    assert(*p == 3);
    assert(p  == &j);}

void test3 () {
    int  k = 2;
//  int& r;            //  error: 'r' declared as reference but not initialized
//  int& r = &k;       // error: invalid conversion from 'int*' to 'int' [-fpermissive]
    int& r = k;
    ++r;               // same as ++k
    assert(k  == 3);
    assert(r  == 3);
    assert(&r == &k);} // r and k are two names for the same location in memory

void test4 () {
    int   i = 2;
    int*  p = &i;
    int*& r = p;
    ++*r;              // ++*p
    assert(i  == 3);
    assert(*p == 3);
    assert(*r == 3);
    assert(&r == &p);} // r and p are two names for the same location in memory

    cout << (&p == &i) // no; type of the left: int**; type of the right: int*
