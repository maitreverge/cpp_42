#include <iostream>

int main(void)
{
	int age;
	std::string name;

	std::cout << "what is your age ? " << std::endl;

	std::cin >> age;

	// l'utilisation de getline avec un cin avant impose l'utulisation d'un cin.ignore
	std::cin.ignore();

	std::cout << "Your age is " << age << std::endl;

	std::cout << "What is your name ? " << std::endl;

	getline(std::cin, name);

	std::cout << "Your name is " << name << std::endl;
}