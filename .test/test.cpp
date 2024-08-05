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

string trimWhitespace(const string& str) {
    // Copy the input string to a new string which will be trimmed
    string trimmed = str;

    // Find the first character position after leading whitespace
    string::size_type left = trimmed.find_first_not_of(" \t\n\r");

    // Find the last character position before trailing whitespace
    string::size_type right = trimmed.find_last_not_of(" \t\n\r");
    
    // If both 'left' and 'right' are not string::npos (indicating that the string is not all whitespace)
    if (left != string::npos && right != string::npos) {
        // Trim the string by taking a substring from 'left' to 'right'
        trimmed = trimmed.substr(left, right - left + 1);
    } else {
        // If the string is all whitespace, clear it
        trimmed.clear();
    }
    
    // Return the trimmed string
    return trimmed;
}

bool    isValidDate( string str ){

    // valid format = 2023-02-20
    string trimmed = trimWhitespace(str);

    cout << "Whole string : " << str << endl;

    if (trimmed.length() != 10)
        return false;
    
    if ( std::count(trimmed.begin(), trimmed.end(), '-') != 2
        or trimmed[4] != HYPHEN
        or trimmed[7] != HYPHEN )
        return false;
    
    string year, month, day;

    year = trimmed.substr(0, 4);

    month = trimmed.substr(5, 2);

    day = trimmed.substr(8, 2);

    cout << year << endl;
    cout << month << endl;
    cout << day << endl;

    return true; 
    
}

int main(void){

	string str = "  2011-01-03    ";

	if (isValidDate(str))
        cout << "OKAY" << endl;
    else
        cout << "NOPE" << endl;

}