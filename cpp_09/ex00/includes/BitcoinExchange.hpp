/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:06 by flverge           #+#    #+#             */
/*   Updated: 2024/08/05 15:23:41 by flverge          ###   ########.fr       */
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
/**
 * @brief Return true if given char is either a digit, a whitespace, a `|', `-` or a `.`.
 * 
 * Returns false otherwise.
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool validChar( char input ){

    if (std::isdigit(input)
        or std::isspace(input)
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

    // Count the amount of `|` characters
    int separator = std::count(str.begin(), str.end(), '|');
    
    int hyphen = std::count(str.begin(), str.end(), '-');

    int dot = std::count(str.begin(), str.end(), '.');

    if (separator != 1 or hyphen != 2 or dot > 1)
        return false;
    
    // Chekcks if there is all valid charatcers
    if (std::any_of(str.begin(), str.end(), validChar))
        return true;
    return false;
}

bool    isValidDate( string str ){

    // valid format = 2023-02-20
    string trimmed = trimWhitespace(str);

    if (trimmed.length() != 10)
        return false;
    
    if ( std::count(trimmed.begin(), trimmed.end(), '-') != 2
        or trimmed[4] != HYPHEN
        or trimmed[7] != HYPHEN )
        return false;
    
    
    // trimmed specific to extract substrings
    string year = trimmed.substr(0, 4);

    string month = trimmed.substr(5, 2);

    string day = trimmed.substr(8, 2);

    bool allNumeric = std::all_of(year.begin(), year.end(), ::isdigit)
        & std::all_of(month.begin(), month.end(), ::isdigit)
        & std::all_of(day.begin(), day.end(), ::isdigit);
    
    if ( not allNumeric )
        return false;
    
    int yearInt = std::atoi(year.c_str());
    int monthInt = std::atoi(month.c_str());
    int dayInt = std::atoi(day.c_str());

    if (yearInt < 0)
        return false;
    
    // switch statement for checking the 30 and 31 DAYS repartition
    switch (monthInt)
    {
        case 1: // january
            if (dayInt > 31)
                return false;
            break;
        case 2:// Febuary
            if (dayInt > 28) // screw leap years
                return false;
            break;
        case 3: // and so on
            if (dayInt > 31)
                return false;
            break;
        case 4:
            if (dayInt > 30)
                return false;
            break;
        case 5:
            if (dayInt > 31)
                return false;
            break;
        case 6:
            if (dayInt > 30)
                return false;
            break;
        case 7:
            if (dayInt > 31)
                return false;
            break;
        case 8:
            if (dayInt > 31)
                return false;
            break;
        case 9:
            if (dayInt > 30)
                return false;
            break;
        case 10:
            if (dayInt > 31)
                return false;
            break;
        case 11:
            if (dayInt > 30)
                return false;
            break;
        case 12:
            if (dayInt > 31)
                return false;
            break;
        default:
            return false;
    }
    
    
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
        else if (not isValidDate(key) or not isValidValue(value))
        {
            printColor(BOLD_RED, readLine + " is a invalid format line.");
            //
        }


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
