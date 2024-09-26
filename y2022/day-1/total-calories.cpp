/**
 * Advent of Code Day 1.1
 * date solved: 17 sept 2023
 * date modified: 26 sept 2024
 * 
 * finds the maximum total calories an elf has packed.
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
#include <numeric>
#include "lib_calories.h"

using std::cout, std::cin, std::endl;
using std::string;
using std::vector;

/**
 * Returns the maximum calories held by a single elf.
 */
unsigned get_max_calories(const vector<vector<unsigned>> &elves)
{
	unsigned max_cal = 0;
	
	for (auto &calories : elves) {
        unsigned total_cal = std::accumulate(calories.begin(), calories.end(), 0);
        if (max_cal < total_cal)
            max_cal = total_cal;
    }
    return max_cal;
}

void test_max_calories(const vector<vector<unsigned>> &elves)
{
    assert(get_max_calories(elves) == 24000);
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

    vector<vector<unsigned>> elves = read_calories(in);

    #ifndef NDEBUG
        test_max_calories(elves);
    #endif  

	cout << "Maximum calorie found: " << get_max_calories(elves) << "\n";
    return 0;
}