#include "Sample_class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor Called" << std::endl;
	this->nb = 42;

	/*
	`this`  is a special syntax which allows to kickstart the program with initialised values
	*/
	std::cout << "1ere instance number = " << this->nb << std::endl;

	this->ft_salut();
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destrcutor Called" << std::endl;
	return ;
}

void	Sample::ft_salut(void)
{
	std::cout << "Coucou les copines, c'est l'heure des chocapic" << std::endl;
	return ;
}