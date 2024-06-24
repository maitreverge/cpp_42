/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:36:57 by flverge           #+#    #+#             */
/*   Updated: 2024/05/09 10:39:16 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

int main(void)
{
	Sample hello;

	hello.publicBar();

	// hello._privateBar(); // won't compile

	return 0;
}