#include <iostream>
#include "sample_class.hpp"

/**
 * @brief Construct a new Sample:: Sample object
 * 
 */
Sample::Sample(void) {
	std::cout << "Constructor Called " << std::endl;
	return ;
}

// Les constructeurs et les destructeurs de classes
// n'ont pas de valeurs de retours, ce sont des procedures

/**
 * @brief Destroy the Sample:: Sample object
 * 
 */
Sample::~Sample(void) {
	std::cout << "Destructor Called" << std::endl;
	return ;
}

/**
 * @brief Print a message on the output
 * 
 */
void	Sample::ft_hello(void) {
	std::cout << "Salut bande de coquines" << std::endl;
	return ;
}