/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:52:34 by flverge           #+#    #+#             */
/*   Updated: 2024/07/20 13:26:04 by flverge          ###   ########.fr       */
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

ScalarConverter::e_Result isInputValid( string &input, /* string allTypes[4] , */ string allLimits[6] )
{
    if (input == "")
        return ScalarConverter::ERROR;
    
    // Checking for any limits string
    for (size_t i = 0; i < 6; i++)
    {
        if (input == allLimits[i])
            return ScalarConverter::LIMITS;
    }
    
    // Check for char
    if (input.length() == 1 and not std::isdigit(input[0]) and std::isprint(input[0]))
        return ScalarConverter::CHAR;
    
    // Check for int
    return ScalarConverter::ERROR;
    
}

void    ScalarConverter::convert( string &input ) {
    
    string allTypes[4] = {"char: ", "int: ", "float: ", "double: "};
    
    string allLimits[6] = {"+inff", "+inf", "-inff", "-inf", "nan", "nanf"};
    
    
    if (size_t result = isInputValid(input, /* allTypes,*/ allLimits)){
        
        // switch (result)
        // {
        // case /* constant-expression */:
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }
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