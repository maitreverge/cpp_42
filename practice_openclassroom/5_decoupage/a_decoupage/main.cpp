#include "tete.hpp"

int main(void)
{
	int nb;

	std::cout << "Please enter a number : " << std::endl;
	std::cin >> nb;

	std::cin.ignore();

	int result = ajouteDeux(nb);

	std::cout << "ajouteDeux(nb) = " << result << std::endl;

	return 0;
}