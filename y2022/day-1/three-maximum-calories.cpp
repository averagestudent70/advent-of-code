/**
 * Advent of Code Day 1.1
 * date solved: 17 sept 2023
 * date modified: 26 sept 2024
 * 
 * finds the top three of the maximum total calories an elf has packed.
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
#include <algorithm>
#include <iterator>
#include <numeric>
#include "lib_calories.h"

using std::cout, std::cin, std::endl;
using std::string;
using std::vector;

unsigned sum(const vector<unsigned> &vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}

unsigned get_sum_three_max_cals(const vector<vector<unsigned>> &elves)
{
    vector<unsigned> calories;
    std::transform(elves.begin(), elves.end(), 
        std::back_inserter(calories), sum);
    std::sort(calories.begin(), calories.end(), std::greater<unsigned>());
    return calories[0] + calories[1] + calories[2];
}

void test_sum_three_maximum_calories(const vector<vector<unsigned>> &elves)
{
    assert(get_sum_three_max_cals(elves) == 45000);
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
        test_sum_three_maximum_calories(elves);
    #endif

    cout << "Sum of three maximum calories: " << get_sum_three_max_cals(elves) << "\n";

    return 0;
}