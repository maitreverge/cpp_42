/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:34:16 by flverge           #+#    #+#             */
/*   Updated: 2024/08/20 10:25:34 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ){}

RPN::RPN( string input ) :
    _promptARGV(input){}


RPN::RPN( const RPN& copy ) :
    _promptARGV(copy._promptARGV) {}


RPN& RPN::operator=( const RPN& right_operator ){ static_cast<void>(right_operator); return *this; }

/**
 * @brief Append in the stack with `.push()` method from the end of the `_promptARGV`
 * 
 */
void    RPN::parseStack( void ){

    std::string::iterator it_begin = this->_promptARGV.begin();
    std::string::iterator it_end = this->_promptARGV.end();
    
    // Erase all whitespaces
    this->_promptARGV.erase(std::remove_if(it_begin, it_end, ::isspace ),it_end );

    // push each element in the stack in reverse order
    for (std::string::iterator it = _promptARGV.end() - 1; it >= _promptARGV.begin(); --it)
    {
        _stackArg.push(*it);
    }
}

/**
 * @brief Convert each stack node in a number, `pop` the stack and return the value.
 * 
 * @return int 
 */
int     RPN::popAndConvert( void ){

    int value = _stackArg.top() - '0';

    _stackArg.pop();

    return value;
}

/**
 * @brief Performs a switch case for `+`, `-`, `*` and `/` operators.
 * 
 * Handles `DivideByZero` exception.
 * 
 * @param leftNb 
 * @param rightNb 
 * @param op 
 * @return int 
 */
int     RPN::performSwitch( int leftNb, int rightNb, char op ){

    int result;
    switch (op)
    {
        case '+':
            result = leftNb + rightNb;
            break;
        case '-':
            result = leftNb - rightNb;
            break;
        case '*':
            result = leftNb * rightNb;
            break;
        case '/':
            if (rightNb == 0)
                throw DivideByZero();
            result = leftNb / rightNb;
            break;
    }
    return result;
}

/**
 * @brief Performs the RPN calcul.
 * 
 * @return int 
 */
int     RPN::printResult( void ){

    char mainOperator, secondOperator;
    
    int leftNb = 0, rightNb = 0, result = 0;

    // Calcul for the first 3 elements of the stack and pop them.
    leftNb = popAndConvert();
    rightNb = popAndConvert();
    
    mainOperator = _stackArg.top();
    _stackArg.pop();

    result = performSwitch( leftNb, rightNb, mainOperator );


    // Continue performing operations as long as there is stack content
    while ( _stackArg.size() > 0 ){

        leftNb = popAndConvert();

        // Double numbers edge case
        if ( std::isdigit( _stackArg.top() ) ){
            
            rightNb = popAndConvert();
            secondOperator = _stackArg.top();
            _stackArg.pop();
            mainOperator = _stackArg.top();
            _stackArg.pop();

            leftNb = performSwitch( leftNb, rightNb, secondOperator );
        }
        else{

            mainOperator = _stackArg.top();
            _stackArg.pop();
        }
        result = performSwitch( result, leftNb, mainOperator );
    }
    return result;
}

const char* RPN::DivideByZero::what( void )const throw() { return "Can't divide by Zero, aborting RPN"; }

RPN::~RPN( void ){}