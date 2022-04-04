// ----------
// StackT.cpp
// ----------

// http://en.cppreference.com/w/cpp/container/stack

#include <deque>   // deque
#include <list>    // list
#include <stack>   // stack
#include <utility> // !=, <=, >, >=
#include <vector>  // vector

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

template <typename T, typename C = std::deque<T>>
class my_stack {
    friend bool operator == (const my_stack& lhs, const my_stack& rhs) {
        return lhs._c == rhs._c;}

    friend bool operator < (const my_stack& lhs, const my_stack& rhs) {
        return lhs._c < rhs._c;}

    public:
        using container_type  = C;

        using value_type      = typename container_type::value_type;
        using size_type       = typename container_type::size_type;

        using reference       = typename container_type::reference;
        using const_reference = typename container_type::const_reference;

    private:
        container_type _c;

    public:
        my_stack             ()                 = default;
        my_stack             (const my_stack&)  = default;
        ~my_stack            ()                 = default;
        my_stack& operator = (const my_stack&)  = default;

        explicit my_stack (const container_type& c) :
                _c (c)
            {}

        bool empty () const {
            return _c.empty();}

        void pop () {
            _c.pop_back();}

        void push (const_reference v) {
            _c.push_back(v);}

        size_type size () const {
            return _c.size();}

        reference top () {
            return _c.back();}

        const_reference top () const {
            return _c.back();}};

template <typename T>
struct StackFixture : Test {
    using stack_type = T;};

using stack_types =
    Types<
           stack<int>,
        my_stack<int>,
           stack<int, vector<int>>,
        my_stack<int, vector<int>>,
           stack<int, list<int>>,
        my_stack<int, list<int>>>;

#ifdef __APPLE__
    TYPED_TEST_SUITE(StackFixture, stack_types,);
#else
    TYPED_TEST_SUITE(StackFixture, stack_types);
#endif

TYPED_TEST(StackFixture, test0) {
    using stack_type = typename TestFixture::stack_type;
    const stack_type x;       // default constructor
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(), 0u);}

TYPED_TEST(StackFixture, test1) {
    using stack_type = typename TestFixture::stack_type;
    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(), 3u);
    ASSERT_EQ(x.top(),  4);
    const stack_type& r = x;
    ASSERT_EQ(r.top(),  4);}

TYPED_TEST(StackFixture, test2) {
    using stack_type = typename TestFixture::stack_type;
    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);
    x.top() = 5;
    ASSERT_EQ(x.top(), 5);
    const stack_type& r = x;
//  r.top() = 6;             // error: assignment of read-only location '(& r)->std::stack_type::top()'
    ASSERT_EQ(r.top(), 5);}

TYPED_TEST(StackFixture, test3) {
    using stack_type = typename TestFixture::stack_type;
    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);
    x.pop();
    ASSERT_EQ(x.size(), 2u);
    ASSERT_EQ(x.top(),  3);}

TYPED_TEST(StackFixture, test4) {
    using stack_type = typename TestFixture::stack_type;
    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);
    stack_type y = x; // copy     constructor
    ASSERT_EQ(x, y);} // equality operator

TYPED_TEST(StackFixture, test5) {
    using stack_type = typename TestFixture::stack_type;
    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);
    stack_type y;
    x.push(5);
    x.push(6);
    stack_type& z = (x = y); // copy assignment operator
    ASSERT_EQ(x,  y);
    ASSERT_EQ(&x, &z);}
