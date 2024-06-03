/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:04:28 by flverge           #+#    #+#             */
/*   Updated: 2024/06/03 10:40:45 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

Utils::Utils( const string file, const string target, const string remplace ) :
	_originFile(file), _targetString(target), _replacingString(remplace) {
		this->buildTargetFile();
	}

Utils::~Utils(){}

const string& Utils::getOriginFile( void )const{
	return this->_originFile;
}

const string& Utils::getReplace( void )const{
	return this->_replacingString;
}

const string& Utils::getTarget( void )const{
	return this->_targetString;
}

void Utils::buildTargetFile( void ){
	string targetFile = this->_originFile;

	targetFile.append(".replace");

	this->_targetFile = targetFile;

	printColor(RED, this->_targetFile);
}

/**
 * @brief Compare target and replace string, exit if so.
 * 
 */
void Utils::areStringEqual( void )const{
	if (this->_targetString == this->_replacingString)
	{
		printColor(RED, "⛔ argv[1] and argv[2] are identical ⛔");
		exit(EXIT_FAILURE);
	}
}

// void Utils::deleteReplaceFile( void )const{
// 	int status = std::remove("*.replace");
// 	if (status)
// 		printColor(RED, "⛔ Error deleting \".replace\" file ⛔");
// 	else
// 		printColor(GREEN, "✅ Successfully deleting \".replace\" file ✅");
// }

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
