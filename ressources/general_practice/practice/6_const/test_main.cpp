/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:15:28 by flverge           #+#    #+#             */
/*   Updated: 2024/06/10 16:29:04 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	const int VALEUR_1 = 42; // oui

	VALEUR_1++; // mdr non

	std::cout << VALEUR_1 << std::endl;

	return 0;
}#include "../includes/Fixed.hpp"
#include <cassert>

int main(void) {
    Fixed a(4.2f);
    Fixed b(2.1f);
    Fixed c(4.2f);
    
    // Test operator<=
    assert(a <= b == false);
    assert(a <= c == true);
    
    // Test operator>
    assert(a > b == true);
    assert(a > c == false);
    
    // Test operator>=
    assert(a >= b == true);
    assert(a >= c == true);
    
    // Test operator==
    assert(a == b == false);
    assert(a == c == true);
    
    // Test operator!=
    assert(a != b == true);
    assert(a != c == false);
    
    return 0;
}