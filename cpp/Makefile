.DEFAULT_GOAL := all

ASTYLE        := astyle
CHECKTESTDATA := checktestdata
CPPCHECK      := cppcheck
DOXYGEN       := doxygen
VALGRIND      := valgrind

ifeq ($(shell uname -s), Darwin)
    BOOST    := /usr/local/include/boost
    CXX      := clang++
    CXXFLAGS := --coverage -g -pedantic -std=c++17 -I/usr/local/include -Wall -Wextra
    GCOV     := llvm-cov gcov
    GTEST    := /usr/local/src/googletest-master
    LDFLAGS  := -lgtest -lgtest_main
    LIB      := /usr/local/lib
    VALGRIND :=
else ifeq ($(shell uname -p), unknown)
    BOOST    := /usr/include/boost
    CXX      := g++
    CXXFLAGS := --coverage -g -pedantic -std=c++17 -Wall -Wextra
    GCOV     := gcov
    GTEST    := /usr/src/gtest
    LDFLAGS  := -lgtest -lgtest_main -pthread
    LIB      := /usr/lib
    VALGRIND := valgrind
else
    BOOST    := /usr/local/opt/boost-1.67/include/boost
    CXX      := g++-11
    CXXFLAGS := --coverage -g -pedantic -std=c++17 -Wall -Wextra
    GCOV     := gcov-11
    GTEST    := /usr/local/include/gtest
    LDFLAGS  := -L/usr/local/opt/boost-1.77/lib/ -lgtest -lgtest_main -pthread
    LIB      := /usr/local/lib
    VALGRIND := valgrind-3.17
endif

FILES :=                    \
    Hello                   \
    UnitTests3              \
    Coverage1               \
    Coverage2               \
    Coverage3               \
    IsPrimeT                \
    Exceptions              \
    StrCmpT                 \
    Variables

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.cppx: %
	./$<

%.cppy: %
	./$<
	$(GCOV) $<.cpp | grep -B 2 "cpp.gcov"

%.cppz: %
	$(VALGRIND) ./$<
	$(GCOV) $<.cpp | grep -B 2 "cpp.gcov"

all: $(FILES)

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist
	rm -f $(FILES)

docker:
	docker run --rm -i -t -v $(PWD):/usr/gcc -w /usr/gcc gpdowning/gcc

run: $(FILES:=.cppx)

sync:
	make clean
	@echo ~/examples/cpp/
	@rsync -p -r -t -u -v --delete         \
    --include "Dockerfile"                 \
    --include "Script.txt"                 \
    --include "Hello.cpp"                  \
    --include "Assertions.cpp"             \
    --include "UnitTests1.cpp"             \
    --include "UnitTests2.cpp"             \
    --include "UnitTests3.cpp"             \
    --include "Coverage1.cpp"              \
    --include "Coverage2.cpp"              \
    --include "Coverage3.cpp"              \
    --include "Exceptions.cpp"             \
    --include "Variables.cpp"              \
    --include "Arguments.cpp"              \
    --include "Returns.cpp"                \
    --exclude "*"                          \
    ~/examples/cpp/ .
	@echo ~/exercises/cpp/
	@rsync -p -r -t -u -v --delete         \
    --include "IsPrimeT.cpp"               \
    --include "StrCmpT.cpp"                \
    --include "IncrT.cpp"                  \
    --exclude "*"                          \
    ~/exercises/cpp/ .

versions:
	@echo "% which $(ASTYLE)"
	@which $(ASTYLE)
	@echo
	@echo "% $(ASTYLE) --version"
	@$(ASTYLE) --version

	@echo
	@echo "% which $(CHECKTESTDATA)"
	@which $(CHECKTESTDATA)
	@echo
	@echo "% $(CHECKTESTDATA) --version"
	@$(CHECKTESTDATA) --version

	@echo
	@echo "% which cmake"
	@which cmake
	@echo
	@echo "% cmake --version"
	@cmake --version

	@echo
	@echo "% which $(CPPCHECK)"
	@which $(CPPCHECK)
	@echo
	@echo "% $(CPPCHECK) --version"
	@$(CPPCHECK) --version

	@echo
	@echo "% which $(DOXYGEN)"
	@which $(DOXYGEN)
	@echo
	@echo "% $(DOXYGEN) --version"
	@$(DOXYGEN) --version

	@echo
	@echo "% which $(CXX)"
	@which $(CXX)
	@echo
	@echo "% $(CXX) --version"
	@$(CXX) --version

	@echo
	@echo "% which $(GCOV)"
	@which $(GCOV)
	@echo
	@echo "% $(GCOV) --version"
	@$(GCOV) --version

	@echo
	@echo "% which git"
	@which git
	@echo
	@echo "% git --version"
	@git --version

	@echo
	@echo "% which make"
	@which make
	@echo
	@echo "% make --version"
	@make --version

ifneq ($(shell uname -s), Darwin)
	@echo
	@echo "% which $(VALGRIND)"
	@which $(VALGRIND)
	@echo
	@echo "% $(VALGRIND) --version"
	@$(VALGRIND) --version
endif

	@echo "% which vim"
	@which vim
	@echo
	@echo "% vim --version"
	@vim --version

	@echo
	@echo "% grep \"#define BOOST_LIB_VERSION \" $(BOOST)/version.hpp"
	@grep "#define BOOST_LIB_VERSION " $(BOOST)/version.hpp

	@echo
	@echo "% grep \"set(GOOGLETEST_VERSION\" $(GTEST)/CMakeLists.txt"
	@grep "set(GOOGLETEST_VERSION" $(GTEST)/CMakeLists.txt
	@echo
	@echo "% ls -al $(LIB)/libgtest*.a"
	@ls -al $(LIB)/libgtest*.a
