#include <iostream>
#include <string>

int main(void)
{
	int a = 42;

	int &ref_a = a;

	a = 21;

	ref_a++;

	// int *pointeur_a = &a;

	// *pointeur_a = 4;

	int               a;


	std::cout << "Valeur de a = " << a << std::endl;
	std::cout << "Valeur de ref_a = " << ref_a << std::endl;

	
}