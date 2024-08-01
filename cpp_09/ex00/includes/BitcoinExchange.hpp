/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:06 by flverge           #+#    #+#             */
/*   Updated: 2024/08/01 11:45:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"


class BitcoinExchange
{

private:

    string _inputFile;
    string _dataFile;
    map<string, double> _mapData;

public:

    BitcoinExchange( void );
    BitcoinExchange( const BitcoinExchange& copy );
    BitcoinExchange& operator=( const BitcoinExchange& right_operator );
    ~BitcoinExchange();

    // Getter
    const string& getInputFile( void )const;
    const string& getDataFile( void )const;

    // Setter
    void    setInputFile( string input );
    void    setDataFile( string input );

    // print
    void    printDataFile( void );

    void    mapData( void );

    void    mapInput( void );

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

        this->_inputFile = right_operator._inputFile;
        this->_dataFile = right_operator._dataFile;        
        
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange( void ){}

void    BitcoinExchange::mapData( void ){

    // Map data.csv within
    
    // split values on each getline on the coma

    // store both key and value on each

    ifstream inputFile(this->getDataFile().c_str());

    if (not inputFile.is_open())
        customExit("Failed to open " + this->getDataFile());
    
    string readLine;
    string key, value, splitValue;

    string separator = ",";
    // map date to a int value
    while (getline(inputFile, readLine)){

        // extract the date
        key = readLine.substr(0, readLine.find(separator));
        // extract BTC value
        value = readLine.erase(0, readLine.find(separator) + separator.length());

        // insert in the _mapData raw date value AND double value with atof.
        this->_mapData.insert( std::make_pair(key, std::atof(value.c_str()) ) );
    }
}
void    BitcoinExchange::mapInput( void ){

    // Rules for a valid input
    // Have a | separator
    // Have a valid date (YYYY-MM-DD)
    // Have a valid number (positive, between 0 and 1000 included)
}

void    BitcoinExchange::printDataFile( void ){

    for (map<string, double>::iterator it = _mapData.begin();
        it != _mapData.end(); ++it)
    {
        printNoEndl("Date : ");
        print(it->first);
        printNoEndl("Bitcoin Value : ");
        print(it->second);
    }
    
}


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
