/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:04:28 by flverge           #+#    #+#             */
/*   Updated: 2024/06/03 14:19:31 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Utils::Utils( const string file, const string target, const string remplace ) :
	_originFile(file), _targetString(target), _replacingString(remplace) {
		this->buildTargetFile();
}


Utils::~Utils(){}

/**
 * @brief Build the destination file name based on the target file.
 * `file1` target file name => `file1.replace` destination file name.
 * 
 */
void Utils::buildTargetFile( void ){
	string targetFile = this->_originFile;

	targetFile.append(".replace");

	this->_targetFile = targetFile;
}


void Utils::areStringEqual( void )const{
	if (this->_targetString == this->_replacingString)
	{
		printColor(RED, "⛔ argv[1] and argv[2] are identical ⛔");
		exit(EXIT_FAILURE);
	}
}


const string& Utils::getOriginFile( void )const{
	return this->_originFile;
}


const string& Utils::getTargetFile( void )const{
	return this->_targetFile;
}


const string& Utils::getReplaceString( void )const{
	return this->_replacingString;
}


const string& Utils::getTargetString( void )const{
	return this->_targetString;
}


// ----------------- UTILS FUNCTIONS --------------------------------

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
