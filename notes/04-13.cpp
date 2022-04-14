// -----------
// Wed, 13 Apr
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
initializations
vector
*/


struct D {
    static int c;

    int i;

    D             ()         = default; // default constructor
    D             (const D&) = default; // copy constructor
    D& operator = (const D&) = default; // copy assignment operator
    ~D            ()         = default; // destructor

    D (initializer_list<int>) {
        ++c;}};

int D::c = 0;

void test6 () {
//  D x(2);             // error: no matching constructor for initialization of 'D'

//  D y = 2;            // error: no viable conversion from 'int' to 'D'

    D z{2};             // D(initializer_list<int>)
    assert(D::c == 1);

    D t = {2};          // D(initializer_list<int>)
    assert(D::c == 2);}



struct E {
    static int c;

    int i;

    E             ()         = default; // default constructor
    E             (const E&) = default; // copy constructor
    E& operator = (const E&) = default; // copy assignment operator
    ~E            ()         = default; // destructor

    explicit E (initializer_list<int>) {
        ++c;}};

int E::c = 0;

void test7 () {
//  E x(2);            // error: no matching constructor for initialization of 'E'

//  E y = 2;           // error: no viable conversion from 'int' to 'E'

    E z{2};            // E(initializer_list<int>)
    assert(E::c == 1);

//  E t = {2};         // error: chosen constructor is explicit in copy-initialization
    }



struct F {
    static int c;

    int i;

    F             ()         = default; // default constructor
    F             (const F&) = default; // copy constructor
    F& operator = (const F&) = default; // copy assignment operator
    ~F            ()         = default; // destructor

    F (int) {
        c += 2;}

    F (initializer_list<int>) {
        c += 3;}};

int F::c = 0;

void test8 () {
    F x(2);              // F(int)
    assert(F::c == 2);

    F y = 2;             // F(int)
    assert(&y);
    assert(F::c == 4);

    F z{2};              // F(initializer_list<int>)
    assert(F::c == 7);

    F t = {2};           // F(initializer_list<int>)
    assert(F::c == 10);}



void test9 () {
    vector<int> x(2);                               // vector<int>(int)
    assert(x.size() == 2);
    assert(equal(begin(x), end(x), begin({0, 0})));

//  vector<int> y = 2;                              // error: conversion from 'int' to non-scalar type 'std::vector<int>' requested

    vector<int> z{2};                               // vector<int>(initializer_list<int>)
    assert(z.size() == 1);
    assert(equal(begin(z), end(z), begin({2})));

    vector<int> t = {2};                            // vector<int>(initializer_list<int>)
    assert(t.size() == 1);
    assert(equal(begin(t), end(t), begin({2})));}


template <typename T>
class my_vector {
	private:
		T* _b = nullptr;
		T* _e = nullptr;

	public:
		my_vector () = default;

		size_t size () const {
			return _e - _b;}

	};



#ifdef TEST0
void test0 () {
    const my_vector<int> x;
    assert(x.size() == 0);}
#endif

#ifdef TEST1
void test1 () {
    const my_vector<int> x(3);
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({0, 0, 0})));}
#endif

#ifdef TEST2
void test2 () {
    const my_vector<int> x(3, 2);
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({2, 2, 2})));}
#endif

#ifdef TEST3
void test3 () {
    const initializer_list<int> x = {2, 3, 4};
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));
    const my_vector<int> y = x;
    assert(y.size() == 3);
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}
#endif

#ifdef TEST4
void test4 () {
    my_vector<int> x = {2, 3, 4};
    assert(x[1] == 3);
    x[1] = 5;
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}
#endif

#ifdef TEST5
void test5 () {
    const my_vector<int> x = {2, 3, 4};
    assert(x[1] == 3);
//  x[1] = 5;                                           // error: cannot assign to return value because function 'operator[]' returns a const value
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}
#endif
