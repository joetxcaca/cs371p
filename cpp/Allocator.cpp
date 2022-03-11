// -------------
// Allocator.cpp
// -------------

// http://en.cppreference.com/w/cpp/memory/allocator

#include <algorithm> // count
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <memory>    // allocator, allocator_traits

using namespace std;

void test () {
    using allocator_type        = allocator<int>;
    using allocator_traits_type = allocator_traits<allocator_type>;
    using value_type            = allocator_traits_type::value_type;
    using size_type             = allocator_traits_type::size_type;
    using pointer               = allocator_traits_type::pointer;

    allocator_type   x;
    const size_type  s = 10;
    const pointer    b = allocator_traits_type::allocate(x, s);
    const pointer    e = b + s;
    const value_type v = 2;
    pointer p = b;
    while (p != e) {
        allocator_traits_type::construct(x, p, v);
        ++p;}
    assert(count(b, e, v) == s);
    p = b;
    while (p != e) {
        allocator_traits_type::destroy(x, p);
        ++p;}
    allocator_traits_type::deallocate(x, b, s);}

int main () {
    cout << "Allocator.cpp" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
