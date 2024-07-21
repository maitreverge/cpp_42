/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:52:34 by flverge           #+#    #+#             */
/*   Updated: 2024/07/21 07:59:57 by ubuntu           ###   ########.fr       */
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

void    printChar( string &input, bool isLimit ){

    // Testing for limits 
    if (isLimit){

        printColor(BOLD_RED, "impossible");
        return;
    }
    
    // Testing for a simple char (exclusing 0 to 9 input)
    if (input.length() == 1
        and std::isprint(input[0])
        and not std::isdigit(input[0])){

        cout << BOLD_GREEN << input << RESET << endl;
        return;
    }

    // Trying to convert the string in a string
    unsigned char result;
    try
    {
        result = std::atoi(input.c_str());
    }
    catch(const std::exception& e)
    {
        printColor(BOLD_RED, "impossible");
        return;
    }

    if (std::isgraph(result))
        cout << BOLD_GREEN << result << RESET << endl;
    else
        printColor(BOLD_RED, "Non displayable");
    
}

void    printInt( string &input, bool isLimit){

    // Testing for limits keywords
    if (isLimit){

        if (input == "nan")
            printColor(BOLD_RED, "impossible");
        else
            cout << BOLD_GREEN << input << RESET << endl;
        return;
    }

    // edge case for 0

    // if 
    
    long long int result;
    try
    {
        result = std::atoll(input.c_str());
    }
    catch(const std::exception& e)
    {
        printColor(BOLD_RED, "impossible");
        return;
    }

    if (result > INT_MAX or result < INT_MIN)
        printColor(BOLD_RED, "impossible");
    else
        cout << BOLD_GREEN << result << RESET << endl;

    return;
}

void    ScalarConverter::convert( string &input ) {
    
    string allLimits[6] = {"+inff", "+inf", "-inff", "-inf", "nan", "nanf"};

    bool isLimit = false;

    // Check is the string is part of a limit
    for (size_t i = 0; i < 6; i++)
    {
        if (input == allLimits[i]){
            
            isLimit = true;
            break;
        }
    }
    
    
    printColorNoEndl(BOLD_BLUE, "char: ");
    printChar(input, isLimit);
    printColorNoEndl(BOLD_BLUE, "int: ");
    printInt(input, isLimit);
    printColorNoEndl(BOLD_BLUE, "double: ");
    // printDouble(input);
    printColorNoEndl(BOLD_BLUE, "float: ");
    // printFloat(input);
    
    
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& right_operator ){
    (void)(right_operator);
    return *this; }


ScalarConverter::~ScalarConverter( void ){}