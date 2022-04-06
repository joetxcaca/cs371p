// -----------
// Wed,  6 Apr
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
Paper #10: Why getter and setter methods are evil
remember to go to Perusall THROUGH Canvas
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
13. built-in heap arrays are always passed by address
14. built-in heap arrays are DO NOT know their size
15. built-in heap arrays are NOT comparable
16. built-in heap arrays are NOT copyable
17. built-in heap arrays are NOT assignable
18. built-in heap arrays are NOT resizable
19. std::vector<> DOES know its size
20. std::vector<> IS comparable
21. std::vector<> IS copyable
22. std::vector<> IS assignable
23. std::vector<> IS resizable
24. std::vector<> is to a built-in heap array as std::array is to a built-in stack array
25. std::vector<> resizing will invalidate old iterators, pointers, and references
26. use member initialization list to avoid unwanted default constructor call
27. use const_cast for reuse
28. use explicit to turn off implicit type conversion
*/

/*
stack
member initialization list
const_cast
friend
explicit
queue
priority_queue
*/

struct Cristian {};

Cristian x; // yes


template <typename T, typename C = std::deque<T>>
class my_stack {
    friend bool operator == (const my_stack& lhs, const my_stack& rhs) {
        return lhs._c == rhs._c;}

    private:
        C _c;

    public:
    	my_stack             ()                 = default;
        my_stack             (const my_stack&)  = default;
        ~my_stack            ()                 = default;
        my_stack& operator = (const my_stack&)  = default;

		// this constructor exists to accommodate the possibility that C does NOT have a C()

		// explicit makes this ONLY a constructor
        explicit my_stack (const C& c) { // C()
                _c = c;}                 // =(C)

		// explicit makes this ONLY a constructor
        explicit my_stack (const C& c) : // member initialization list
                _c (c)                   // C(C)
            {}

        bool empty () const {
            return _c.empty();}

        void pop () {
            _c.pop_back();}

        void push (const T& v) {
            _c.push_back(v);}

        size_t size () const {
            return _c.size();}

        T& top () {
            return _c.back();}

        const T& top () const { // read-only version to reuse the read/write version
            return const_cast<stack&>(*this).top();}};

void f (stack<int> xx) {}

stack<int> x;
f(x);

deque<int> d;
f(d);            // no!!!
stack<int> y(d);

vector<int> v;
stack<int> z(v); // no

stack<int, vector<int>> t(v);

class string {
	string (const char*) {...}; // a constructor AND it's a type converter
	...};

void g (string t) {
	...}

string s = "abc";
g(s);
g("abc");         // ok

class Chris { // backing container, assume it doesn't have Chris()
	...}

stack<int, Chris<int>> x; // fails

Chris c(...);
stack<int, Chris<int>> x(c);

/*
sequential containers
	vector
	deque
	forward_list
	list
*/

/*
container adapters
	stack
	queue
	priority_queue
*/

/*
stack
	vector, deque (default), list, forward_list
	LIFO
	push  -> push_back
	pop   -> pop_back
	size  -> size
	empty -> empty
	top   -> back, 2 versions
*/

/*
queue
	deque (default), list
	FIFO
	push  -> push_back
	pop   -> pop_front
	size  -> size
	empty -> empty
	front -> front, 2 versions
	back  -> back,  2 versions
*/

/*
priority_queue
	binary heap
	deque, vector (default)
	push  -> push_back, reheapify
	pop   -> pop_back,  reheapify
	size  -> size
	empty -> empty
	top   -> back, only 1 version, read-only
*/

/*
associative containers
	set
	multi_set
	unordered_set
	map
	multi_map
	unordered_map
*/

/*
set is like Java's TreeSet
	ordered
	keys must be comparable
	unique elements
	find(), only 1 version, read-only
*/

/*
unorderedset is like Java's HashSet
	unordered
	keys must be hashable
	unique elements
	find(), only 1 version, read-only
*/
