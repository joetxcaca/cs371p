// -----------
// Fri,  6 May
// -----------

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
Shapes3
*/

struct A {
	virtual void f (int) {}};

struct B : A {
	void f (int) {}};

struct C : A {}

A* p = new B;
p->f(2);      // B::f



struct A {
	int i;

	A () {} // we can have constructor

	virtual void f (int) = 0; // pure virtual method
	virtual void g (int) {}
	void h (int) {}};         // unusual

void A::f (int) {}

struct B : A {
	void f (int) {}};

struct C : A {} // C would become abstract, because it not define f()

A* p = new B;
p->f(2);      // B::f


/*
consequences of a pure virtual function
1. the parent becomes abstract
2. children must define it OR they become abstract
3. permitted but not required to define in the parent
*/

A x; // no

A* p = new B; // ok

A* q = new A; // no


struct A {
	virtual ~A() = 0};

A::~A() {}

// equivalent to this in Java:

abstract class A {}

/*
auto defined methods
T()
T(T)
=(T)
~T()
*/

/*
consequences of a pure virtual destructor
1. the parent becomes abstract
2. does not apply
3. does not apply
*/




// ------------
// Shapes3H.c++
// ------------

#include <cassert>  // assert
#include <iostream> // cout, endl, istream, ostream
#include <sstream>  // istringstream, ostringstream
#include <utility>  // !=

using namespace std;
using rel_ops::operator!=;

#define TEST4
#define TEST5
#define TEST6
#define TEST7
#define TEST8
#define TEST9
#define TEST11
#define TEST12
#define TEST13

class AbstractShape {
    friend bool operator == (const AbstractShape& lhs, const AbstractShape& rhs) {
        return lhs.equals(rhs);}

    friend istream& operator >> (istream& lhs, AbstractShape& rhs) {
        return rhs.read(lhs);}

    friend ostream& operator << (ostream& lhs, const AbstractShape& rhs) {
        return rhs.write(lhs);}

    private:
        int _x;
        int _y;

    protected:
        AbstractShape& operator = (const AbstractShape&) = default;

        virtual bool     equals (const AbstractShape& rhs) const = 0;
        virtual istream& read   (istream&             in)        = 0;
        virtual ostream& write  (ostream&             out) const = 0;

    public:
        AbstractShape (int x, int y) :
                _x (x),
                _y (y)
            {}

        AbstractShape          (const AbstractShape&) = default;
        virtual ~AbstractShape ()                     = default;

        virtual double         area  () const = 0;
        virtual AbstractShape* clone () const = 0;

        void move (int x, int y) {
            _x = x;
            _y = y;}};

bool AbstractShape::equals (const AbstractShape& rhs) const {
    return (_x == rhs._x) && (_y == rhs._y);}

istream& AbstractShape::read (istream& in) {
    return in >> _x >> _y;}

ostream& AbstractShape::write (ostream& out) const {
    return out << _x << " " << _y;}

class Circle : public AbstractShape {
    private:
        int _r;

    protected:
        bool equals (const AbstractShape& rhs) const override {
            if (const Circle* const p = dynamic_cast<const Circle*>(&rhs))
                return AbstractShape::equals(*p) && (_r == p->_r);
            return false;}

        istream& read (istream& in) override {
            return AbstractShape::read(in) >> _r;}

        ostream& write (ostream& out) const override {
            return AbstractShape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                AbstractShape (x, y),
                _r            (r)
            {}

        Circle             (const Circle&) = default;
        ~Circle            ()              = default;
        Circle& operator = (const Circle&) = default;

        double area () const override {
            return 3.14 * _r * _r;}

        Circle* clone () const override {
            return new Circle(*this);}

        int radius () const {
            return _r;}};

/*
#ifdef TEST0
void test0 () {
    AbstractShape x(2, 3);
    x.move(4, 5);
    assert(x.area() == 0);
//  x.radius();            // doesn't compile
    }
#endif

#ifdef TEST1
void test1 () {
    const AbstractShape x(2, 3);
          AbstractShape y(4, 5);
    assert(x != y);
    y = x;
    assert(x == y);}
#endif

#ifdef TEST2
void test2 () {
    istringstream sin("4 5");
    AbstractShape x(2, 3);
    AbstractShape y(4, 5);
    sin >> x;
    assert(x == y);}
#endif

#ifdef TEST3
void test3 () {
    ostringstream sout;
    AbstractShape x(2, 3);
    sout << x;
    assert(sout.str() == "2 3");}
#endif
*/

#ifdef TEST4
void test4 () {
    Circle x(2, 3, 4);
    x.move(5, 6);
    assert(x.area()   == 3.14 * 4 * 4);
    assert(x.radius() == 4);}
#endif

#ifdef TEST5
void test5 () {
    const Circle x(2, 3, 4);
          Circle y(2, 3, 5);
    assert(x != y);
    y = x;
    assert(x == y);}
#endif

#ifdef TEST6
void test6 () {
    istringstream sin("4 5 6");
    Circle x(2, 3, 4);
    Circle y(4, 5, 6);
    sin >> x;
    assert(x == y);}
#endif

#ifdef TEST7
void test7 () {
    ostringstream sout;
    Circle x(2, 3, 4);
    sout << x;
    assert(sout.str() == "2 3 4");}
#endif

#ifdef TEST8
void test8 () {
//  Circle*        const p = new AbstractShape(2, 3); // doesn't compile
    AbstractShape* const p = new Circle(2, 3, 4);
    p->move(5, 6);
    assert(p->area() == 3.14 * 4 * 4);
//  p->radius();                                      // doesn't compile
    if (Circle* const q = dynamic_cast<Circle*>(p))
        assert(q->radius() == 4);
    try {
        Circle& r = dynamic_cast<Circle&>(*p);
        assert(r.radius() == 4);}
    catch (const bad_cast& e) {
        assert(false);}
    delete p;}
#endif

AS
	virtual AS* clone () const = 0;

C
	C* clone () const {           // virtual return types are covariant
		return new Circle(*this)}

Circle* p = new Circle(...);
Circle* q = p->clone();

#ifdef TEST9
void test9 () {
    const AbstractShape* const p = new Square(2, 3, 4, 5);
    const AbstractShape*       q = new Circle(2, 3, 5);
    assert(*p != *q);                                   // == call equals, and we made equals virtual
//  *q = *p;                                            // error: no viable overloaded '='
    delete q;
    q = p->clone();
    assert(*p == *q);
    delete p;
    delete q;}
#endif

/*
#ifdef TEST10
void test10 () {
//  const Circle        a[] = {AbstractShape(2, 3), Circle(4, 5, 6)}; // doesn't compile
    const AbstractShape a[] = {AbstractShape(2, 3), Circle(4, 5, 6)};
    assert(a[0].area() == 0);
    assert(a[1].area() == 0);}
#endif
*/

#ifdef TEST11
void test11 () {
    const Circle a[] = {Circle(2, 3, 4), Circle(5, 6, 7)};
    assert(a[0].area() == 3.14 * 4 * 4);
    assert(a[1].area() == 3.14 * 7 * 7);
    const AbstractShape* const p = a;
    assert(p[0].area() == 3.14 * 4 * 4);
//  p[1].area();                                           // illdefined
    }
#endif

#ifdef TEST12
void test12 () {
    istringstream sin("5 6 7");
    AbstractShape* p = new Circle(2, 3, 4);
    AbstractShape* q = new Circle(5, 6, 7);
    sin >> *p;
    assert(*p == *q);}
#endif

#ifdef TEST13
void test13 () {
    ostringstream sout;
    AbstractShape* p = new Circle(2, 3, 4);
    sout << *p;
    assert(sout.str() == "2 3 4");}
#endif

int main () {
    cout << "Shapes3.c++" << endl;
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test11();
    test12();
    test13();
    /*
    int n;
    cin >> n;
    switch (n) {
        #ifdef TEST4
        case 4:
            test4();
            break;
        #endif

        #ifdef TEST5
        case 5:
            test5();
            break;
        #endif

        #ifdef TEST6
        case 6:
            test6();
            break;
        #endif

        #ifdef TEST7
        case 7:
            test7();
            break;
        #endif

        #ifdef TEST8
        case 8:
            test8();
            break;
        #endif

        #ifdef TEST9
        case 9:
            test9();
            break;
        #endif

        #ifdef TEST11
        case 11:
            test11();
            break;
        #endif

        #ifdef TEST12
        case 12:
            test12();
            break;
        #endif

        #ifdef TEST13
        case 13:
            test13();
            break;
        #endif

        default:
            assert(false);}
    */
    cout << "Done." << endl;
    return 0;}

// Cell is called a smart pointer

template <typename T>
class Handle {
    friend bool operator == (const Handle& lhs, const Handle& rhs) {
        if ((lhs.get() == nullptr) && (rhs.get() == nullptr))
            return true;
        if ((lhs.get() == nullptr) || (rhs.get() == nullptr))
            return false;
        return (*lhs.get() == *rhs.get());}

    public:
        typedef T                 value_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

    private:
        pointer _p = nullptr;

    protected:
        pointer get () {
            return _p;}

        const_pointer get () const {
            return _p;}

    public:
        Handle () = default;

Cell  x  = new ConwayCell(...);
Cell  x2 = x;
Cell  t  = new FredkinCell(...);
x = t;

Shape y  = new Circle(...);
Shape y2 = y;
Shape z  = new Triangle(...);
y = z;

        Handle (pointer p) {
            _p = p;}

        Handle (const Handle& rhs) {
            if (rhs._p != nullptr)
                _p = rhs._p->clone();}

        Handle& operator = (const Handle& rhs) {
            if (this == &rhs)
                return *this;
            Handle that(rhs);
            swap(that);
            return *this;}

        ~Handle () {
            delete _p;}

        void swap (Handle& rhs) {
            std::swap(_p, rhs._p);}};

struct Cell : Handle<AbstractCell> {
	...}

struct Shape : Handle<AbstractShape> {
    Shape () = default;

    Shape (AbstractShape* p) :
            Handle<AbstractShape> (p)
        {}

    Shape             (const Shape&) = default;
    ~Shape            ()             = default;
    Shape& operator = (const Shape&) = default;

    double area () const {
        assert(get() != nullptr);
        return get()->area();}

    void move (int x, int y) {
        assert(get() != nullptr);
        return get()->move(x, y);}};
