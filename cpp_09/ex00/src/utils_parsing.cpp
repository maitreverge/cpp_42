/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:27:03 by ubuntu            #+#    #+#             */
/*   Updated: 2024/08/05 21:32:29 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_template.hpp"

/**
 * @brief Converts a string like 2020-12-31 in int 20201231
 * 
 * @param str 
 * @return int 
 */
int    convertDateToInt( string &str ){

    int result;

    string year = str.substr(0, 4);

    string month = str.substr(5, 2);

    string day = str.substr(8, 2);

    int yearInt = std::atoi(year.c_str());
    int monthInt = std::atoi(month.c_str());
    int dayInt = std::atoi(day.c_str());

    // 2020  12   31
    result = (yearInt * 1000) + (monthInt * 100) + dayInt;
    
    return result;
}

bool    isValidValue( string &str ){

    // between 0 and 1000
    // can be double numbers

    string str = trimWhitespace(str);

    if ( isInputZero(str) )
        return true;
    
    int valueInt = std::atof(str.c_str());

    if (valueInt < 0 or valueInt > 1000)
        return false;
    return true;
}

bool isInputZero( string &input ) {
    
    int decimalPresence = 0; // for '.'
    int polarityPresence = 0; // for the either '+' or the '-'

    size_t i = 0;

    // Detecting polarity as first character
    if (input[i] == '+' or input[i] == '-'){
        
        polarityPresence++;
        i++;
    }
    
    // loop throught the whole string
    for (; i < input.length(); ++i)
    {
        if (input[i] == '.'){
            
            decimalPresence++;
            if (decimalPresence > 1) return false;
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

bool    isValidDate( string &str ){

    // valid format = 2023-02-20
    string str = trimWhitespace(str);

    if (str.length() != 10)
        return false;
    
    if ( std::count(str.begin(), str.end(), '-') != 2
        or str[4] != HYPHEN
        or str[7] != HYPHEN )
        return false;
    
    
    // str specific to extract substrings
    string year = str.substr(0, 4);

    string month = str.substr(5, 2);

    string day = str.substr(8, 2);

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
    
    return true;
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
bool    isInputValid( string &str ){

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

/**
 * @brief Return true if given char is either a digit, a whitespace, a `|', `-` or a `.`.
 * 
 * Returns false otherwise.
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool validChar( char &input ){

    if (std::isdigit(input)
        or std::isspace(input)
        or input == PIPE
        or input == DOT
        or input == HYPHEN)
        return true;
    return false;
}