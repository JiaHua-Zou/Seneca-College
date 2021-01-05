// Workshop 9 - Multi-Threading
// w9.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include "SecureData.h"
#include   <bitset>
using namespace std;

int main(int argc, char** argv)
{
    unsigned int a = 1;
    unsigned int b = 2;
    unsigned int c = 3;
    unsigned int d = 4;
    unsigned int e = 5;

    a <<= 2;
    b >>= 0;
    c = a & b;
    d = a ^ b;
    e = c | d;


    std::cout << "a = " << std::bitset<8>(a) << std::endl;
    std::cout << "b = " << std::bitset<8>(b) << std::endl;
    std::cout << "c = " << std::bitset<8>(c) << std::endl;
    std::cout << "d = " << std::bitset<8>(d) << std::endl;
    std::cout << "e = " << std::bitset<8>(e) << std::endl;

	/*cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4)
	{
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

    char key = argv[3][0];

    try {
        w9::SecureData sd(argv[1], key, &cout);
        sd.backup(argv[2]);

        sd.restore(argv[2], key);
        cout << sd << std::endl;

    } catch (const std::string& msg) {
        cout << msg << std::endl;
    }*/

	return 0;
}
