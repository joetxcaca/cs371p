// -----------
// Fri, 22 Apr
// -----------

/*
Paper 13. What Happens to Us Does Not Happen to Most of You
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
Vector3
Life
Shapes
Circles
*/

template <typename T>
class my_vector {
    friend bool operator == (const my_vector& lhs, const my_vector& rhs) {
        return (lhs.size() == rhs.size()) && equal(lhs.begin(), lhs.end(), rhs.begin());}

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
                _b = new T[s];
                _e = _b + s;
                fill(begin(), end(), v);}}

        my_vector (initializer_list<T> rhs) {
            if (rhs.size() != 0) {
                _b = new T[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}}

        my_vector (const my_vector& rhs) {
            if (rhs.size() != 0) {
                _b = new T[rhs.size()];
                _e = _b + rhs.size();
                copy(rhs.begin(), rhs.end(), begin());}}

        my_vector (my_vector&& rhs) {
            swap(rhs);}

        my_vector& operator = (const my_vector& rhs) {
            if (this == &rhs)
                return *this;
            my_vector that(rhs); // copy constructor
            swap(that);
            return *this;}

        my_vector& operator = (my_vector&& rhs) {
            if (this == &rhs)
                return *this;
            my_vector that(move(rhs)); // move constructor
            swap(that);
            return *this;}

        ~my_vector () {
            delete [] _b;}

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
            return _e - _b;}

        void swap (my_vector& rhs) {
            std::swap(_b, rhs._b);
            std::swap(_e, rhs._e);}};

/*
Project #5: Life
*/

/*
John Conway's Game of Life
*/

/*
cell has two states
	alive (*)
	dead  (.)
*/

.....
..*..
..*..
..*..
.....

/*
5x5, 25 cells
3  alive
22 dead
*/

/*
neighborhood is defined as all of the adjacent cells
1. corner:   3
2. edge:     5
3. interior: 8
*/

/*
if the cell is alive and there are 2 or 3 live neighbors
	cell stays alive

if the cell is dead and there are 3 live neighbors
	cell becomes alive
*/

.....
.....
.***.
.....
.....


.....
..*..
..*..
..*..
.....


// Life.in.txt

5

4 4
4
1 1
1 2
2 1
2 2
1 1

5 5
3
2 1
2 2
2 3
2 1

5 5
4
1 2
2 1
2 3
3 2
1 1

5 6
6
1 2
1 3
2 1
2 4
3 2
3 3
1 1

6 6
5
1 2
2 3
3 1
3 2
3 3
4 1



*** Life<ConwayCell> 4x4 ***

Generation = 0, Population = 4.
....
.**.
.**.
....

Generation = 1, Population = 4.
....
.**.
.**.
....

*** Life<ConwayCell> 5x5 ***

Generation = 0, Population = 3.
.....
.....
.***.
.....
.....

Generation = 1, Population = 3.
.....
..*..
..*..
..*..
.....

Generation = 2, Population = 3.
.....
.....
.***.
.....
.....

*** Life<ConwayCell> 5x5 ***

Generation = 0, Population = 4.
.....
..*..
.*.*.
..*..
.....

Generation = 1, Population = 4.
.....
..*..
.*.*.
..*..
.....

*** Life<ConwayCell> 5x6 ***

Generation = 0, Population = 6.
......
..**..
.*..*.
..**..
......

Generation = 1, Population = 6.
......
..**..
.*..*.
..**..
......

*** Life<ConwayCell> 6x6 ***

Generation = 0, Population = 5.
......
..*...
...*..
.***..
......
......

Generation = 1, Population = 5.
......
......
.*.*..
..**..
..*...
......

Generation = 2, Population = 5.
......
......
...*..
.*.*..
..**..
......

Generation = 3, Population = 5.
......
......
..*...
...**.
..**..
......

Generation = 4, Population = 5.
......
......
...*..
....*.
..***.
......

class AbstractCell {
	...}

class ConwayCell : public AbstractCell {
	...}

class FredkinCell : public AbstractCell {
	...}

template <typename C>
class Life {
	...}

Life<ConwayCell>  x(5, 5, ConwayCell(...));       // homogeneous grid of ConwayCell
Life<FredkinCell> y(5, 5, FredkinCell(...));      // homogeneous grid of FredkinCell

Life<AbstractCell> z(5, 5, ConwayCell(...));      // no

Life<AbstractCell*> z(5, 5, ConwayCell(...));     // no

Life<AbstractCell*> z(5, 5, new ConwayCell(...)); // no
