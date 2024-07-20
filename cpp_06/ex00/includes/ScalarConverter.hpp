/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:52:34 by flverge           #+#    #+#             */
/*   Updated: 2024/07/20 15:01:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class ScalarConverter
{

private:

    ScalarConverter( void );
    ScalarConverter( const ScalarConverter& copy );
    ScalarConverter& operator=( const ScalarConverter& right_operator );
    ~ScalarConverter();

public:

    // Les fonctions statiques sont utilisables sans instances d'objet.
    static void convert( string &input );
    // void    printImpossible( string &input );

    typedef enum e{
        ERROR = 0,
        LIMITS,
        CHAR,
        INT,
        
        
    } e_Result;

};

// ---------- Functions declarations ---------------


ScalarConverter::ScalarConverter( void ){}


ScalarConverter::ScalarConverter( const ScalarConverter& copy ) {*this = copy;}

void    printImpossible( string &input ) {

    printColorNoEndl(BOLD_BLUE, input);
    printColor(BOLD_RED, "impossible");
}

ScalarConverter::e_Result isInputValid( string &input, string allTypes[4] , string allLimits[6] )
{
    if (input == "")
        return ScalarConverter::ERROR;
    
    string validChars[4] = {".", "f", "+", "-"};
    // checking error input
    for (size_t i = 0; i < input.size(); i++)
    {
        if (i = 0)
        {
            if (input)
        }
    }
    
    
    // Checking for any limits string
    for (size_t i = 0; i < 6; i++)
    {
        if (input == allLimits[i])
            return ScalarConverter::LIMITS;
    }
    
    // Check for char
    if (input.length() == 1)
        return ScalarConverter::CHAR;
    
    // Check for int
    
    
    return ScalarConverter::ERROR;
    
}

void    ScalarConverter::convert( string &input ) {
    
    string allTypes[4] = {"char: ", "int: ", "float: ", "double: "};
    
    string allLimits[6] = {"+inff", "+inf", "-inff", "-inf", "nan", "nanf"};
    
    
    if (size_t result = isInputValid(input,  allTypes, allLimits)){
        
        switch (result)
        {
        case LIMITS:
            printColorNoEndl(BOLD_BLUE, "char: ");
            printColor(BOLD_RED, "impossible");
            printColorNoEndl(BOLD_BLUE, "int: ");
            printColor(BOLD_RED, "impossible");
            
            break;
        case CHAR:
                printColorNoEndl(BOLD_BLUE, "char: ");
                (std::isprint(input[0])) ? printColor(BOLD_GREEN, input) : printColor(BOLD_RED, "not printable");
                printColorNoEndl(BOLD_BLUE, "int: ");
                cout << BOLD_GREEN << static_cast<int>(input[0]) << RESET << endl;
                printColorNoEndl(BOLD_BLUE, "float: ");
                cout << BOLD_GREEN << static_cast<float>(input[0]) << RESET << endl;
                printColorNoEndl(BOLD_BLUE, "double: ");
            break;
        
        
        default:
            break;
        }
    }
    else{

        for (size_t i = 0; i < 4; i++)
            printImpossible(allTypes[i]);
    }
    
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& right_operator ){
    (void)(right_operator);
    return *this; }


ScalarConverter::~ScalarConverter( void ){}