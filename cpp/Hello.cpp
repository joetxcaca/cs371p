// ---------
// Hello.cpp
// ---------

// https://en.cppreference.com
// https://en.cppreference.com/w/cpp/io
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Nothing to be done." << endl;
    return 0;}

/*
Developed in 1978 by Bjarne Stroustrup of Denmark.
C++ is procedural, object-oriented, statically typed, and not garbage collected.

C++98
C++03
C++11
C++14
C++17
C++20
C++23



% which clang++
/usr/bin/clang++



% clang++ --version
Apple clang version 13.0.0 (clang-1300.0.29.30)
Target: x86_64-apple-darwin21.3.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin



% clang++ -g -std=c++17 -Wall -Wextra -Wpedantic Hello.cpp -o Hello



% ./Hello
Nothing to be done.
*/
