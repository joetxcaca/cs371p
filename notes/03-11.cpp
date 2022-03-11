// -----------
// Fri, 11 Mar
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
Paper #8: Interface Segregation Principle
remember to go to Perusall THROUGH Canvas

this is the fourth of a 5-paper series
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

int  s = ...;
int* a = new int[s]; // heap-allocated int array, undefined, O(1)

T* a = new T[s]; // if T is a built-in type, O(1), undefined values
			     // if T is a user     type, O(n), default constructor, s times

T v = ...;

loop
	a[i] = v;

class Lance {
	Lance (const Lance& rhs) {             // copy constructor
		...}

	Lance& operator = (const Lance& rhs) { // copy assignment operator
		...}};

Lance* a = new Lance[s];
Lance  v = ...;

fill(a, a + s, v); // O(n), copy assignment operator, s times

vector<Lance> x(s, v); // O(n), copy constructor, s times

template <typename FI, typename T>
void fill (FI b, FI e, const T& v) {
	while (b != e) {
		*b = v; // copy assignment operator of T
		++b;}}

/*
requirements on T1
	1. !=
	2. * (write only)
	3. ++
*/

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

// a user type T

int s = ...;
T   v = ...;

T* a = new T[s]; // O(n), T()  s times
fill(a, a+s, v); // O(n), =(T) s times
...              // now I can use the array
delete [] a;

{
vector<T> x(s, v); // O(n), T(T) s times
} // the vector will automatically clean up

#include <memory> // allocator

allocator<T> x;          // allocator's default constructor
T* a = x.allocate(s);    // builds the array, O(1), no initialization
loop
	x.construct(a+i, v); // T's copy constructor, s times
...                      // now I can use the arra
loop
	x.destroy(a+i);
x.deallocate(a, s);

template <typename T, int N> // N is the number of bytes in the heap that we are managing
class my_allocator {
	private:
		char a[N]; // this is the "heap"

	public:
		T* allocate (...)

		void construct (...) {
			// this is already built}

		void destroy (...) {
			// this is already built}

		void deallocate (...)

my_allocator<double, 100> x; // this is an allocator of doubles with a "heap" of 100 bytes

[92...92] // 4 + 92 + 4 = 100

double* a = x.allocate(5); // this needs 40 bytes

[-40...-4044...44]

/*
pos sentinels surround a free block, 4 + 44 + 4 = 52
neg sentinels surround a busy block, 4 + 40 + 4 = 48

52 + 48 = 100
*/

x.deallocate(a, s);

[40...4044...44] // don't want two free blocks in a row, instead we join them

[92...92] // 4 + 92 + 4 = 100
