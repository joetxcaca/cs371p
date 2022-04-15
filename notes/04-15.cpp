// -----------
// Fri, 15 Apr
// -----------

/*
Paper #11: More getters and setters
remember to go to Perusall THROUGH Canvas
*/

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
vector copy constructor
vector copy assignment
*/



struct Ziwen {}

Ziwen()
Ziwen(const Ziwen&)
~Ziwen()
=(const Ziwen&)

template <typename T>
class my_vector {
	 friend bool operator == (...)
     private:
        T* _b = nullptr;
        T* _e = nullptr;

    public:
        my_vector () = default;

        explicit my_vector (size_t s) :
                my_vector(s, T())
            {}

        my_vector (size_t s, const T& v) {
            if (s != 0) {
                _b = new T[s];             // T: built-in type; O(1), no initialization
                			               // T: user     type; O(n), T(), s times
                _e = _b + s;
                fill(begin(), end(), v);}} // O(n), =(T), s times

        my_vector (initializer_list<T> rhs) {
            if (rhs.size() != 0) {
                _b = new T[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}} // O(n), =(T), s times

        my_vector             (const my_vector&) {
        	// fix this
        	}

        /*
        my_vector (const my_vector& rhs) {
        	_b = rhs._b;
        	_e = rhs._e;
        */

        my_vector& operator = (const my_vector&) {
        	...} // fix this

        ~my_vector () {
            delete [] _b;} // T: built-in type; O(1), no destruction
            			   // T: user     type; O(n), ~T(), s times

        T& operator [] (size_t i) {
            assert(i < size());
            return _b[i];}

        const T& operator [] (size_t i) const {
            return (*const_cast<my_vector*>(this))[i];}

        T* begin () {
            return _b;}

        const T* begin () const {
            return const_cast<my_vector*>(this)->begin();}

        T* end () {
            return _e;}

        const T* end () const {
            return const_cast<my_vector*>(this)->end();}

        size_t size () const {
            return _e - _b;}};

void f (vector<int> y) // copy constructor
	{...}

vector<int> x(10, 2);
f(x);

ostream my_stream = cout; // no
