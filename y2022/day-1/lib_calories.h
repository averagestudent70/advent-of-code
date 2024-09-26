#ifndef LIB_CALORIES_H
#define LIB_CALORIES_H

#include <vector>
#include <istream>

/**
 * Calories carried by a single elf are listed in separate lines,  
 * with entries of different elves separated by blank lines.
 */
std::vector<std::vector<unsigned>> read_calories(std::istream &in);

#endif