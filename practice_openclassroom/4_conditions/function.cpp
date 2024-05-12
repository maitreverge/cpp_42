#include <iostream>

void	increment(int nb)
{
	std::cout << "Nombre dans fonction increment avant = " << nb << std::endl;
	nb = nb + 1;
	// nb++;

	std::cout << "Nombre dans fonction increment apres = " << nb << std::endl;
}

int main(void)
{
	int nombre = 42;

	// ! Syntaxe pour declaration + assignation d'un pointeur
	// int *ptr_nombre = &nombre;

	// ! Cette variable est comme un alias, donc une reference
	int &ref_nombre = nombre;

	std::cout << "Valeur de ref_nombre = " << ref_nombre << std::endl;

	std::cout << "Adresses de nombre = " << &nombre << std::endl;
	std::cout << "Adresses de ref_nombre = " << &ref_nombre << std::endl;
	// increment(nombre);
	// std::cout << "Nombre main post fonction increment = " << nombre << std::endl;
}