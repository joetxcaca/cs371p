// -----------
// Fri, 25 Feb
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
please track your grades
*/

/*
Paper #6: Open-Closed Principle
remember to go to Perusall THROUGH Canvas

this is the first of a 5-paper series
SOLID design
*/

/*
Project #2: Voting
	1. write code to only handle the I/O
	2. use a single bucket (vector of vector)
	3. use a bucket per candidate
	4. can NOT use new/delete, use the STL (e.g., vector, list, etc.)
Canvas poll
crowd source checktestdata schema
best to remove make run-all from .gitlab-ci.yml, until you're really done
if you're working with a partner, you MUST join a Canvas group BEFORE you submit
*/

/*
programming contest
*/

/*
const
*/

int i = 2;
++i;
cout << i; // 3

const int ci;     // no, have to initialize
const int ci = 3;
++ci;             // no



int       i  = 2;
const int ci = 3;

int* p = i;  // no
int* p = &i;
++*p;
cout << i;   // 3

int* q = &ci; // no
++*q;         // can't allow that



// read-only, many-location pointer
// the target is immutable, the pointer is mutable

int       i  = 2;
const int ci = 3;

const int* pc = &ci;
++pc;                // ok, but crazy
++*pc;               // no

const int* qc;       // yes, don't have to initialize
qc = &ci;

const int* rc = &i;  // yes




// read-write, one-location pointer
// the target is mutable, the pointer is immutable

int       i  = 2;
const int ci = 3;

int* const cp = &ci; // no
int* const cp;       // no

int* const cp = &i;
++cp;               // no
++*cp;              // yes
cout << i;          // 3

int* a = new int[100];
++*a;
++a;
...
delete [] a; // runtime error

int* const b = new int[100];
++*b;
++b;  // no
...
delete [] b; // this now fine


// read-only, one-location pointer
// the target is immutable, the pointer is immutable

int       i  = 2;
const int ci = 3;

const int* const cpc; // no, has to be initialized

const int* const cpc = &ci; // yes
++cpc;                      // no
++*cpc;                     // no

const int* const cqc = &i; // yes



// read-write, one-location reference
// the target is mutable, the reference is immutable
// int& is most like int* const

int       i  = 2;
const int ci = 3;

int& r;      // no, has to be initialized
int& r = &i; // no
int& r = i;
++r;
cout << i;   // 3
cout << r;   // 3
++*r;        // no, r is not a pointer

int& s = ci; // no
++s;         // can't let this happen



// read-only, one-location reference
// the target is immutable, the reference is immutable
// const int& is most like const int* const

int       i  = 2;
const int ci = 3;

const int& r; // no, has to be initializede

const int& r = ci; // yes
++r;               // no

const int& s = i;  // yes
++s;               // no



int        i = 2;
const int* p = &i;
cout << i;         // 2
cout << *p;        // 2

++i;

cout << i;  // 3
cout << *p; // 3
