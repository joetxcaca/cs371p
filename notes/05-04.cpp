// -----------
// Wed,  4 May
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

/*
by default Java is dynamically bound
by default C++  is statically  bound
*/

struct A {
	void f () {}};

struct B : A {
	void f () {}};

B x;
x.f();    // B::f

A& r = x;
r.f();    // A::f, static binding

// in C++, virtual turns on dynamic binding

struct A {
	virtual void f () {}};

struct B : A {
	void f () {}};

B x;
x.f();    // B::f

A& r = x;
r.f();    // B::f, dynamic binding




class Shape {
    friend bool operator == (const Shape& lhs, const Shape& rhs) {
        return lhs.equals(rhs);}

    friend istream& operator >> (istream& lhs, Shape& rhs) {
        return rhs.read(lhs);}

    friend ostream& operator << (ostream& lhs, const Shape& rhs) {
        return rhs.write(lhs);}

    private:
        int _x;
        int _y;

    protected:
        virtual bool equals (const Shape& rhs) const {
            return (_x == rhs._x) && (_y == rhs._y);}

        virtual istream& read (istream& in) {
            return in >> _x >> _y;}

        virtual ostream& write (ostream& out) const {
            return out << _x << " " << _y;}

    public:
        Shape (int x, int y) :
                _x (x),
                _y (y)
            {}

        Shape             (const Shape&) = default;
        virtual ~Shape    ()             = default;
        Shape& operator = (const Shape&) = default;

        virtual double area () const {
            return 0;}

        void move (int x, int y) {
            _x = x;
            _y = y;}};

class Circle : public Shape {
    private:
        int _r;

    protected:
        bool equals (const Shape& rhs) const override {
            if (const Circle* const p = dynamic_cast<const Circle*>(&rhs))
                return Shape::equals(*p) && (_r == p->_r);
            return false;}

        istream& read (istream& in) override {
            return Shape::read(in) >> _r;}

        ostream& write (ostream& out) const override {
            return Shape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                Shape (x, y),
                _r    (r)
            {}

        Circle             (const Circle&) = default;
        ~Circle            ()              = default;
        Circle& operator = (const Circle&) = default;

        double area () const override {
            return 3.14 * _r * _r;}

        int radius () const {
            return _r;}};

struct A {
	void f (int) {}};

struct B : A {
	void f (int) {}};

B x;
x.f(2); // B::f



struct A {
	void f (int) {}};

struct B : A {
	void g (int) {}};

B x;
x.f(2); // A::f



struct A {
	void f (int) {}};

struct B : A {
	void f (long) {}};

B x;
x.f(2); // B::f

int  i = 2;
long l = i; // ok

long l = 2;
int  i = l; // ok in C++, NOT ok in Java


// way up here
windowupdate (int)

struct A : A' {
	void f (int) {}};

struct B : A {
	void windowupdate (string) {}};

B x;
x.f(2); // doesn't compile!!!, in Java we'd get A::f

int    i = 2;
string s = i; // no



struct A  {
	void f (int) {}};

struct B : A {
	void f (string) {}};

B x;
x.f(2); // doesn't compile

int    i = 2;
string s = i; // no



struct A  {
	void f (int) {}};

struct B : A {
	void f (string) {}};

B x;
x.A::f(2); // ok

int    i = 2;
string s = i; // no



struct A  {
	void f (int) {}};

struct B : A {
	void f (int i) {
		A::f(i)}

	void f (string) {}};

B x;
x.f(2)

int    i = 2;
string s = i; // no



struct A  {
	void f (int) {}};

struct B : A {
	using A::f;

	void f (string) {}};

B x;
x.f(2) // ok

int    i = 2;
string s = i; // no




struct A {
	virtual void f (int) {}};

struct B : A {
	void f (int) {}};

A* p = new B;
p->f(2);      // B::f



struct A {
	virtual void f (int) {}};

struct B : A {
	void g (int) {}};

A* p = new B;
p->f(2);      // A::f



struct A {
	virtual void f (int) {}};

struct B : A {
	void f (long) {}}; // we are NOT overriding A::f!!!!!

A* p = new B;
p->f(2);      // A::f




struct A {
	virtual void f (int) const {}};

struct B : A {
	void f (int) {}};

A* p = new B;
p->f(2);      // A::f


// rule of three

T()
=(T)
~T()

vector
	pointers

shape
	ints

circle
	ints

AC
	int

CC
	<nothing>

FC
	int

Life
	vector<vector<T>>

Cell
	AC*
