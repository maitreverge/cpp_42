/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:11:34 by flverge           #+#    #+#             */
/*   Updated: 2024/05/08 20:27:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

int main (void) {
	
	// Cet appl va me permettre de faire appel a la fois a un constructeur
	// et un destructeur de classe
	Sample coucou;

	coucou.nb = 42;
	
	std::cout << coucou.nb << std::endl;

	coucou.ft_hello();

	return (0);
}