/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:43:22 by flverge           #+#    #+#             */
/*   Updated: 2024/08/07 15:07:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void printUsage( void ){

    printColor(BOLD_RED, "Wrong Arguments Provided");
    print("Usage :");
    printColorNoEndl(BOLD_GREEN, "./RPN      ");
    printColorNoEndl(BOLD_YELLOW, " \" 8 5 * 3 - 9 / 1 - 12 + \" ");
}

bool    validChars( string input){

    // isdigit
    // Operators + - * /

    bool isChar = false;
    int nbChars = 0;

    // Checks if there is not two consecutives characters without a whitespace
    for (size_t i = 0; i < input.length(); i++)
    {
        if ( std::isspace( input[i] ))
            isChar = false;
        else if ( std::isdigit(input[i]) and !isChar ){
            
            isChar = true;
            nbChars++;
        }
        else if (  (input[i] == PLUS or
                    input[i] == MINUS or
                    input[i] == MULTIPLY or
                    input[i] == DIVIDE ) and !isChar ){
                        
                        isChar = true;
                        nbChars++;
                    }
        else
            return false; // ? ALL CORNER CASES IDENTIFIED
    }

    if (nbChars < 3)
        return false;
    

    // ! THINK ABOUT FREEING THE POINTER
    char *inputs = strtok(const_cast<char*>( input.c_str() ), " \t\n");

    int operators = 0;
    int numbers = 0;
    // 3 consecutives numbers or 3 consecutives operators is false
    
    for (size_t i = 0; inputs[i]; i++)
    {
        if (std::isdigit(inputs[i])){

            numbers++;
            operators = 0;
        }
        else{

            operators++;
            numbers = 0;
        }
        
        if (operators > 2 or numbers > 2)
            return false;
    }
    
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

    string mainArg(av[1]);
    
    if ( not validChars( mainArg ) )
        return false;
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