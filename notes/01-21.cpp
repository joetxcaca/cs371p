// -----------
// Fri, 21 Jan
// -----------

/*
Class Modality
	first two weeks on Zoom, you're welcome to go to physical room (JGB 2.218)

Cold Calling
	you're only called ONCE per rotation
	it's totally fine to not know the answer, the idea is to discuss and to learn

Lectures
	MWF 1 pm

Help Sessions
	W 6-8 pm

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
	5.9.1
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
*/

/*
Canvas: office hours
Discord: please change your server name to your full name
Perusall: syllabus assignment (answer questions)
*/

/*
for software development you need tool chain
C++ took chain
	g++
	gcov,          a coverage tool
	cppcheck,      static analyzer
	astyle,        auto formatter
	doxygen,       auto documentation
	checktestdata, input file verifier
*/

/*
how to get that tool chain
	1. download those tools to your local machine
	2. ssh into the CS machines
	3. use Docker (totally optional)
*/

/*
install Docker
pull a Docker image from Docker Hub
*/

https://hub.docker.com/r/gpdowning/gcc/



% which docker
/usr/local/bin/docker



% docker --version
Docker version 20.10.12, build e91ed57



% docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE



% cat Dockerfile
FROM gcc

RUN apt-get update

RUN apt-get -y install astyle
RUN apt-get -y install cppcheck
RUN apt-get -y install cmake
RUN apt-get -y install dos2unix
RUN apt-get -y install doxygen
RUN apt-get -y install graphviz
RUN apt-get -y install valgrind
RUN apt-get -y install vim
RUN apt-get -y install libboost-dev
RUN apt-get -y install libboost-serialization-dev
RUN apt-get -y install libgmp-dev
RUN apt-get -y install libgtest-dev

RUN git clone https://github.com/DOMjudge/checktestdata checktestdata && \
    cd checktestdata                                                  && \
    git checkout release                                              && \
    ./bootstrap                                                       && \
    make                                                              && \
    cp checktestdata /usr/bin                                         && \
    cd -

RUN cd /usr/src/gtest                                                 && \
    cmake CMakeLists.txt                                              && \
    make                                                              && \
    cp lib/*.a /usr/lib                                               && \
    cd -

CMD bash
*/


% docker build -t gpdowning/gcc .
...



% docker login
...



% docker push gpdowning/gcc
...



% docker pull gpdowning/gcc
...



% docker images
REPOSITORY         TAG       IMAGE ID       CREATED          SIZE
gpdowning/gcc      latest    fde3b7dc38c6   4 minutes ago    1.95GB
gcc                latest    709e60f7d3e3   4 weeks ago      1.23GB



% pwd
/Users/downing/git/cs371p/cpp



% ls
Assertions.cpp	Dockerfile	Hello.cpp	Script.txt	makefile



% docker run --rm -i -t -v /Users/downing/git/cs371p/cpp:/usr/gcc -w /usr/gcc gpdowning/gcc
root@c70871d08248:/usr/gcc# pwd
/usr/gcc



root@c70871d08248:/usr/gcc# ls
Assertions.cpp	Dockerfile	Hello.cpp	Script.txt	makefile



root@c70871d08248:/usr/gcc# which astyle
/usr/bin/astyle
root@c70871d08248:/usr/gcc# astyle --version
Artistic Style Version 3.1



root@c70871d08248:/usr/gcc# which checktestdata
/usr/bin/checktestdata
root@c70871d08248:/usr/gcc# checktestdata --version
checktestdata -- version 20220121, written by Jan Kuipers, Jaap Eldering, Tobias Werth



root@c70871d08248:/usr/gcc# which cmake
/usr/bin/cmake
root@c70871d08248:/usr/gcc# cmake --version
cmake version 3.18.4



root@c70871d08248:/usr/gcc# which cppcheck
/usr/bin/cppcheck
root@c70871d08248:/usr/gcc# cppcheck --version
Cppcheck 2.3



root@c70871d08248:/usr/gcc# which doxygen
/usr/bin/doxygen
root@c70871d08248:/usr/gcc# doxygen --version
1.9.1



root@c70871d08248:/usr/gcc# which g++
/usr/local/bin/g++
root@c70871d08248:/usr/gcc# g++ --version
g++ (GCC) 11.2.0



root@c70871d08248:/usr/gcc# which gcov
/usr/local/bin/gcov
root@c70871d08248:/usr/gcc# gcov --version
gcov (GCC) 11.2.0



root@c70871d08248:/usr/gcc# which git
/usr/bin/git
root@c70871d08248:/usr/gcc# git --version
git version 2.30.2



root@c70871d08248:/usr/gcc# which make
/usr/bin/make
root@c70871d08248:/usr/gcc# make --version
GNU Make 4.3



root@c70871d08248:/usr/gcc# which valgrind
/usr/bin/valgrind
root@c70871d08248:/usr/gcc# valgrind --version
valgrind-3.16.1



root@c70871d08248:/usr/gcc# which vim
/usr/bin/vim
root@c70871d08248:/usr/gcc# vim --version
VIM - Vi IMproved 8.2 (2019 Dec 12, compiled Oct 01 2021 01:51:08)



root@c70871d08248:/usr/gcc#  grep "#define BOOST_LIB_VERSION " /usr/include/boost/version.hpp
#define BOOST_LIB_VERSION "1_74"



root@c70871d08248:/usr/gcc# grep "set(GOOGLETEST_VERSION" /usr/src/gtest/CMakeLists.txt
set(GOOGLETEST_VERSION 1.10.0)



root@c70871d08248:/usr/gcc# ls -al /usr/lib/libgtest*.a
-rw-r--r-- 1 root root 2446902 Jan 21 05:54 /usr/lib/libgtest.a
-rw-r--r-- 1 root root    4012 Jan 21 05:54 /usr/lib/libgtest_main.a
