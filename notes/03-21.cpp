// -----------
// Mon, 21 Mar
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


struct A {
    A () {
        cout << "A() ";}
    A (int) {
        cout << "A(int) ";}
    A (const A&) {
        cout << "A(A) ";}
    A& operator = (const A&) {
        cout << "=(A) ";
        return *this;}
    ~A () {
        cout << "~A() ";}};

void test4 () {
    allocator<A> x;
    A            v = 3;
    A*           a = x.allocate(2);
    a[0] = v;                       // copy assignment, no good!!!
    x.construct(a, v);              // copy constructor

    A            w = 4;
    a[0] = w;                       // NOW, this would be ok

    x.destroy(a);
    x.deallocate(a, 2);}

/*
allocator project

managing an array of char (bytes)

defining blocks (free or busy) with the use of matching int sentinels at both ends of the block
free blocks have pos sentinels
busy blocks have neg sentinels
*/

    private:
        // ----
        // data
        // ----

        char a[N];

        /**
         * O(1) in space
         * O(n) in time
         * <your documentation>
         */
        bool valid () const {
            // <your code>
            // <use iterators>
            return true;}

    public:
        // -----------
        // constructor
        // -----------

        /**
         * O(1) in space
         * O(1) in time
         * throw a bad_alloc exception, if N is less than sizeof(T) + (2 * sizeof(int))
         */
        my_allocator () {
            (*this)[0] = 0;                                   // no
            (*this)[0]               = N - (2 * sizeof(int));
            (*this)[N - sizeof(int)] = N - (2 * sizeof(int));
            // <your code>
            assert(valid());}

        /**
         * O(1) in space
         * O(n) in time
         * after allocation there must be enough space left for a valid block
         * the smallest allowable block is sizeof(T) + (2 * sizeof(int))
         * choose the first block that fits
         * throw a bad_alloc exception, if n is invalid
         */
        pointer allocate (size_type) {
            // <your code>
            assert(valid());
            return nullptr;}             // replace!

        // ---------
        // construct
        // ---------

        /**
         * O(1) in space
         * O(1) in time
         */
        void construct (pointer p, const_reference v) {
            new (p) T(v);                               // this is correct and exempt
            assert(valid());}                           // from the prohibition of new

        // ----------
        // deallocate
        // ----------

        /**
         * O(1) in space
         * O(1) in time
         * after deallocation adjacent free blocks must be coalesced
         * throw an invalid_argument exception, if p is invalid
         * <your documentation>
         */
        void deallocate (pointer, size_type) {
            // <your code>
            assert(valid());}

        // -------
        // destroy
        // -------

        /**
         * O(1) in space
         * O(1) in time
         */
        void destroy (pointer p) {
            p->~T();               // this is correct
            assert(valid());}

        // -----------
        // operator []
        // -----------

        /**
         * O(1) in space
         * O(1) in time
         */
        int& operator [] (int i) {
            return *reinterpret_cast<int*>(&a[i]);}

        /**
         * O(1) in space
         * O(1) in time
         */
        const int& operator [] (int i) const {
            return *reinterpret_cast<const int*>(&a[i]);}

struct A {
	int _i;

	void f () {
		++_i;}};

A x;
x.f();

const A cx;
cx.f();     // no



struct A {
	int _i;

	void f () {
		++_i;}

	void g () const {
		++_i;         // no
		cout << i;}};

A x;
x.g();

const A cx;
cx.g();


struct A {
	int _i;

	void h () {
		++_i;}

	void h () const {
		++_i;         // no
		cout << i;}};

A x;
x.h(); // non-const h()

const A cx;
cx.h();     // const h()

/*
100 bytes
*/

92...92

allocator<double> x;
double* a = x.allocate(5); // 40 + 8 = 48

48       52
-40...-4044...44

double* b = x.allocate(5); // 40 + 8 = 48

48       48       4
-40...-40-40...-40... // no good, can't leave behind a useless free block

48       52
-40...-40-44...-44
