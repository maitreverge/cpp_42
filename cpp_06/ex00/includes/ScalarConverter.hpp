/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:52:34 by flverge           #+#    #+#             */
/*   Updated: 2024/07/20 12:21:57 by flverge          ###   ########.fr       */
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
    void    printImpossible( string &input );

};

// ---------- Functions declarations ---------------


ScalarConverter::ScalarConverter( void ){}


ScalarConverter::ScalarConverter( const ScalarConverter& copy ) {*this = copy;}

void    ScalarConverter::printImpossible( string &input ) {

    printColorNoEndl(BOLD_BLUE, input);
    printColor(BOLD_RED, "impossible");
}


void    ScalarConverter::convert( string &input ) {
    
    string allTypes[4] = {"char: ", "int: ", "float: ", "double: "};
    
    string allLimits[6] = {"+inff", "+inf", "-inff", "-inf", "nan", "nanf"};
    
    if (isInputValid(input)){
        
    }
    else{

        for (size_t i = 0; i < 4; i++)
            ScalarConverter::printImpossible(allTypes[i]);
    }
    
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& right_operator ){
    (void)(right_operator);
    return *this; }


ScalarConverter::~ScalarConverter( void ){}