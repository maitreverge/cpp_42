/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:02:12 by flverge           #+#    #+#             */
/*   Updated: 2024/06/03 14:15:04 by flverge          ###   ########.fr       */
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

class Utils
{
private:
	const string _originFile;
	string _targetFile; // build with buildTargetFile
	const string _targetString;
	const string _replacingString;
public:
	Utils( const string file, const string target, const string remplace );
	~Utils();
	
	void			buildTargetFile( void );
	void			areStringEqual( void )const;
	
	const string&	getOriginFile( void )const;
	const string&	getTargetFile( void )const;
	
	const string&	getReplaceString( void )const;
	const string&	getTargetString( void )const;
};

void	print( string str );
void	printNoEndl( string str );
void	printColor( string COLOR, string str );
void	printColorNoEndl( string COLOR, string str );