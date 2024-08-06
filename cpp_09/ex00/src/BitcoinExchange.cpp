/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:24:31 by flverge           #+#    #+#             */
/*   Updated: 2024/08/06 15:25:02 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) : 
    _inputFile(""),
    _dataFile("") {}


BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) :
    _inputFile(copy._inputFile),
    _dataFile(copy._dataFile) {}


BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& right_operator ){

   if (this != &right_operator){

        this->_inputFile = right_operator._inputFile;
        this->_dataFile = right_operator._dataFile;        
        
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange( void ){}

void    BitcoinExchange::mapData( void ){

    ifstream inputFile(this->getDataFile().c_str());

    if (not inputFile.is_open())
        customExit("Failed to open " + this->getDataFile());
    
    string readLine;
    string key, value, splitValue;

    string separator = ",";
    
    while (getline(inputFile, readLine)){

        
        // extract the date
        key = readLine.substr(0, readLine.find(separator));
        // extract BTC value
        value = readLine.erase(0, readLine.find(separator) + separator.length());

        /*
            ! This way of inserting data is not C++ 98 friendly, we need to go through std::make_pair function
            this->_mapData.insert( key, std::atof(value.c_str()) );
            
        */
        if ( isValidDate(key) ) // skips the first live of data.csv, or every line which is not a valid date
            this->_mapData.insert( std::make_pair(convertDateToInt(key), std::atof(value.c_str()) ) );
    }
}

/**
 * @brief Functions which searches for the closest date whithin the data.csv values
 * 
 * @param key 
 * @param value 
 */
void    BitcoinExchange::printResult( string &key, string &value){

    int digitDate = convertDateToInt(key);
    
    double digitValue = std::atof(value.c_str());

    // lower_bound actually searche for the closest result, because results are sorted
    std::map<int, double>::iterator it = _mapData.lower_bound(digitDate);

    // Position variable actually eases the csv data reading
    int position = std::distance(_mapData.begin(), it) + 1;

    if (it->first != digitDate)
        it--;
    else
        position++;

    double refValue = it->second;

    // Main block for printing
    printColorNoEndl(BOLD_YELLOW, "At CSV position : ");
    print(position);
    printNoEndl("Date : ");
    printColorNoEndl(BOLD_GREEN, key);
    printNoEndl(" // Rate = ");
    printColorNoEndl(UNDERLINE_YELLOW, refValue);
    printNoEndl(" // Nb of bitcoin = ");
    printColorNoEndl(BOLD_CYAN, digitValue);
    printNoEndl(" // Result = ");
    printNoEndl(value + " * ");
    printNoEndl(refValue);
    printNoEndl(" = ");
    printColor(HIGH_INTENSITY_GREEN, digitValue * refValue);
    extraLine();
    
}

void    BitcoinExchange::parseInput( void ){

    // Rules for a valid input
    // Have a | separator
    // Have a valid date format (YYYY-MM-DD) AND a valid date (2012-13-55) 
    // Have a valid number (positive, between 0 and 1000 included)

    ifstream inputFile(this->getInputFile().c_str());

    if (not inputFile.is_open())
        customExit("Failed to open " + this->getInputFile());

    string pipeSeparator = "|";
    
    string readLine, key, value, tempReadline;

    while(getline(inputFile, readLine)){

        tempReadline = readLine;
        
        // extract the date
        key = readLine.substr(0, readLine.find(pipeSeparator));
        // extract BTC value
        value = readLine.erase(0, readLine.find(pipeSeparator) + pipeSeparator.length());

        if (not isInputValid(tempReadline)){ // check for the characters validity in readline

            printColorNoEndl(BOLD_RED, tempReadline);
            printColor(BOLD_HIGH_INTENSITY_RED, " is a invalid format line.");   
        }
        else if (not isValidDate(key)){

            printColorNoEndl(BOLD_RED, key);
            printColor(BOLD_HIGH_INTENSITY_RED, " is a invalid DATE.");   
        }
        else if (not isValidValue(value)){

            printColorNoEndl(BOLD_RED, value);
            printColor(BOLD_HIGH_INTENSITY_RED, " is a invalid VALUE.");   
        }
        else
            printResult(key, value); // actual printing value
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