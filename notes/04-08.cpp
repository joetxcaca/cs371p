// -----------
// Fri,  8 Apr
// -----------

/*
Paper #11: More getters and setters
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
29. make symmetric non-member friend functions
*/

/*
getters and setters
friend
map
*/

class string {
	private:
		...

	public:
		string (const char*) {...} // construct AND type converter

	...};

void f (string t) {
	...}

string s("abc");
f(s);            // yes
f("abc");        // yes, implicit conversion

template <typenane T>
class vector {
	private:
		...

	public:
		explicit vector (size_t s) {...} // size constructor, ONLY a constructor

		vector (initializer_list<T> ll) {...}

	...};

void g (vector<int> y) {
	...}

vector<int> x(10); // size constructor
g(x);              // yes
g(10);             // no

vector<int> y(10000); // explicit construction of a large data structure
g(10000);             // IMPLICIT

vector<int> z({2, 3, 4, 5, 6, 7}); // initializer_list constructor
g({2, 3, 4, 5, 6, 7})

class string {
	private:
		...

	public:
		string (const char*) {...} // construct AND type converter

		bool operator == (const string& ) {
			...}

	...};

x.f(...); // method

string s("abc");
string t("abc");
cout << (s == t); // s.operator==(t)

cout << (s == "abc"); // s.operator==("abc")

cout << ("abc" == s); // "abc". // no




class string {
	friend bool operator == (const string&, const string&);

	private:
		char* _a; // this is the internal array of char on the heap

	public:
		string (const char*) {...} // construct AND type converter

	...};


bool operator == (const string& lhs, const string& rhs) {
	...}


string s("abc");
string t("abc");
cout << (s == t); // operator==(s, t) // yes

cout << (s == "abc"); // operator==(s, "abc") // yes

cout << ("abc" == s); // operator==("abc", s) // yes




class string {
	 friend bool operator == (const string& lhs, const string& rhs) {
		...}

	private:
		char* _a; // this is the internal array of char on the heap

	public:
		string (const char*) {...} // construct AND type converter

	...};


/*
symmetric operators, non-member friend functions
	==
	!=
	+
	-
	*
	/
	%
	<
	>
	<=
	>=
*/

/*
non-symmetric operators, remain non-friend member functions
	+=
	-=
	*=
	/=
	%=
*/
