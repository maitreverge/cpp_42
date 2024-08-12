#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;

int main(void){

	string str = "1234567890";

	cout << str << endl;

    str.erase(str.begin(), str.begin() + 3);

	cout << str << endl;


}