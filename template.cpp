/**
 * Advent of Code Day 1.1
 * date solved: 17 sept 2023
 * 
 * Pass the name of the input file as an argument to the program. 
 * Default file name is `input`.
 * 
 * If `NDEBUG` is not set, default file name is `test`, and the program 
 * also runs the test function(s).
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>

using std::cout, std::cin, std::endl;
using std::string;
using std::vector;

void test_()
{
    assert(true);
}

int main(int argc, const char *argv[])
{
    string default_filename = "input";
    #ifndef NDEBUG
        default_filename = "test";
    #endif

    // argc denotes the number of arguments passed +1 (it includes the program name)
    string filename = (argc > 1 ? argv[1] : default_filename);

    std::ifstream in(filename);
    if(!in.is_open()) {
        std::cerr << "Couldn't open input file `" + filename << "`.\n";
        return -1;
    }

    #ifndef NDEBUG
        test_();
    #endif   

    return 0;
}