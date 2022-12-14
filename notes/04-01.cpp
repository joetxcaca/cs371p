// -----------
// Fri,  1 Apr
// -----------

/*
Class
	MWF 1-2 pm CT

Website
	https://www.cs.utexas.edu/users/downing/cs371p/Schedule.html

Help Sessions
	W 5-7 pm

Office Hours
	Glenn Downing
		Th 3-4 pm, Zoom

	Philo Lin (undergrad, '23)
		M 2-3 pm, Zoom

	Serdjan Rolovic (grad, '22)
		Th 2-3 pm, Zoom

Cold Calling
	you're only called ONCE per rotation
	it's totally fine to not know the answer, the idea is to discuss and to learn

Notes
	these notes will be posted on GitLab

Canvas
	personal questions
	please message all 3 of us

Ed Discussion (EdStem), replaces Piazza
	class questions
	ask and answer questions
	please be proactive

GitLab, like GitHub, do a git clone, later git pull, on	 a regular basis
	notes
	examples
	exercises

HackerRank, competitive programming platform
	exercises

Perusall, collaborative annotation tool (you must go through the Canvas assignment)
	annotate a series of papers
	the first one will be the syllabus

Zoom
	5.9.6
	must use UT EID credentials (@eid.utexas.edu)
	classes recorded
	published later that day

Specifications Grading
	please ask about this if you don't undestand it
	please use the Google Sheet that we're providing to track your grades

Discord
	https://discord.gg/Qd3DVQZG

Grades Tracker Google Sheet
	https://docs.google.com/spreadsheets/d/1nt_FXi5vYuZlsxTPnanItjcivtZy8Gu4AADpPsdBWhM/

Virtual Token Google Form
	https://forms.gle/yoiKV2Vw1cSWbxBQ7/
*/

/*
cold calling
specifications grading
very much a C++ class
*/

/*
please track your grades
please be responsive on Canvas
*/

/*
Paper #9: Why getter and setter methods are evil
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
*/

/*
Darwin
stack
queue
priority_queue
*/

// input

2

8 8
6
f 0 0 e
h 3 3 n
h 3 4 e
h 4 4 s
h 4 3 w
f 7 7 n
5 1

7 9
4
t 0 0 s
h 3 2 e
r 5 4 n
t 6 8 w
5 1

// output

*** Darwin 8x8 ***
Turn = 0.
  01234567
0 f.......
1 ........
2 ........
3 ...hh...
4 ...hh...
5 ........
6 ........
7 .......f

Turn = 1.
  01234567
0 f.......
1 ........
2 ...h....
3 .....h..
4 ..h.....
5 ....h...
6 ........
7 .......f

Turn = 2.
  01234567
0 f.......
1 ...h....
2 ........
3 ......h.
4 .h......
5 ........
6 ....h...
7 .......f

Turn = 3.
  01234567
0 f..h....
1 ........
2 ........
3 .......h
4 h.......
5 ........
6 ........
7 ....h..f

Turn = 4.
  01234567
0 f..h....
1 ........
2 ........
3 .......h
4 h.......
5 ........
6 ........
7 ....h..f

Turn = 5.
  01234567
0 f..h....
1 ........
2 ........
3 .......h
4 h.......
5 ........
6 ........
7 ....h..f

*** Darwin 7x9 ***
Turn = 0.
  012345678
0 t........
1 .........
2 .........
3 ..h......
4 .........
5 ....r....
6 ........t

Turn = 1.
  012345678
0 t........
1 .........
2 .........
3 ...h.....
4 ....r....
5 .........
6 ........t

Turn = 2.
  012345678
0 t........
1 .........
2 .........
3 ....r....
4 ....r....
5 .........
6 ........t

Turn = 3.
  012345678
0 t........
1 .........
2 .........
3 ....rr...
4 .........
5 .........
6 ........t

Turn = 4.
  012345678
0 t........
1 .........
2 ....r....
3 ......r..
4 .........
5 .........
6 ........t

Turn = 5.
  012345678
0 t........
1 ....r....
2 .........
3 .......r.
4 .........
5 .........
6 ........t


enum Direction {...}

struct Instruction {
	...};

struct Species {
	char                _name;
	vector<Instruction> _instructions;
	...};

struct Creature {
	int       _program_counter;
	Direction _direction;
	Species*  _species;};       // must be a pointer because of infect

struct Darwin {
	vector<Creature>          _creatures; // be very careful about using vector
	vector<vector<Creature*>> _grid;};
