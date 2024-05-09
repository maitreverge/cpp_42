/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:15:28 by flverge           #+#    #+#             */
/*   Updated: 2024/05/09 10:23:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	const int VALEUR_1 = 42; // oui

	VALEUR_1++; // mdr non

	std::cout << VALEUR_1 << std::endl;

	return 0;
}