// -----------
// Mon, 25 Apr
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
Life
Shapes
Circles
*/

vector<AbstraceCell> x(10, ConwayCell(...)); // no

vector<AbstractCell*> x(10, new ConwayCell(...)); // no

vector<AbstractCell*> x(10);
fill(begin(x), end(x), new ConwayCell(...)); // no!

vector<AbstractCell*> x(10);
for (int i = 0; i != 10; ++i)
	x[i] = new ConwayCell(...);

vector<AbstractCell*> y(x); // this is crazy, because vectors now point to the same set of cells

vector<AbstractCell*> x(10);
for (int i = 0; i != 10; ++i)
	x[i] = new ConwayCell(...);

vector<AbstractCell*> y(20);
for (int i = 0; i != 20; ++i)
	y[i] = new FredkinCell(...);

x = y; // this is more crazy, memory leak!!!

AbstractCell
	ConwayCell
	FredkinCell

Cell, a smart pointer

{
Cell x = new ConwayCell(...);  // I am calling new
Cell y(x);                     // correctly makes a copy of the ConwayCell

Cell z = new FredkinCell(...);
x = z;                         // correctly deletes the ConwayCell and makes a copy of the FredkinCell
}                              // I am NOT calling delete

/*
Cell is to AbstractCell*
like
vector is to array
*/

vector<ConwayCell> x(10, ConwayCell(...)); // I never call new!!!

class Cell {
	private:
		AbstractCell* _p;

	public:
		Cell (AbstractCell* p) // NOT explicit
			_p = p;}

Cell f () {
	Cell x = new ConwayCell(...); // AC() CC() C()
	return x;
	}

Cell y = f(); // AC() CC() C()

y = f(); // move assignemt

vector<AbstractCell*> x(10, new ConwayCell(...)); // crazy

vector<Cell> x(10, Cell(new ConwayCell(...))); // AC(), CC(), C(), V()

vector<Cell> x(10, new ConwayCell(...)); // AC(), CC(), C(), V()


Life<ConwayCell> ...
Life<FredkinCell>...
Life<Cell> ...



class Shape {
    friend bool operator == (const Shape& lhs, const Shape& rhs) {
        return (lhs._x == rhs._x) && (lhs._y == rhs._y);}

    friend istream& operator >> (istream& lhs, Shape& rhs) {
        return lhs >> rhs._x >> rhs._y;}

    friend ostream& operator << (ostream& lhs, const Shape& rhs) {
        return lhs << rhs._x << " " << rhs._y;}

    public:
        int _x;
        int _y;

    public:
        Shape (int x, int y) :
                _x (x),
                _y (y)
            {}

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


#ifdef TEST0
void test0 () {
    Shape x(2, 3);
    x.move(4, 5);
    assert(x.area() == 0);
//  x.radius();            // doesn't compile
    }
#endif

#ifdef TEST1
void test1 () {
    const Shape x(2, 3);
          Shape y(4, 5);
    assert(x != y);
    y = x;
    assert(x == y);}
#endif

#ifdef TEST2
void test2 () {
    istringstream sin("4 5");
    Shape x(2, 3);
    Shape y(4, 5);
    sin >> x;
    assert(x == y);}
#endif

#ifdef TEST3
void test3 () {
    ostringstream sout;
    Shape x(2, 3);
    sout << x;
    assert(sout.str() == "2 3");}
#endif


class Circle : public Shape {
	private:
		int _r;

	public:
		Circle (int x, int y, int r) :
			// obligated to call the parent constructor
			_r (r)
			{}

		// don't need move
		// do need area
		// do need radius

#ifdef TEST4
void test4 () {
    Circle x(2, 3, 4); // S(), C()
    x.move(5, 6);
    assert(x.area()   == 3.14 * 4 * 4);
    assert(x.radius() == 4);}
#endif
