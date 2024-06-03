/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:18 by flverge           #+#    #+#             */
/*   Updated: 2024/06/03 22:15:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;

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

class Harl
{
private:

	typedef enum _e{
		DEBUG, // 0
		INFO,
		WARNING,
		ERROR
	} _keywords;
	
	void debug( void )const;
	void info( void )const;
	void warning( void )const;
	void error( void )const;

	void(Harl::*ptrDebug)( void )const;
	void(Harl::*ptrInfo)( void )const;
	void(Harl::*ptrWarning)( void )const;
	void(Harl::*ptrError)( void )const;
	// size_t _attributes[4];
public:
	Harl( void );
	~Harl( void );
	void complain( string level );
};

void	print( string str );
void	printNoEndl( string str );
void	printColor( string COLOR, string str );
void	printColorNoEndl( string COLOR, string str );
void	clearScreen( void );



