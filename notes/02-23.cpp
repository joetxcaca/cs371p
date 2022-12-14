// -----------
// Wed, 23 Feb
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
please track your grades
*/

/*
Paper #6: Open-Closed Principle
remember to go to Perusall THROUGH Canvas

this is the first of a 5-paper series
SOLID design
*/

/*
Project #2: Voting
	1. write code to only handle the I/O
	2. use a single bucket (vector of vector)
	3. use a bucket per candidate
	4. can NOT use new/delete, use the STL (e.g., vector, list, etc.)
Canvas poll
crowd source checktestdata schema
best to remove make run-all from .gitlab-ci.yml, until you're really done
*/

int& pre_incr (int& r) {
	return r += 1;}

int post_incr (int& r) {
	int v = r;
	r += 1;
	return v;}

#define TEST0
#define TEST1
// #define TEST2
// #define TEST3

#ifdef TEST0
void test0 () {
    int i = 2;
    int j = pre_incr(i); // like pre ++
    assert(i == 3);
    assert(j == 3);}
#endif

#ifdef TEST1
void test1 () {
    int i = 2;
    int j = pre_incr(pre_incr(i));
    assert(i == 4);
    assert(j == 4);}
#endif

#ifdef TEST2
void test2 () {
    int i = 2;
    int j = post_incr(i); // like post ++
    assert(i == 3);
    assert(j == 2);}
#endif

#ifdef TEST3
void test3 () {
    int i = 2;
//  post_incr(post_incr(i)); // error: no matching function for call to 'post_incr'
    assert(i == 2);}
#endif

/*
you're not allowed to use ++!!!
*/
