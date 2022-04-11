// -----------
// Mon, 11 Apr
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
map
iteration
initializations
*/


/*
set is like Java's TreeSet
	keys
	ordered
	keys must be comparable (<)
	unique keys
	find(), only 1 version, read-only
*/

/*
unorderedset is like Java's HashSet
	keys
	unordered
	keys must be hashable
	unique keys
	find(), only 1 version, read-only
*/




/*
map is like Java's TreeMap
	key, value pairs
	ordered keys
	keys must be comparable
	unique keys
	find(), two versions, read-only and read-write (values only)
*/

/*
unorderedmap is like Java's HashMap
	key, value pairs
	unordered
	keys must be hashable
	unique keys
	find(), two versions, read-only and read-write (values only)
*/



void test1 () {
    int i = 0;
    int s = 0;
    while (i != 10) {
        s += i;
        ++i;}
    assert(i == 10);
    assert(s == 45);}

void test2 () {
    int i = 0;
    int s = 0;
    do { // body guaranteed to run at least once
        s += i;
        ++i;}
    while (i != 10);
    assert(i == 10);
    assert(s == 45);}

void test3 () {
    int s = 0;
    for (int i = 0; i != 10; ++i)
        s += i;
//  assert(i == 10);              // error: name lookup of 'i' changed for new ISO 'for' scoping
    assert(s == 45);}

{
int i = 0;
while (i != 10) {
	s += i;
	++i;}
}

void test4 () {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    int s = 0;
    for (int i = 0, j = 0; i != 3; ++i, ++j) // all loop variables have to be the same type
        s += a[i] + b[j];
    assert(s == 27);}

void test5 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int v : a) // for in, for each
        s += v;
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

// what are the requirements on a

{
int* b = begin(a);
int* e = end(a);
while (b != e) { // using b, e as input iterators
	int v = *b;
	s += v;
	++b;}
}

void test6 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int v : a) {
        s += v;
        ++v;}                                   // ?
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test7 () {
    int  a[] = {2, 3, 4};
    int  s   = 0;
    int* b   = begin(a);
    int* e   = end(a);
    while (b != e) {
        int v = *b;
        s += v;
        ++v;                                    // ?
        ++b;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test8 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (auto v : a) {
        s += v;
        ++v;}                                   // ?
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));
    auto [vx, vy, vz] = a;
    assert(vx  == 2);
    assert(vy  == 3);
    assert(vz  == 4);
    assert(&vx != &a[0]);}

void test9 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int& r : a) {
        s += r;
        ++r;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({3, 4, 5})));}

void test10 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (auto& r : a) {
        s += r;
        ++r;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({3, 4, 5})));
    auto& [rx, ry, rz] = a;
    assert(rx  == 3);
    assert(ry  == 4);
    assert(rz  == 5);
    assert(&rx == &a[0]);}

void test11 () {
    list<int> x = {2, 3, 4};
    int       s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test12 () {
    list<int>           x = {2, 3, 4};
    int                 s = 0;
    list<int>::iterator b = begin(x);           // x.begin()
    list<int>::iterator e = end(x);             // x.end()
    while (b != e) {
        list<int>::iterator::value_type v = *b;
        s += v;
        ++b;}
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test13 () {
    set<int> x = {2, 3, 4};
    int      s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test14 () {
    set<int>           x = {2, 3, 4};
    int                s = 0;
    set<int>::iterator b = begin(x);           // x.begin()
    set<int>::iterator e = end(x);             // x.end()
    while (b != e) {
        set<int>::iterator::value_type v = *b;
        s += v;
        ++b;}
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test15 () {
    set<int> x = {2, 3, 4};
    int      s = 0;
//  for (      int& r : x)                              // error: binding reference of type 'int&' to 'const int' discards qualifiers
    for (const int& r : x)
        s += r;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test16 () {
    map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int            s = 0;
    for (pair<char, int> v : x)
        s += v.second;
    assert(s == 9);}

void test17 () {
    map<char, int>           x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int                      s = 0;
    map<char, int>::iterator b = begin(x);                       // x.begin()
    map<char, int>::iterator e = end(x);                         // x.end()
    while (b != e) {
        map<char, int>::iterator::value_type v = *b;
        s += v.second;
        ++b;}
    assert(s == 9);}

void test18 () {
    map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int            s = 0;
//  for (pair<      char, int>& p : x)                 // error: non-const lvalue reference to type 'pair<char, [...]>' cannot bind to a value of unrelated type 'const pair<__key_type, [...]>'
    for (pair<const char, int>& p : x)
        s += p.second;
    assert(s == 9);}

void test19 () {
    ostringstream     out;
    const vector<int> x = {2, 3, 4};
    for (size_t i = 0; i != x.size(); ++i)
        out << x[i] << " \n"[i == (x.size() - 1)];
    assert(out.str() == "2 3 4\n");}






// -------------------
// Initializations.cpp
// -------------------

// http://en.cppreference.com/w/cpp/language/value_initialization
// http://en.cppreference.com/w/cpp/language/initializer_list
// http://en.cppreference.com/w/cpp/utility/initializer_list

#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <vector>           // vector

using namespace std;

void test1 () {
    int i(2);
    assert(i == 2);

    int j = 2;
    assert(j == 2);

    int k{2};
    assert(k == 2);

    int l = {2};
    assert(l == 2);}



void test2 () {
    int i(2.0);
    assert(i == 2);

    int j = 2.0;
    assert(j == 2);

//  int k{2.0};     // error: narrowing conversion of '2.0e+0' from 'double' to 'int'

//  int l = {2.0};  // error: narrowing conversion of '2.0e+0' from 'double' to 'int'
    }



struct A { // a C struct as compared to a C++ one
    int i;
    int j;

    A             ()         = default;   // default constructor
    A             (const A&) = default;   // copy constructor
    A& operator = (const A&) = default;   // copy assignment operator
    ~A            ()         = default;}; // destructor

void test3 () {
//  A x(2, 3);    // error: no matching function for call to 'A::A(int, int)'

    A z{2, 3};    // analogous to initializing an array
    assert(&z);

    A t = {2, 3};
    assert(&t);}


int a[] = {2, 3, 4};


struct B { // C++ struct
    static int c;

    int i;
    int j;

    B             ()         = default; // default constructor
    B             (const B&) = default; // copy constructor
    B& operator = (const B&) = default; // copy assignment operator
    ~B            ()         = default; // destructor

    B (int, int) {
        ++c;}};

int B::c = 0;

void test4 () {
    B x(2, 3);          // B(int, int)
    assert(B::c == 1);

    B z{2, 3};          // B(int, int)
    assert(B::c == 2);

    B t = {2, 3};       // B(int, int)
    assert(B::c == 3);}



struct C {
    static int c;

    int i;
    int j;

    C             ()         = default; // default constructor
    C             (const C&) = default; // copy constructor
    C& operator = (const C&) = default; // copy assignment operator
    ~C            ()         = default; // destructor

    explicit C (int, int) {
        ++c;}};

int C::c = 0;

void test5 () {
    C x(2, 3);         // C(int, int)
    assert(C::c == 1);

    C z{2, 3};         // C(int, int)
    assert(C::c == 2);

//  C t = {2, 3};      // error: converting to 'C' from initializer list would use explicit constructor 'C::C(int, int)'
    }
