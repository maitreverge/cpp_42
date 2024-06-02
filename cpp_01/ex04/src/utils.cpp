/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:04:28 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 14:13:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

Utils::Utils( const string target, const string remplace ) :
	_targetString(target), _remplacingString(remplace) {}

Utils::~Utils(){}

void	print( string str ){
	cout << str << endl;
}

void	printNoEndl( string str ){
	cout << str;
}

void	printColor( string COLOR, string str ){
	cout << COLOR << str << RESET << endl;
}

void	printColorNoEndl( string COLOR, string str ){
	cout << COLOR << str << RESET;
}
