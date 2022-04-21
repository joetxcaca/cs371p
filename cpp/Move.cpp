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

A f () {
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
