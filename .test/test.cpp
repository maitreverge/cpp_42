#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;

#define PIPE '|'
#define DOT '.'
#define HYPHEN '-'
#define SPACE ' '

bool validChar( int input ){

     
    if (std::isdigit(input)
        or input == PIPE
        or input == DOT
        or input == HYPHEN)
		// or input == SPACE)
        return true;
    return false;
    
}

int main(void){

	string str = "  	\b 2011-01-03 | 3";

	if (std::any_of(str.begin(), str.end(), validChar))
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
}