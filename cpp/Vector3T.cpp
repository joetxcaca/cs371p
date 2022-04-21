// ------------
// Vector3T.cpp
// ------------

// http://en.cppreference.com/w/cpp/container/vector

#include <algorithm>        // copy, equal, fill, lexicographical_compare, swap
#include <cstddef>          // ptrdiff_t, size_t
#include <initializer_list> // initializer_list
#include <utility>          // !=, <=, >, >=, move
#include <vector>           // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

using rel_ops::operator!=;
using rel_ops::operator<=;
using rel_ops::operator>;
using rel_ops::operator>=;

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

template <typename T>
class my_vector {
    friend bool operator == (const my_vector& lhs, const my_vector& rhs) {
        return (lhs.size() == rhs.size()) && equal(lhs.begin(), lhs.end(), rhs.begin());}

    friend bool operator < (const my_vector& lhs, const my_vector& rhs) {
        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

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

        my_vector (const my_vector& rhs) {
            if (rhs.size() != 0) {
                _b = new value_type[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}}

        my_vector (my_vector&& rhs) {
            swap(rhs);}

        my_vector& operator = (const my_vector& rhs) {
            if (this == &rhs)
                return *this;
            my_vector that(rhs);
            swap(that);
            return *this;}

        my_vector& operator = (my_vector&& rhs) {
            if (this == &rhs)
                return *this;
            my_vector that(move(rhs));
            swap(that);
            return *this;}

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
            return _e - _b;}

        void swap (my_vector& rhs) {
            std::swap(_b, rhs._b);
            std::swap(_e, rhs._e);}};

template <typename T>
struct VectorFixture : Test {
    using vector_type = T;
    using iterator    = typename vector_type::iterator;};

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

TYPED_TEST(VectorFixture, test6) {
    using vector_type = typename TestFixture::vector_type;
    const vector_type x(10, 2);
    const vector_type y = x;
    ASSERT_NE(&x[0],      &y[0]);
    ASSERT_NE(&*begin(x), &*begin(y));
    ASSERT_EQ(x,          y);}

TYPED_TEST(VectorFixture, test7) {
    using vector_type = typename TestFixture::vector_type;
    const vector_type x(10, 2);
    vector_type       y(20, 3);
    y = x;
    ASSERT_EQ(y[1],       2);
    ASSERT_NE(&x[0],      &y[0]);
    ASSERT_NE(&*begin(x), &*begin(y));
    ASSERT_EQ(x,          y);}

TYPED_TEST(VectorFixture, test8) {
    using vector_type = typename TestFixture::vector_type;
    const vector_type x(20, 3);
    vector_type       y(10, 2);
    y = x;
    ASSERT_EQ(y[1],       3);
    ASSERT_NE(&x[0],      &y[0]);
    ASSERT_NE(&*begin(x), &*begin(y));
    ASSERT_EQ(x,          y);}

TYPED_TEST(VectorFixture, test9) {
    using vector_type = typename TestFixture::vector_type;
    const vector_type x(10, 2);
    const vector_type y(10, 2);
    const vector_type z(10, 3);
    ASSERT_EQ(x, y);
    ASSERT_NE(x, z);
    ASSERT_LT(x, z);
    ASSERT_LE(x, y);
    ASSERT_GT(z, x);
    ASSERT_GE(x, y);}

TYPED_TEST(VectorFixture, test10) {
    using vector_type = typename TestFixture::vector_type;
    using iterator    = typename TestFixture::iterator;
    vector_type       x(10, 2);
    iterator          b = begin(x);
    const vector_type y = move(x);
    ASSERT_EQ(x.size(),  0u);
    ASSERT_EQ(y.size(), 10u);
    ASSERT_EQ(b,        begin(y));}

TYPED_TEST(VectorFixture, test11) {
    using vector_type = typename TestFixture::vector_type;
    using iterator    = typename TestFixture::iterator;
    vector_type x(20, 3);
    iterator    b = begin(x);
    vector_type y(10, 2);
    y = move(x);
    ASSERT_EQ(x.size(),  0u);
    ASSERT_EQ(y.size(), 20u);
    ASSERT_EQ(b,        begin(y));}
