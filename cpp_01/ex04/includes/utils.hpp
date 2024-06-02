/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:02:12 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 14:13:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

// ANSII colors codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class Utils
{
private:
	const string _targetString;
	const string _remplacingString;
public:
	Utils( const string target, const string remplace );
	~Utils();
};


void	print( string str );
void	printNoEndl( string str );
void	printColor( string COLOR, string str );
void	printColorNoEndl( string COLOR, string str );