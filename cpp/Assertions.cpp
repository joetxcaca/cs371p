// --------------
// Assertions.cpp
// --------------

// https://en.cppreference.com/w/cpp/error/assert

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

int cycle_length (int n) {
    assert(n > 0);
    int c = 0;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

void test () {
    assert(cycle_length( 1) == 1);
    assert(cycle_length( 5) == 6);
    assert(cycle_length(10) == 7);}

int main () {
    cout << "Assertions.cpp" << endl;
    test();
    cout << "Done." << endl;
    return 0;}

/*
% clang++ -g -std=c++17 -Wall -Wextra -Wpedantic Assertions.cpp -o Assertions
% ./Assertions
Assertions.cpp
Assertion failed: (c > 0), function cycle_length, file Assertions.cpp, line 21.



Turn OFF assertions at compile time with -DNDEBUG
% clang++ -g -std=c++17 -DNDEBUG -Wall -Wextra -Wpedantic Assertions.cpp -o Assertions
% ./Assertions
Assertions.cpp
Done.
*/
