/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:06 by flverge           #+#    #+#             */
/*   Updated: 2024/07/29 13:07:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"


class BitcoinExchange
{

private:

    string _inputFile;
    string _dataFile;

public:

    BitcoinExchange( void );
    BitcoinExchange( const BitcoinExchange& copy );
    BitcoinExchange& operator=( const BitcoinExchange& right_operator );
    ~BitcoinExchange();

    const string& getInputFile( void )const;
    const string& getDataFile( void )const;

    void    setInputFile( string input );
    void    setDataFile( string input );

};

// ! TO DO LATER
// ostream& operator<<( ostream& output_stream, const BitcoinExchange& input );


// ---------- Functions declarations ---------------


BitcoinExchange::BitcoinExchange( void ) : 
    _inputFile(""),
    _dataFile("") {}


BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) :
    _inputFile(copy._inputFile),
    _dataFile(copy._dataFile) {}
    // {*this = copy;} in case of non-member values


BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& right_operator ){

   if (this != &right_operator){
        // Reassign every value with the getter value 
        this->_inputFile = right_operator._inputFile;
        this->_dataFile = right_operator._dataFile;
        
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange( void ){}

// Getters
const string& BitcoinExchange::getInputFile( void )const{ return this->_inputFile; }
const string& BitcoinExchange::getDataFile( void )const{ return this->_dataFile; }

// Setters
void    BitcoinExchange::setInputFile( string input ){ _inputFile = input; }
void    BitcoinExchange::setDataFile( string input ){ _dataFile = input; }


// ! TO DO LATER
// ostream& operator<<( ostream& output_stream, const BitcoinExchange& right_input ){

//     // output_stream << right_input.PutAGetterFunctionhere();

//     return output_stream;
// }
