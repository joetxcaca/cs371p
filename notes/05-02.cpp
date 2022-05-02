// -----------
// Mon,  2 May
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

/*
compile time casts
	const_cast
	reinterprest_cast
	static_cast

run time casts
	dynamic_cast
*/

#ifdef TEST8
void test8 () {
//  Circle* const p = new Shape(2, 3);              // doesn't compile
    Shape*  const p = new Triangle(2, 3, 4);
    p->move(5, 6);
    assert(p->area() == 3.14 * 4 * 4);              // mark area virtual in shape
//  p->radius();                                    // doesn't compile
    if (Circle* const q = dynamic_cast<Circle*>(p))
        assert(q->radius() == 4);
    try {
        Circle& r = dynamic_cast<Circle&>(*p);
        assert(r.radius() == 4);}
    catch (const bad_cast& e) {
        assert(false);}
    delete p;}
#endif

class Shape {
	friend ... operator ==
		call equals

	protected:
		virtual ... equals (const Shape& rhs)

class Circle {
	// I no longer need ==

	protected
		...equals (const Shape& rhs)
			// needs to call Shape::equals
			// needs dynamic_cast
	}

#ifdef TEST9
void test9 () {
    const Shape* const p = new Circle(2, 3, 4);
          Shape* const q = new Circle(2, 3, 5);
    assert(*p != *q);
//  *q = *p;                                                    // illdefined
    if (const Circle* const r = dynamic_cast<const Circle*>(p))
        if (Circle* const s = dynamic_cast<Circle*>(q)) {
            assert(*r != *s);
            *s = *r;
            assert(*r == *s);}
    delete p;
    delete q;}
#endif

#ifdef TEST10
void test10 () {
    istringstream sin("5 6 7");
    Shape* p = new Circle(2, 3, 4);
    Shape* q = new Circle(5, 6, 7);
    sin >> *p;
    assert(*p == *q);}
#endif

#ifdef TEST11
void test11 () {
    ostringstream sout;
    Shape* p = new Circle(2, 3, 4);
    sout << *p;
    assert(sout.str() == "2 3 4");}
#endif
