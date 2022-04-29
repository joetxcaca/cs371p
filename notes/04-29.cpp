// -----------
// Fri, 29 Apr
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
Shapes2
*/

class Shape {
    friend bool operator == (const Shape& lhs, const Shape& rhs) {
        return (lhs._x == rhs._x) && (lhs._y == rhs._y);}

    friend istream& operator >> (istream& lhs, Shape& rhs) {
        return lhs >> rhs._x >> rhs._y;}

    friend ostream& operator << (ostream& lhs, const Shape& rhs) {
        return lhs << rhs._x << " " << rhs._y;}

    private:
        int _x;
        int _y;

    public:
        Shape (int x, int y) :
                _x (x),
                _y (y)
            {
            }

        Shape (const Shape&) = default;
/*
        Shape (const Shape& rhs) :
                _x (rhs._x),
                _y (rhs._y)
            {}
*/
        ~Shape () = default;
/*
        ~Shape ()
            {}
*/
        Shape& operator = (const Shape&) = default;
/*
        Shape& operator = (const Shape& rhs) {
            _x = rhs._x;
            _y = rhs._y;
            return *this;}
*/
        double area () const {
            return 0;}

        void move (int x, int y) {
            _x = x;
            _y = y;}};

class Circle : public Shape {
    friend bool operator == (const Circle& lhs, const Circle& rhs) {
        return (static_cast<const Shape&>(lhs) == rhs) && (lhs._r == rhs._r);}

    friend istream& operator >> (istream& lhs, Circle& rhs) {
        return lhs >> static_cast<Shape&>(rhs) >> rhs._r;}

    friend ostream& operator << (ostream& lhs, const Circle& rhs) {
        return lhs << static_cast<const Shape&>(rhs) << " " << rhs._r;}

    private:
        int _r;

    public:
        Circle (int x, int y, int r) :
                Shape (x, y),
                _r    (r)
            {}

        Circle (const Circle&) = default;
/*
        Circle (const Circle& rhs) :
                Shape (rhs),
                _r    (rhs._r)
            {}
*/
        ~Circle () = default;
/*
        ~Circle ()
            {}     // implicitly calling ~Shape()
*/
        Circle& operator = (const Circle&) = default;
/*
        Circle& operator = (const Circle& rhs) {
            Shape::operator=(rhs); // this must be statically bound, could be inlined
            _r = rhs._r;
            return *this;}
*/
        double area () const {
            return 3.14 * _r * _r;}

        int radius () const {
            return _r;}};

Life<AbstractCell*> x(...); // heterogeneous, this was not so good

// let's invent Cell, a smart pointer of AbstractCell

Life<Cell> x(...);

#ifdef TEST8
void test8 () {
//  Circle* const p = new Shape(2, 3);         // doesn't compile
    Shape*  const p = new Circle(2, 3, 4);     // S(), C()
    p->move(5, 6);
    assert(p->area() == 0);                    // Shape::area()!!!
//  p->radius();                               // doesn't compile
//  delete p;                                  // illdefined, only Shape::~Shape(), not good
    Circle* const q = static_cast<Circle*>(p);
    assert(q->area()   == 3.14 * 4 * 4);
    assert(q->radius() == 4);
    delete q;}                                 // ~C(), ~S()
#endif

#ifdef TEST9
void test9 () {
    const Shape* const p = new Circle(2, 3, 4);
          Shape* const q = new Circle(2, 3, 5);
//  assert(*p != *q);                                      // illdefined, Shape's operator!=()
//  *q = *p;                                               // illdefined, Shape::operator=()
//  assert(*p == *q);                                      // illdefined
//  delete p;                                              // illdefined
//  delete q;                                              // illdefined
    const Circle* const r = static_cast<const Circle*>(p);
          Circle* const s = static_cast<      Circle*>(q);
    assert(*r != *s); // Shape's operator==, Circle's operator==
    *s = *r;          // Shape::operator=(), Circle::operator=()
    assert(*r == *s);
    delete r;
    delete s;}
#endif

#ifdef TEST10
void test10 () {
//  vector<Circle> x = {Shape(2, 3), Circle(4, 5, 6)}; // error: no matching constructor for initialization of 'vector<Circle>'
    vector<Shape>  x = {Shape(2, 3), Circle(4, 5, 6)};
    assert(x[0].area() == 0);
    assert(x[1].area() == 0);}
#endif

#ifdef TEST11
void test11 () {
    const Circle       a[] = {Circle(2, 3, 4), Circle(5, 6, 7)};
    const Shape* const p   = a; // never use a parent pointer to an ARRAY of children
    assert(p[0].area() == 0);
//  p[1].area();                                                 // illdefined
    }
#endif

#ifdef TEST12
void test12 () {
    istringstream sin("5 6");
    Shape* p = new Circle(2, 3, 4);
    Shape* q = new Circle(5, 6, 7);
    sin >> *p; // Shape's >>
    assert(*p == *q);}
#endif

#ifdef TEST13
void test13 () {
    ostringstream sout;
    Shape* p = new Circle(2, 3, 4);
    sout << *p; // Shape's <<
    assert(sout.str() == "2 3");}
#endif


class Shape {
	public double area ...}

class Circle: public Shape {
	public double area ...}

Circle x(...);
x.area();      // ok

Shape* p = &x;
*p.area();     // doesn't compile
(*p).area();   // compiles, but wrong
p->area();     // compiles, but wrong


/*
in C++,  static  binding is on by default, virtual makes it dynamic binding
in Java, dynamic binding is on by default
*/


class Shape {
	public int move ...
	public virtual double area ...} // turn on dynamic binding

class Circle: public Shape {
	public double area ...}



Circle x(...);
x.area();      // ok

Shape* p = &x;
p->area();     // does the right thing


Shape* p;
if (...)
 	p = new Circle(...);
else
	p = new Triangle(...);
p->move(...);              // statically  bound, but does the right thing
p->area();                 // dynamically bound, does the right thing

/*
what does inlining mean
you can     inline statically  bound code
you can NOT inline dynamically bound code
*/

/*
mark a virtual method inline? yes
*/

/*
just because a method is marked virtual does NOT mean
that ALL calls to the method are dynamically bound
*/

Circle x(...);
x.area();      // statically bound, this could be inlined

Shape* p = &x;
p->area();         // dynamically bound, can NOT inline
p->Circle::area(); // statically  bound, can inline



class Shape {
	public Shape (...) {
		area();           // in a constructor of the parent a virtual method
						  // will run statically, can inline
		...}

	public int move ...
	public virtual double area ... // turn on dynamic binding

	~Shape () {
		area()} // statically bound, can inline


class Circle: public Shape {
	public double area ...}

{
Circle x(...); // S(),  C()
}              // ~C(), ~S()


/*
4 places where virtual methods are statically bound and could be inlined
1. object
2. scope operator
3. a constructor
4. a destructor
*/
