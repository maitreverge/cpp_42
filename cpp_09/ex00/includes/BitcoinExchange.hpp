/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:06 by flverge           #+#    #+#             */
/*   Updated: 2024/08/06 10:30:15 by flverge          ###   ########.fr       */
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

    void    printResult(string &key, string &value);

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
        
        // insert in the _mapData converted date value AND double value with atof.
        this->_mapData.insert( std::make_pair(convertDateToInt(key), std::atof(value.c_str()) ) );
    }
}

// !! MAIN BUGGING FUNCTION
void    BitcoinExchange::printResult( string &key, string &value){ // key = date, value = asked value of bitcoin

    // int digitDate = convertDateToInt(key);
    
    double digitValue = std::atof(value.c_str());

    // double refValue;

    // std::map<int, double>::iterator it = std::lower_bound(_mapData.begin(), _mapData.end(), digitDate);

    /*
        Prendre conscience que it == .begin est ok
        cibler les iterateurs en dehors des limmites
        Redescendre l'iterateur de 1 cran car lower_bound l'avance plutot que le reculer
        
        ! STEP 2 :
        Une fois le correct iterateur obtenu, extraire la valeur et la multiplier par digitValue

        ! STEP 3 :
        imprimmer le resultat voir ou s'inspirer du sujet

        ! STEP 4 : optionnel
        Extraire le "numero" de l'iterateur pour afficher de maniere claire et precise le numero de la ligne dans le fichier data.csv
        voir afficher en plus la ligne en entier en couleur differente
    
    */
    // if (it == _mapData.begin()) // premier resulat == 0
    // {
    //     print("debug");
    // }
    // else /* if  (it != _mapData.end()) */
    // {
    //     it--;
    // }

    // double refValue = it->second;

    printNoEndl("Date : ");
    printColorNoEndl(BOLD_GREEN, key);
    printNoEndl(" // Rate = ");
    // printColorNoEndl(UNDERLINE_YELLOW, refValue);
    printNoEndl(" // Nb of bitcoin = ");
    printColorNoEndl(BOLD_CYAN, digitValue);
    printNoEndl(" // Result = ");
    printNoEndl(value + " * ");
    // printNoEndl(refValue);
    // printColor(HIGH_INTENSITY_GREEN, digitValue * refValue);
    
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
