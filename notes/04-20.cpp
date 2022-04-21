// -----------
// Wed, 20 Apr
// -----------

/*
Paper 13. What Happens to Us Does Not Happen to Most of You
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
copy assignment
move
move constructor
move assignment
*/



template <typename T>
class my_vector {
    friend bool operator == (const my_vector& lhs, const my_vector& rhs) {
        return (lhs.size() == rhs.size()) && equal(lhs.begin(), lhs.end(), rhs.begin());}

    private:
        T* _b = nullptr;
        T* _e = nullptr;

    public:
        my_vector () = default;

        explicit my_vector (size_t s) :
                my_vector(s, T())
            {}

        my_vector (size_t s, const T& v) {
            if (s != 0) {
                _b = new T[s];
                _e = _b + s;
                fill(begin(), end(), v);}}

        my_vector (initializer_list<T> rhs) {
            if (rhs.size() != 0) {
                _b = new T[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}}

        my_vector (const my_vector& rhs) { // copy constructor
            if (rhs.size() != 0) {
                _b = new T[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}}

        my_vector (my_vector&& rhs) { // move constructor

/*
x = y;
*/

/*
rhs has data that we want
we have data that we don't want
rhs is about to die
*/

        my_vector& operator = (const my_vector& rhs) { // copy assignment
        	my_vector tmp(rhs);
			swap(_b, tmp._b);
			swap(_e, tmp._e);
			return *this;}
/*
        my_vector& operator = (const my_vector& rhs) {
			if (*this ==  rhs) // O(n), no!
        	if ( this == &rhs) // O(1)
        		return *this;
        	delete [] _b;
        	_b = nullptr;
        	_e = nullptr;
            if (rhs.size() != 0) {
                _b = new T[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}}
			return *this;}
*/

        my_vector& operator = (my_vector&& rhs) { // move assignment

        ~my_vector () {
            delete [] _b;}

       T& operator [] (size_t i) {
            assert(i < size());
            return _b[i];}

        const T& operator [] (size_t i) const {
            return (*const_cast<my_vector*>(this))[i];}

        T* begin () {
            return _b;}

        const T* begin () const {
            return const_cast<my_vector*>(this)->begin();}

        T* end () {
            return _e;}

        const T* end () const {
            return const_cast<my_vector*>(this)->end();}

        size_t size () const {
            return _e - _b;}

        void swap (my_vector& rhs) {
            std::swap(_b, rhs._b);
            std::swap(_e, rhs._e);}};


vector<int> f () {
	...
	return vector<int>(...);}

vector<int> x(...);
vector<int> y(...);

x = y; // l-value

vs.

x = f(); // r-value




// --------
// Move.c++
// --------

// https://en.cppreference.com/w/cpp/utility/move

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // move
#include <vector>   // vector

using namespace std;

struct A {
    A (int) {
        cout << "A(int) ";}      // int constructor

    A (const A&) {               // copy constructor
        cout << "A(const A&) ";}

    A& operator = (const A&) {   // copy assignment
        cout << "=(const A&) ";
        return *this;}};

void test1 () {
    cout << "1. A copy constructor: ";
    A x(2);                            // A(int)
    A y = x;}                          // A(const A&)

void test2 () {
    cout << "2. A copy assignment: ";
    A x(2);                            // A(int)
    A y(3);                            // A(int)
    y = x;}                            // =(const A&)

A f () { // return by value, by copy
    A x(2);
    return x;}

void test3 () {
    cout << "3. A copy elision: ";
    A y = f();                         // A(int)
    assert(&y);}

void test4 () {
    cout << "4. A copy constructor: ";
    vector<A> v;
    v.push_back(f());}                 // A(int), A(const A&)

void test5 () {
    cout << "5. A copy assignment: ";
    A y(3);                            // A(int)
    y = f();}                          // A(int), =(const A&)



struct B {
    B (int) {                    // int constructor
        cout << "B(int) ";}

    B (const B&) {               // copy constructor
        cout << "B(const B&) ";}

    B (B&&) {                    // move constructor
        cout << "B(B&&) ";}

    B& operator = (const B&) {   // copy assignment
        cout << "=(const B&) ";
        return *this;}

    B& operator = (B&&) {        // move assignment
        cout << "=(B&&) ";
        return *this;}};

/*
the only thing that move() does is to CAST from an l-value to an r-value!!!
*/

void test6 () {
    cout << "6. B move constructor: ";
    B x(2);                            // B(int)
    B y = move(x);}                    // B(&&)

void test7 () {
    cout << "7. B move assignment: ";
    B x(2);                            // B(int)
    B y(3);                            // B(int)
    y = move(x);}                      // =(B&&)

B g () {
    B x(2);
    return x;}

void test8 () {
    cout << "8. B move elision: ";
    B y = g();                         // B(int)
    assert(&y);}

void test9 () {
    cout << "9. B move constructor: ";
    vector<B> x;
    x.push_back(g());}                 // B(int), B(B&&)

void test10 () {
    cout << "10. B move assignment: ";
    B y(3);                            // B(int)
    y = g();}                          // B(int), =(B&&)



int main () {
    cout << "Move.c++" << endl;
    test1();
    cout << endl;

    test2();
    cout << endl;

    test3();
    cout << endl;

    test4();
    cout << endl;

    test5();
    cout << endl << endl;

    test6();
    cout << endl;

    test7();
    cout << endl;

    test8();
    cout << endl;

    test9();
    cout << endl;

    test10();
    cout << endl;
    cout << "Done." << endl;
    return 0;}

/*
Move.c++
1. A copy constructor: A(int) A(const A&)
2. A copy assignment: A(int) A(int) =(const A&)
3. A copy elision: A(int)
4. A copy constructor: A(int) A(const A&)
5. A copy assignment: A(int) A(int) =(const A&)

6. B move constructor: B(int) B(B&&)
7. B move assignment: B(int) B(int) =(B&&)
8. B move elision: B(int)
9. B move constructor: B(int) B(B&&)
10. B move assignment: B(int) B(int) =(B&&)
Done.
*/



/*
1. define <
2. move constr
3. move assgn
*/


#ifdef TEST9
void test9 () {
    const my_vector<int> x(10, 2);
    const my_vector<int> y(10, 2);
    const my_vector<int> z(10, 3);
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(x != z);
    assert(x <  z);
    assert(z >  x);}
#endif

#ifdef TEST10
void test10 () {
    my_vector<int>       x(10, 2);
    int*                 b = begin(x);
    const my_vector<int> y = move(x);
    assert(x.size() ==  0);
    assert(y.size() == 10);
    assert(b        == begin(y));}
#endif

#ifdef TEST11
void test11 () {
    my_vector<int> x(20, 3);
    int*           b = begin(x);
    my_vector<int> y(10, 2);
    y = move(x);
    assert(x.size() ==  0);
    assert(y.size() == 20);
    assert(b        == begin(y));}
#endif
