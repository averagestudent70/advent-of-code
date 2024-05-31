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
    assert();
}

int main(int argc, const char *argv[])
{
    #ifndef NDEBUG
    test_();
    return 0;
    #endif

    // argc denotes the number of arguments passed +1 (it includes the program name)
    const string filename = (argc > 1 ? argv[1] : "input");
    std::ifstream in(filename);
    if(!in.is_open()) {
        std::cerr << "Couldn't open input file `" + filename << "`. Check if you are present"
                    " in the directory in which the input file is present\n";
        return -1;
    }
}