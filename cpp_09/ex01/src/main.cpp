/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:43:22 by flverge           #+#    #+#             */
/*   Updated: 2024/08/13 12:33:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void printUsage( void ){

    printColor(BOLD_RED, "Wrong Arguments Provided");
    print("Usage :");
    printColorNoEndl(BOLD_GREEN, "./RPN      ");
    printColorNoEndl(BOLD_YELLOW, " \" 8 9 * 9 - 9 - 9 - 4 - 1 + \" ");
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

    // ! STEP 1 : detects for double digits
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
    
    // ! STEP 2 : search for a lenght() < 3 or not an operator as last char
    if ( input.length() < 3 or !isOperator(lastChar) ){

        printColor(BOLD_RED, "lenght < 3 or last operator is not a operator ");
        return false;
    }

    
    // ! STEP 3 checks if the first 3 operators are number/number/operator
    if ( not ( std::isdigit(input[0]) and std::isdigit(input[1]) and isOperator(input[2]) ) ){

        printColor(BOLD_RED, "first 3 arguments are not nb/nb/op");
        return false;
    }
    
    // ! STEP 4 : search for an invalid char
    std::string::iterator it = std::find_if(input.begin(), input.end(), notOkChars);
    
    if (it != input.end()){

        printColor(BOLD_RED, "Invalid char detected");
        return false;
    }

    // ! STEP 5 : search for coherence for alternance between numbers and operators
    // ! Except for first 3 chars, one number is followed by one operator, two numbers are followed by 2 operators, not more

    string subThree(input);

    subThree.erase(subThree.begin(), subThree.begin() + 3);

    
    // ! Count post arguments of three to check if odd or not.
    if ( subThree.length() % 2 != 0){

        printColor(BOLD_RED, "Post three odd");
        return false;
    }
    

    // ! STEP 6 : Check if there is a coherence : 1 nb == 1 op, 2nb == 2op
    if (subThree.length()){
        
        bool doubleCount = false;
        
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
static bool correctArgv(char **av){

    // (void)(rpn);
    string mainArg(av[1]);
    
    if ( not validChars( mainArg ) )
        return false;
    return true;
}

int main( int ac, char** av){

    if (ac != 2 or not correctArgv(av)){

        printUsage();
        return 1;
    }
    
    RPN rpn(av[1]);

    rpn.parseStack();

    printColorNoEndl(BOLD_GREEN, "Result = ");
    
    try
    {
        print(rpn.printResult());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}