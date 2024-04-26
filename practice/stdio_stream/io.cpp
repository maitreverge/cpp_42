#include <iostream>

int main(void){
	/*
	In standart output, I inject the string "Hello World"
	Then, I inject std::endl, which is c++ for '\n'
	*/
	std::cout << "Hello, World !" << std::endl;

	// those two lines are exactly the same
	std::cout << "Hello, World !\n";

	char	buff[1024];
	std::cout << "Input a word : ";
	std::cin >> buff;
	std::cout << "You entered : " << buff << std::endl;

}