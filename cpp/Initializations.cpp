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



struct A {
    int i;

    A             ()         = default;   // default constructor
    A             (const A&) = default;   // copy constructor
    A& operator = (const A&) = default;   // copy assignment operator
    ~A            ()         = default;}; // destructor

void test3 () {
//  A x(2);      // error: no matching constructor for initialization of 'A'

//  A y = 2;     // error: no viable conversion from 'int' to 'A'

    A z{2};
    assert(&z);

    A t = {2};
    assert(&t);}



struct B {
    static int c;

    int i;

    B             ()         = default; // default constructor
    B             (const B&) = default; // copy constructor
    B& operator = (const B&) = default; // copy assignment operator
    ~B            ()         = default; // destructor

    B (int) {
        ++c;}};

int B::c = 0;

void test4 () {
    B x(2);             // B(int)
    assert(B::c == 1);

    B y = 2;
    assert(&y);
    assert(B::c == 2);  // B(int)

    B z{2}   ;          // B(int)
    assert(B::c == 3);

    B t = {2};          // B(int)
    assert(B::c == 4);}



struct C {
    static int c;

    int i;

    C             ()         = default; // default constructor
    C             (const C&) = default; // copy constructor
    C& operator = (const C&) = default; // copy assignment operator
    ~C            ()         = default; // destructor

    explicit C (int) {
        ++c;}};

int C::c = 0;

void test5 () {
    C x(2);            // C(int)
    assert(C::c == 1);

//  C y = 2;           // error: no viable conversion from 'int' to 'C'

    C z{2};            // C(int)
    assert(C::c == 2);

//  C t = {2};         // error: chosen constructor is explicit in copy-initialization
    }



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



int main () {
    cout << "Initializations.cpp" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    cout << "Done." << endl;
    return 0;}
