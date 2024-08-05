/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:06 by flverge           #+#    #+#             */
/*   Updated: 2024/08/05 12:12:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"


class BitcoinExchange
{

private:

    string _inputFile;
    string _dataFile;
    map<string, double> _mapData; // parsed data.csv
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
    void    printInputFile( void );

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
        this->_mapData.insert( std::make_pair(key, std::atof(value.c_str()) ) );
    }
}

bool validChar( char input ){

     
    if (std::isdigit(input)
        or input == PIPE
        or input == DOT
        or input == HYPHEN)
        return true;
    return false;
    
}

/**
 * @brief Checks if the string of the input file has the correct value, such as :
 * - One separator `|`
 * - Two `-` Date separators
 * - Maximum one dot `.` for double numbers
 * - Only numbers
 * 
 * If not, return false
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool    isInputValid( string str ){

    int separator = std::count(str.begin(), str.end(), '|');
    
    int hyphen = std::count(str.begin(), str.end(), '-');

    int dot = std::count(str.begin(), str.end(), '.');

    if (separator != 1 or hyphen != 2 or dot > 1)
        return false;
    
    std::none_of(str.begin(), str.end(), validChar);
    

    
    
}
void    BitcoinExchange::mapInput( void ){

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

        // ! STEP 1 : parse whatever the content

        

        // extract the date
        key = readLine.substr(0, readLine.find(pipeSeparator));
        // extract BTC value
        value = readLine.erase(0, readLine.find(pipeSeparator) + pipeSeparator.length());

    }
}

void    BitcoinExchange::printDataFile( void ){

    for (map<string, double>::iterator it = _mapData.begin();
        it != _mapData.end(); ++it)
    {
        printNoEndl("Date : ");
        print(it->first); // first value
        printNoEndl("Bitcoin Value : ");
        print(it->second); // second value
    }
    
}

void    BitcoinExchange::printInputFile( void ){

    for (map<string, double>::iterator it = _mapParsedInput.begin();
        it != _mapParsedInput.end(); ++it)
    {
        printNoEndl("Input Date : ");
        print(it->first); // first value
        printNoEndl("Input asked Value : ");
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
