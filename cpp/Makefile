.DEFAULT_GOAL := all

ASTYLE        := astyle
CHECKTESTDATA := checktestdata
CPPCHECK      := cppcheck
DOXYGEN       := doxygen

ifeq ($(shell uname -s), Darwin)
    BOOST    := /usr/local/include/boost
    CXX      := clang++
    CXXFLAGS := --coverage -g -std=c++17 -Wall -Wextra -Wpedantic
    GCOV     := llvm-cov gcov
    GTEST    := /usr/local/src/googletest-master
    LDFLAGS  := -lgtest -lgtest_main
    LIB      := /usr/local/lib
    VALGRIND :=
else ifeq ($(shell uname -p), unknown)
    BOOST    := /usr/include/boost
    CXX      := g++
    CXXFLAGS := --coverage -g -std=c++17 -Wall -Wextra -Wpedantic
    GCOV     := gcov
    GTEST    := /usr/src/gtest
    LDFLAGS  := -lgtest -lgtest_main -pthread
    LIB      := /usr/lib
    VALGRIND :=
else
    BOOST    := /usr/local/opt/boost-1.67/include/boost
    CXX      := g++-11
    CXXFLAGS := --coverage -g -std=c++17 -Wall -Wextra -Wpedantic
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
    Variables               \
    Arguments               \
    Returns                 \
    Consts                  \
    Arrays1                 \
    Allocator               \
    Iterators               \
    Arrays2                 \
    StackT                  \
    Iteration               \
    Initializations         \
    Vector1T                \
    Vector2T                \
    FunctionOverloading     \
    Move                    \
    Vector3T                \
    Shapes1T                \
    Shapes2T

%: %.cpp
	$(CPPCHECK) $<
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.cppx: %
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
    --include "Consts.cpp"                 \
    --include "Arrays1.cpp"                \
    --include "Allocator.cpp"              \
    --include "Iterators.cpp"              \
    --include "Arrays2.cpp"                \
    --include "Iteration.cpp"              \
    --include "Initializations.cpp"        \
    --include "FunctionOverloading.cpp"    \
    --include "Move.cpp"                   \
    --exclude "*"                          \
    ~/examples/cpp/ .
	@echo ~/exercises/cpp/
	@rsync -p -r -t -u -v --delete         \
    --include "IsPrimeT.cpp"               \
    --include "StrCmpT.cpp"                \
    --include "IncrT.cpp"                  \
    --include "EqualT.cpp"                 \
    --include "CopyT.cpp"                  \
    --include "ReverseT.cpp"               \
    --include "FillT.cpp"                  \
    --include "StackT.cpp"                 \
    --include "Vector1T.cpp"               \
    --include "Vector2T.cpp"               \
    --include "Vector3T.cpp"               \
    --include "Shapes1T.cpp"               \
    --include "Shapes2T.cpp"               \
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

ifneq ($(VALGRIND),)
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
