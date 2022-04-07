// -----------
// Mon,  4 Apr
// -----------

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
stack
queue
priority_queue
*/


template <typename T, typename C = deque<T>>
class Stack {
	private:
		C _c;

	public:
		void push (const T& v) {
			_c.push_back(v);}

		pop   -> pop_back

		const T& top () const {
			...} // might be nice these two tops to reuse each other

		T& top () {
			...} // might be nice these two tops to reuse each other

		size_t size () const {
			return _c.size();}

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

stack<double, vector<double>> t;

void f (const stack<int>& y) {
	cout << y.size();
	cout << y.top();  // 3
	y.top() = 4;}     // no

stack<int> x;
...
f(x);

stack<int> x;
x.push_back(2);
x.push_back(3);
cout << x.top(); // 3
f(x);
x.top() = 4;     // yes
