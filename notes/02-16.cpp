// -----------
// Wed, 16 Feb
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
Paper #5: Single Responsibility Principle
remember to go to Perusall THROUGH Canvas

this is the first of a 5-paper series
SOLID design
*/

k = (i += j); // yes in C, C++, Java; no in Python

(i += j) = k; // yes in C++, no in C, Java, Python

/*
write a program that ONLY handles the input correctly
write the simplest possible solution, ONE bucket
bucket for each candidate
*/

2 // the number of test cases
  // blank line
3             // the number of candidates
John Doe      // the names of the candidates
Jane Smith
Sirhan Sirhan
1 2 3         // the ballots of the voters
2 1 3
2 3 1
1 2 3
3 1 2
              // blank line
3
John Doe
Jane Smith
Sirhan Sirhan
1 2 3
2 1 3
2 3 1
1 2 3
3 1 2
              // NO blank line, EOF instead

/*
1. count the 1st preferences
2. does any candidate have a majority, if yes, we have a winner
3. is there a tie among all of the candidates, if yes, we have many winners
4. identify the candidates that are tied for last
       revisit the ballots of those losers
       consider the next preference on those ballots
	   start over again
*/

/*
a test case ends in a blank line
the last test case ends in EOF
*/
