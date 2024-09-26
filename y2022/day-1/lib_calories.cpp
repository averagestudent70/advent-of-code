#include "lib_calories.h"
#include <string>

using std::vector, std::string;

/**
 * Calories carried by a single elf are listed in separate lines,  
 * with entries of different elves separated by blank lines.
 */
vector<vector<unsigned>> read_calories(std::istream &in)
{
    vector<vector<unsigned>> calories;
    string line;
    
    vector<unsigned> cals;
	while (getline(in, line)) {
        if (line.empty()) {
            calories.push_back(cals);
            // entry for new elf begins
            cals.clear();
            continue;
        }
        cals.push_back(stoi(line));
	}
    // add the last entry if it was not added
    if (!cals.empty())
        calories.push_back(cals);
    return calories;
}