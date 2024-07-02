#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

int main(void){

	// filesystem::exists("hello.txt") ? cout << "File exists" << endl : 

	cout << ((filesystem::exists("hellooo.txt")) ? "File exists" : "File does not exists");
}