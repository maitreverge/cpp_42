/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:06 by flverge           #+#    #+#             */
/*   Updated: 2024/08/05 21:32:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"


class BitcoinExchange
{

private:

    string _inputFile;
    string _dataFile;
    map<int, double> _mapData; // parsed data.csv
    // map<string, string> _mapParsedInput; // raw parsed input.txt with double string keys

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


        /*
            this->_mapData.insert( key, std::atof(value.c_str()) );
            
            ! This way of inserting data is not C++ 98 friendly, we need to go through std::make_pair function
        */
        
        // insert in the _mapData raw date value AND double value with atof.
        this->_mapData.insert( std::make_pair(convertDateToInt(key), std::atof(value.c_str()) ) );
    }
}


void    printResult( string &key, string &value){

    int digitDate = convertDateToInt(key);
    
    double digitValue = std::atof(value.c_str());

    std::map<int, double>::iterator closestResult = std::lower_bound()

    
}

void    BitcoinExchange::mapInput( void ){ // rename function

    // Rules for a valid input
    // Have a | separator
    // Have a valid date format (YYYY-MM-DD) AND a valid date (2012-13-55) 
    // Have a valid number (positive, between 0 and 1000 included)

    ifstream inputFile(this->getInputFile().c_str());

    if (not inputFile.is_open())
        customExit("Failed to open " + this->getInputFile());

    string pipeSeparator = "|";
    
    string readLine, key, value;

    while(getline(inputFile, readLine)){

        // extract the date
        key = readLine.substr(0, readLine.find(pipeSeparator));
        // extract BTC value
        value = readLine.erase(0, readLine.find(pipeSeparator) + pipeSeparator.length());

        if (not isInputValid(readLine))
            printColor(BOLD_RED, readLine + " is a invalid format line.");
        else if (not isValidDate(key))
            printColor(BOLD_RED, key + " is a invalid date line.");
        else if (not isValidValue(value))
            printColor(BOLD_RED, value + " is a invalid value.");
        else
            printResult(key, value);
    }
}

void    BitcoinExchange::printDataFile( void ){

    for (map<int, double>::iterator it = _mapData.begin();
        it != _mapData.end(); ++it)
    {
        printNoEndl("Date : ");
        print(it->first); // first value
        printNoEndl("Bitcoin Value : ");
        print(it->second); // second value
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
