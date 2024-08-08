/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:43:22 by flverge           #+#    #+#             */
/*   Updated: 2024/08/08 11:59:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void printUsage( void ){

    printColor(BOLD_RED, "Wrong Arguments Provided");
    print("Usage :");
    printColorNoEndl(BOLD_GREEN, "./RPN      ");
    printColorNoEndl(BOLD_YELLOW, " \" 8 5 * 3 - 9 / 1 - 12 + \" ");
}

bool okChars( char c){

    if (std::isdigit(c) or
        c == PLUS or
        c == MINUS or
        c == MULTIPLY or
        c == DIVIDE)
            return true;
    return false;
}

bool    validChars( string &input ){

    // isdigit
    // Operators + - * /

    // removed all whitespaces from the string    
    input.erase( std::remove_if( input.begin(), input.end(), ::isspace ), input.end() );
    
    // print(*(input.end() - 1));

    // checks if last argument is a number
    if ( std::isdigit( input[input.length() - 1] ) )
        return false;
    
    //     8 5 * 3 -  9 /  1 -  1 2 +

    std::find_if(input.begin(), input.end(), okChars);
    
    
    return true;
    
}

/**
 * @brief Checks and parse all arguments within the stack
 * 
 * @param av 
 * @return true 
 * @return false 
 */
static bool correctArgv(char **av, RPN &rpn){

    (void)(rpn);
    string mainArg(av[1]);
    
    if ( not validChars( mainArg ) )
        return false;
    return true;
}

int main( int ac, char** av){

    RPN rpn;
    if (ac != 2){

        printUsage();
        return 1;
    }
    else if (not correctArgv(av, rpn)){

        printColor(BOLD_RED, "Wrong arguments given");
        return 1;
    }

    // ! TO DO : make the maths
    
}