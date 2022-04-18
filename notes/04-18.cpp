// -----------
// Mon, 18 Apr
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
function overloading
move
*/

// -----------------------
// FunctionOverloading.cpp
// -----------------------

// https://www.cplusplus.com/doc/tutorial/functions2/

// ad-hoc compile-time polymorphism

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <iostream> // cout, endl
#include <string>   // string

using namespace std;

string f1 (int) {              // l-value or r-value
    return "f1(int)";}

//string f1 (const int) {      // error: redefinition of "string f1(int)"
//    return "f1(const int)";}

void test1 () {
    int       i  = 2;
    const int ci = 3;
    assert(f1(i)  == "f1(int)");
    assert(f1(ci) == "f1(int)");
    assert(f1(4)  == "f1(int)");}



string f2 (int&) {      // non-const l-value
    return "f2(int&)";}

void test2 () {
    int       i  = 2;
    const int ci = 3;
    assert(f2(i)  == "f2(int&)");
//  f2(ci);                       // error: no matching function for call to 'f2'
//  f2(4);                        // error: no matching function for call to 'f2'
    assert(ci);
    }



string f3 (const int&) {      // l-value or r-value
    return "f3(const int&)";}

void test3 () {
    int       i  = 2;
    const int ci = 3;
    assert(f3(i)  == "f3(const int&)");
    assert(f3(ci) == "f3(const int&)");
    assert(f3(4)  == "f3(const int&)");}



string f4 (int&&) {      // r-value
    return "f4(int&&)";}

void test4 () {
    int       i  = 2;
    const int ci = 3;
//  assert(f4(i)  == "f4(int&&)");  // error: no matching function for call to 'f4'
//  assert(f4(ci) == "f4(int&&)");  // error: no matching function for call to 'f4'
    assert(f4(4)  == "f4(int&&)");
    assert(i);
    assert(ci);}



string f5 (int&) {            // non-const l-value
    return "f5(int&)";}

string f5 (const int&) {      // const l-value or r-value
    return "f5(const int&)";}

void test5 () {
    int       i  = 2;
    const int ci = 3;
    assert(f5(i)  == "f5(int&)");
    assert(f5(ci) == "f5(const int&)");
    assert(f5(4)  == "f5(const int&)");}



string f6 (int&) {       // non-const l-value
    return "f6(int&)";}

string f6 (int&&) {      // r-value
    return "f6(int&&)";}

void test6 () {
    int       i  = 2;
    const int ci = 3;
    assert(f6(i)  == "f6(int&)");
//  f6(ci);                         // error: no matching function for call to 'f6'
    assert(f6(4)  == "f6(int&&)");
    assert(ci);}



string f7 (const int&) {      // l-value
    return "f7(const int&)";}

string f7 (int&&) {           // r-value
    return "f7(int&&)";}

void test7 () {
    int       i  = 2;
    const int ci = 3;
    assert(f7(i)  == "f7(const int&)");
    assert(f7(ci) == "f7(const int&)");
    assert(f7(4)  == "f7(int&&)");}



string f8 (int&) {            // non-const l-value
    return "f8(int&)";}

string f8 (const int&) {      // const l-value
    return "f8(const int&)";}

string f8 (int&&) {           // r-value
    return "f8(int&&)";}

void test8 () {
    int       i  = 2;
    const int ci = 3;
    assert(f8(i)  == "f8(int&)");
    assert(f8(ci) == "f8(const int&)");
    assert(f8(4)  == "f8(int&&)");}

int main () {
    cout << "FunctionOverloading.cpp" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    cout << "Done." << endl;
    return 0;}


vector<int> f () {
	...}

vector<int> x(10, 2);
vector<int> y(20, 3);

x = y;

x = f();

vector (const vector& rhs) {...} // copy constructor

vector (vector&& rhs) {...} // move constructor

vector& operator = (const vector& rhs) {...} // copy assignment

vector& operator = (vector&& rhs) {...} // move assignment

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

        my_vector (const my_vector& rhs) {
            if (rhs.size() != 0) {
                _b = new T[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}}

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

vector<int> x(10, 2);
x = x;
