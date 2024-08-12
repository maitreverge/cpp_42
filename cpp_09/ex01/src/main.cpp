/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:43:22 by flverge           #+#    #+#             */
/*   Updated: 2024/08/12 12:56:33 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void printUsage( void ){

    printColor(BOLD_RED, "Wrong Arguments Provided");
    print("Usage :");
    printColorNoEndl(BOLD_GREEN, "./RPN      ");
    printColorNoEndl(BOLD_YELLOW, " \" 8 5 * 3 - 9 / 1 - 12 + \" ");
}

bool isOperator( char &c ){

    return (c == PLUS or
            c == MINUS or
            c == MULTIPLY or
            c == DIVIDE)
    ? true
    : false;
}

/**
 * @brief Return true if an invalid char has been found
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool notOkChars( char &c ){

    return (std::isdigit(c) or isOperator(c)) ? false : true;
}

bool    validChars( string &input ){

    //     8 5 * 3 -  9 /  1 -  1 2 +

    
    // ! STEP 0 : detects for double digits
    int digitDetects = 0;
    for (size_t i = 0; input[i]; i++)
    {
        if ( std::isdigit(input[i]) )
            digitDetects++;
        else
            digitDetects = 0;
        
        if (digitDetects > 1){
            
            printColor(BOLD_RED, "double digit detected");
            return false;  
        }
    }
    
    // removed all whitespaces from the string    
    input.erase( std::remove_if( input.begin(), input.end(), ::isspace ), input.end() );
    
    char lastChar = *(input.end() - 1);
    
    // ! STEP 1 : search for a lenght() < 3 or not an operator as last char
    if ( input.length() < 3 or !isOperator(lastChar) ){

        printColor(BOLD_RED, "lenght < 3 or last operator is not a operator ");
        return false;
    }

    
    // ! STEP 1.1 checks if the first 3 operators are number/number/operator
    if ( not ( std::isdigit(input[0]) and std::isdigit(input[1]) and isOperator(input[2]) ) ){

        printColor(BOLD_RED, "first 3 arguments are not nb/nb/op");
        return false;
    }
    
    // ! STEP 2 : search for an invalid char
    std::string::iterator it = std::find_if(input.begin(), input.end(), notOkChars);
    
    // print( *it );
    
    if (it != input.end()){

        printColor(BOLD_RED, "Invalid char detected");
        return false;
    }

    // int nbDetect = 0;
    // int opDetect = 0;

    // ! STEP 3 : search for coherence for alternance between numbers and operators
    // ! Except for first 3 chars, one number is followed by one operator, two numbers are followed by 2 operators, not more

    string subThree(input);

    subThree.erase(subThree.begin(), subThree.begin() + 3);

    
    // ! Count post arguments of three to check if odd or not.
    if ( subThree.length() % 2 != 0){

        printColor(BOLD_RED, "Post three odd");
        return false;
    }
    
    bool doubleCount = false;

    // ! Check if there is a coherence : 1 nb == 1 op, 2nb == 2op
    if (subThree.length()){
        
        for (size_t i = 0; i < subThree.length(); i++)
        {
            if ( std::isdigit(subThree[i]) and !doubleCount ){

               i++;
               if ( std::isdigit(subThree[i]) )
                   doubleCount = true;
               else
                   continue;
            }
            else if ( isOperator(subThree[i]) and doubleCount ){
                
                i++;
                if ( isOperator(subThree[i]) )
                    doubleCount = false;
                else
                    return false;
            }
            else
                return false;
        }
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