/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:32:28 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/28 15:43:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){}


ScalarConverter::ScalarConverter( const ScalarConverter& copy ) {*this = copy;}

bool inputIsZero( string &input ) {
    
    int decimalPresence = 0; // for '.'
    int floatingPresence = 0; // for the 'f' character
    int polarityPresence = 0; // for the either '+' or the '-'

    size_t i = 0;

    if (input[i] == '+' or input[i] == '-'){
        
        polarityPresence = true;
        i++;
    }
    
    // loop throught the whole string
    for (; i < input.length(); i++)
    {
        if (input[i] == '.'){
            
            decimalPresence++;
            if (decimalPresence > 1) return false;
        }
        else if (input[i] == 'f'){
            
            floatingPresence++;
            if (floatingPresence > 1) return false;
        }
        else if (input[i] == '+' or input[i] == '-'){

            polarityPresence++;
            if (polarityPresence > 1) return false;
        }
        else if (input[i] != '0')
            return false;
    }
    
    return true;
}

bool inputIsValid( string &input ) {
    
    int decimalPresence = 0; // for '.'
    int floatingPresence = 0; // for the 'f' character
    int polarityPresence = 0; // for the either '+' or the '-'

    size_t i = 0;

    if (input[i] == '+' or input[i] == '-'){
        
        polarityPresence = true;
        i++;
    }
    
    // loop throught the whole string
    for (; i < input.length(); i++)
    {
        if (input[i] == '.'){
            
            decimalPresence++;
            if (decimalPresence > 1) return false;
        }
        else if (input[i] == 'f'){
            
            floatingPresence++;
            if (floatingPresence > 1) return false;
        }
        else if (input[i] == '+' or input[i] == '-'){

            polarityPresence++;
            if (polarityPresence > 1) return false;
        }
        else if (not isdigit(input[i]))
            return false;
    }
    
    return true;
}

void    printChar( string &input, bool isLimit ){

    // Testing for a simple char (exclusing 0 to 9 input)
    if (input.length() == 1
        and std::isprint(input[0])
        and not std::isdigit(input[0])){

        cout << BOLD_GREEN << input << RESET << endl;
        return;
    }
    
    // Testing for limits 
    if (isLimit or not inputIsValid(input)){

        printColor(BOLD_RED, "impossible");
        return;
    }
    

    // Trying to convert the string in a string
    unsigned char result = std::atoi(input.c_str());

    if (std::isgraph(result))
        cout << BOLD_GREEN << result << RESET << endl;
    else
        printColor(BOLD_RED, "Non displayable");
    
}


void    printInt( string &input, bool isLimit ){

    // Testing for limits keywords
    if (isLimit){

        if (input[0] == 'n')
            printColor(BOLD_RED, "nan");
        else if (input[0] == '+')
            cout << BOLD_GREEN << "+inf" << RESET << endl;
        else
            cout << BOLD_GREEN << "-inf" << RESET << endl;
        return;
    }

    // edge case for single chars
    else if (input.length() == 1 && std::isprint(input[0])) {
        cout << BOLD_GREEN << static_cast<int>(input[0]) << RESET << endl;
        return;
    }
    
    else if (input.empty() or not inputIsValid(input)){
        
        printColor(BOLD_RED, "impossible");
        return;
    }

    // edge case for mathematical 0 value
    else if (inputIsZero(input))
    {
        cout << BOLD_GREEN << 0 << RESET << endl;
        return;
    }
    
    long long int result = std::atoll(input.c_str());

    /*
        atoll return 0 if the conversion failed, and such case has been handled
        by the function inputIsZero
    */
    if (result > INT_MAX or result < INT_MIN or result == 0)
        printColor(BOLD_RED, "impossible");
    else
        cout << BOLD_GREEN << result << RESET << endl;

    return;
}

void    printFloat( string &input, bool isLimit){

    // Testing for limits keywords
    if (isLimit){

        if (input[0] == 'n')
            printColor(BOLD_RED, "nanf");
        else if (input[0] == '+')
            cout << BOLD_GREEN << "+inff" << RESET << endl;
        else
            cout << BOLD_GREEN << "-inff" << RESET << endl;
        return;
    }

    else if (input.length() == 1 && std::isprint(input[0])) {
        
        cout << BOLD_GREEN << std::fixed << std::setprecision(5) << static_cast<float>(input[0]) << "f" << RESET << endl;
        return;
    }
    
    if (input.empty() or not inputIsValid(input)){
        
        printColor(BOLD_RED, "nanf");
        return;
    }

    // edge case for mathematical 0 value
    if (inputIsZero(input))
    {
        cout << BOLD_GREEN << "0.0f" << RESET << endl;
        return;
    }

    double result = std::atof(input.c_str());

    /*
        atof return 0 if the conversion failed, and such case has been handled
        by the function inputIsZero
    */

    if (result > FLT_MAX or result < FLT_MIN or result == 0)
        printColor(BOLD_RED, "impossible");
    else
        cout << BOLD_GREEN << std::fixed << std::setprecision(5) << static_cast<float>(result) << "f" << RESET << endl;

    return;
}

void    printDouble( string &input, bool isLimit){

    // Testing for limits keywords
    if (isLimit){

        if (input[0] == 'n')
            printColor(BOLD_RED, "nan");
        else if (input[0] == '+')
            cout << BOLD_GREEN << "+inf" << RESET << endl;
        else
            cout << BOLD_GREEN << "-inf" << RESET << endl;
        return;
    }
    
    else if (input.length() == 1 && std::isprint(input[0])) {
        cout << BOLD_GREEN << std::fixed << std::setprecision(5) << static_cast<double>(input[0]) << RESET << endl;
        return;
    }
    
    else if (input.empty() or not inputIsValid(input)){
        
        printColor(BOLD_RED, "nan");
        return;
    }

    // edge case for mathematical 0 value
    else if (inputIsZero(input))
    {
        cout << BOLD_GREEN << "0.0" << RESET << endl;
        return;
    }

    long double result = std::atof(input.c_str());

    /*
        atof return 0 if the conversion failed, and such case has been handled
        by the function inputIsZero
    */
    if (result > DBL_MAX or result < DBL_MIN or result == 0)
        printColor(BOLD_RED, "impossible");
    else
        cout << BOLD_GREEN << std::fixed << std::setprecision(5) << static_cast<double>(result) << RESET << endl;

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
    printColorNoEndl(BOLD_BLUE, "float: ");
    printFloat(input, isLimit);
    printColorNoEndl(BOLD_BLUE, "double: ");
    printDouble(input, isLimit);
    
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& right_operator ){
    (void)(right_operator);
    return *this; }


ScalarConverter::~ScalarConverter( void ){}