/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:43:38 by flverge           #+#    #+#             */
/*   Updated: 2024/05/08 20:50:03 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample_class.hpp"

int main (void)
{
	Sample coucou;

	// coucou.nb = 66;

	std::cout << "2nd affichage de nb = " << coucou.nb << std::endl;

	coucou.nb++;
	
	std::cout << "3eme affichage de nb = " << coucou.nb << std::endl;
	return 0;
}