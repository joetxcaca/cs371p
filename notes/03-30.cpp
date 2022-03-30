// -----------
// Wed, 30 Mar
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
*/

/*
deque
list
stack
queue
priority_queue
*/

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

vector will NOT respond to push_front() or remove_front()
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

/*
deque
middle-loaded array of arrays on the heap
like Java's ArrayDeque

cost of adding to the front:  amortized O(1)
cost of adding to the middle: O(n)
cost of adding to the back:   amortized O(1)

cost of removing from the front:  O(1)
cost of removing from the middle: O(n)
cost of removing from the back:   O(1)

cost of indexing: O(1), much more expensive because other +, /, %
*/

/*
deque
	1. asymmetry of vector
	2. the invalidation of iterators, pointers, and references with the vector grows
middle-loaded array of arrays
*/

// 7 rows, 5 cols
// size of 9, capacity of 35
// not full

# .....
# .....
# ....*
# *****
# **...
# .....
# .....

//

deque x(10, 2)
cout << x.size();     // 10
cout << x.capacity(); // no

// full deque

deque x(15, 2)
cout << x.size(); // 15
cout << x[7];     // 7/5 that gets me the row, 7%5 that gets me the col

# 22222
# 22222
# 22222

x.push_back(3)

# .....
# 22222
# 22222
# 22222
# 3....
# .....

deque<int> x(10, 2);
cout << x.size();      // 10

deque<int>::iterator b = begin(x);
int*                 b = begin(x); // no!!!!!!

cout << *b; // 2

x.push_back(3);
cout << x.size();      // 11

cout << *b; // 2!!!!


/*
list
doubly-linked list
like Java's LinkedList

cost of adding to the front:  O(1)
cost of adding to the middle: O(1)
cost of adding to the back:   O(1)

cost of removing from the front:  O(1)
cost of removing from the middle: O(1)
cost of removing from the back:   O(1)

cost of indexing: not available
*/

/*
Java
Collection
List
	get(int)
ArrayList  both implement List, get(), O(1)
LinkedList both implement List, get(), O(n)
*/


/*
three workhorses
	vector
	deque
	list
*/

/*
container adapters
	stack
	queue
	priority_queue
*/

struct Stack : Vector { // Stack a child of Vector
	push  -> push_back
	pop   -> pop_back
	top   -> back
	size  -> size
	empty -> empty
	};

/*
Java
stack IS a child of vector!!!!!
*/

/*
because we don't want stack to do anything else is bad to inherit from vector
*/

template <typename T, typename C = deque<T>>
class Stack {
	private:
		C _c;

	public:
		void push (const T& v) {
			_c.push_back(v);}

		pop   -> pop_back
		top   -> back
		size  -> size
		empty -> empty
	}

/*
two forms of reuse
	1. inheritance, reuse code, reuse interface
	2. composition, reuse code
*/

/*
vector is faster at indexing than deque
vector is slower at growing  than deque
*/

stack<int> x; // yes

stack<int, list<int>> y; // yes

stack<int, deque<int>> y; // yes

stack<double, list<double>> t;
