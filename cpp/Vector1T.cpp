// ------------
// Vector1T.cpp
// ------------

// http://en.cppreference.com/w/cpp/container/vector

#include <algorithm>        // copy, equal, fill
#include <cassert>          // assert
#include <cstddef>          // ptrdiff_t, size_t
#include <initializer_list> // initializer_list
#include <vector>           // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename T>
class my_vector {
    public:
        using value_type      = T;

        using size_type       = size_t;
        using difference_type = ptrdiff_t;

        using pointer         = value_type*;
        using const_pointer   = const value_type*;

        using reference       = value_type&;
        using const_reference = const value_type&;

        using iterator        = pointer;
        using const_iterator  = const_pointer;

    private:
        pointer _b = nullptr;
        pointer _e = nullptr;

    public:
        my_vector () = default;

        explicit my_vector (size_t s) :
                my_vector(s, T())
            {}

        my_vector (size_type s, const_reference v) {
            if (s != 0) {
                _b = new value_type[s];
                _e = _b + s;
                fill(begin(), end(), v);}}

        my_vector (initializer_list<T> rhs) {
            if (rhs.size() != 0) {
                _b = new value_type[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}}

        my_vector             (const my_vector&) = delete;
        my_vector& operator = (const my_vector&) = delete;

        ~my_vector () {
            delete [] _b;}

        reference operator [] (size_type i) {
            assert(i < size());
            return _b[i];}

        const_reference operator [] (size_type i) const {
            return (*const_cast<my_vector*>(this))[i];}

        iterator begin () {
            return _b;}

        const_iterator begin () const {
            return const_cast<my_vector*>(this)->begin();}

        iterator end () {
            return _e;}

        const_iterator end () const {
            return const_cast<my_vector*>(this)->end();}

        size_type size () const {
            return _e - _b;}};

template <typename T>
struct VectorFixture : Test {
    using vector_type = T;};

using
    vector_types =
    Types<
        vector<int>,
        my_vector<int>>;

#ifdef __APPLE__
    TYPED_TEST_SUITE(VectorFixture, vector_types,);
#else
    TYPED_TEST_SUITE(VectorFixture, vector_types);
#endif

TYPED_TEST(VectorFixture, test0) {
    using vector_type = typename TestFixture::vector_type;
    const vector_type x;
    ASSERT_EQ(x.size(), 0u);}

TYPED_TEST(VectorFixture, test1) {
    using vector_type = typename TestFixture::vector_type;
    const vector_type x(3);
    ASSERT_EQ(x.size(), 3u);
    ASSERT_TRUE(equal(begin(x), end(x), begin({0, 0, 0})));}

TYPED_TEST(VectorFixture, test2) {
    using vector_type = typename TestFixture::vector_type;
    const vector_type x(3, 2);
    ASSERT_EQ(x.size(), 3u);
    ASSERT_TRUE(equal(begin(x), end(x), begin({2, 2, 2})));}

TYPED_TEST(VectorFixture, test3) {
    using vector_type = typename TestFixture::vector_type;
    const initializer_list<int> x = {2, 3, 4};
    ASSERT_EQ(x.size(), 3u);
    ASSERT_TRUE(equal(begin(x), end(x), begin({2, 3, 4})));
    const vector_type y = x;
    ASSERT_EQ(y.size(), 3u);
    ASSERT_TRUE(equal(begin(y), end(y), begin({2, 3, 4})));}

TYPED_TEST(VectorFixture, test4) {
    using vector_type = typename TestFixture::vector_type;
    vector_type x = {2, 3, 4};
    ASSERT_EQ(x[1], 3);
    x[1] = 5;
    ASSERT_TRUE(equal(begin(x), end(x), begin({2, 5, 4})));}

TYPED_TEST(VectorFixture, test5) {
    using vector_type = typename TestFixture::vector_type;
    const vector_type x = {2, 3, 4};
    ASSERT_EQ(x[1], 3);
    // x[1] = 5;                                             // error: cannot assign to return value because function 'operator[]' returns a const value
    ASSERT_TRUE(equal(begin(x), end(x), begin({2, 3, 4})));}
