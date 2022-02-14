// -----------
// Mon, 14 Feb
// -----------

/*
Class Modality
	online until further notice

Cold Calling
	you're only called ONCE per rotation
	it's totally fine to not know the answer, the idea is to discuss and to learn

Lectures
	MWF 1 pm

Help Sessions
	W 5-7 pm

Office Hours
	Glenn Downing
		Th 3-4 pm, Zoom

	Philo Lin (undergrad, '23)
		M 2-3 pm, Zoom

	Serdjan Rolovic (grad, '22)
		Th 2-3 pm, Zoom

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
	5.9.3
	must use UT EID credentials (@eid.utexas.edu)
	classes recorded
	published later that day

Specifications Grading
	please ask about this if you don't undestand it
	please use the Google Sheet that we're providing to track your grades

Website
	https://www.cs.utexas.edu/users/downing/cs371p/Schedule.html

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
Paper #4: 2022-02-13: Pair Programming
remember to go to Perusall THROUGH Canvas
*/

/*
two tokens:   *, &
two contexts: modifying a variable, modifying a type
*/

int  i = 2;
int* p = i;  // no
int* p = &i;
int* p = &2; // no

/*
what are the constraints on &
	l-value
*/

int i = 2;
int j = 3;
int k = (i + j);
k = (i + j);
(i + j) = k; // no, because (i + j) is an r-value

/*
an r-value can be on the right hand side of assignment, but NOT the left
an l-value can be on both sides

the l-value is the stronger of the two
l-values can have their address taken
r-values can not
*/

k = (2 + 3);

/*
+ operator
	takes two r-values
	returns an r-value
	it does NOT have any side effects
	returns the sum
*/

i + j; // at least meaningless

int i = 2;
int j = 3;
i += j;    // modifying i, but not j
i += 2;    // yes
2 += j;    // no

int k = (i += j); // yes for C, C++; Java, no for Python

/*
+= operator
	takes an l-value on the left, an r-value on the right
	returns an l-value, returns the incoming left hand side
	it does have side effect changing the left hand side
*/

/*
as a counter example, in Python, operators that have side effects return NOTHING
*/

(i += j) = k; // yes for C++; no for C, Java, Python

i += j;
i =  k;

i << j; // does not modify i

/*
what operators are like +:
	- (unary, binary), *, /, %, <<, >>, &&, ||, &, |, ~ (unary), ^, <, >, <=, >=, ==, !=

like +=
	-=, *=, /=, %=, <<=, >>=, &=, |=
*/

int i = 2;
int j = ++i;
int j = ++2; // no
cout << i;   // 3
cout << j;   // 3

++i = j; // yes in C++, no in C, Java, Python

/*
++ (pre-increment)
	takes an l-value
	returns an l-value
	it does have a side effect
*/

int i = 2;
int j = i++;
int j = 2++; // no
cout << i;   // 3
cout << j;   // 2

f(i++); // post-increment must create a copy, inherently more expensive than pre-increment

i++ = j; // no in C++, C, Java, Python

/*
++ (post-increment)
	takes an l-value
	returns an r-value
	it does have a side effect
*/

int i = 2;
int j = ++++i;
cout << i;     // 4
cout << j;     // 4

int i = 2;
int j = i++++; // no

int k = ++i++; // no, post has a higher precedence than the pre

for (int i = 0; i < s; i++) { // for ints, doesn't matter pre or post is fine
	...}

{
int i = 0;
while (i < s) {
	...
	i++;}
}

for (T i = 0; i < s; i++) { // for user-defined type, pre is important
	...}

/*
stop worrying, and always use pre
*/
