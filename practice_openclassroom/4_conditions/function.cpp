#include <iostream>

void	carre(int &nombre)
{
	nombre = nombre * nombre;
}

int main(void)
{
	int nb = 4;

	carre(nb);

	std::cout << "nb au carre = = " << nb << std::endl;
}