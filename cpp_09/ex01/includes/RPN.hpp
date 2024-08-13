/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:31:02 by flverge           #+#    #+#             */
/*   Updated: 2024/08/13 11:17:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class RPN
{

private:

    RPN( void );
    RPN& operator=( const RPN& right_operator );
    
    std::stack<char>    _stackArg;
    string              _promptARGV;

public:

    RPN( string input );
    RPN( const RPN& copy );
    ~RPN();

    class DivideByZero : public exception
    {
        virtual const char* what() const throw();   
    };

    void    parseStack( void );

    int     printResult( void );

};


// ---------- Functions declarations ---------------


RPN::RPN( void ){}

RPN::RPN( string input ) :
    _promptARGV(input){}


RPN::RPN( const RPN& copy ) :
    _promptARGV(copy._promptARGV) {}


RPN& RPN::operator=( const RPN& right_operator ){ static_cast<void>(right_operator); return *this; }

void    RPN::parseStack( void ){

    std::string::iterator it_begin = this->_promptARGV.begin();
    std::string::iterator it_end = this->_promptARGV.end();
    
    // Erase all whitespaces
    this->_promptARGV.erase(std::remove_if(it_begin, it_end, ::isspace ),it_end );

    print(_promptARGV);
    // push each element in the stack in reverse order

    for (std::string::iterator it = _promptARGV.end() - 1; it >= _promptARGV.begin(); --it)
    {
        _stackArg.push(*it);
    }

    // print(_stackArg.top());
    // _stackArg.pop();
    // print(_stackArg.top());
    // _stackArg.pop();
    // print(_stackArg.top());
    // _stackArg.pop();
    // print(_stackArg.top());
    // _stackArg.pop();
    // print(_stackArg.top());
 
 
}

int     RPN::printResult( void ){

    char mainOperator;
    char secondOperator;
    
    int leftNb = 0, rightNb = 0, result = 0, tempResult = 0;

    // Pop the first 3 elements of the stack
    
    leftNb = _stackArg.top() - 48;
    _stackArg.pop();
    rightNb = _stackArg.top() - 48;
    _stackArg.pop();
    mainOperator = _stackArg.top();
    _stackArg.pop();

    switch (mainOperator)
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

    while ( _stackArg.size() > 0 ){

        leftNb = _stackArg.top() - 48;
        _stackArg.pop();

        // Double operators edge case
        if ( std::isdigit( _stackArg.top())){
            
            // edge case if RPN got two consecutives numbers
            
            rightNb = _stackArg.top() - 48;
            _stackArg.pop();
            secondOperator = _stackArg.top();
            _stackArg.pop();
            mainOperator = _stackArg.top();
            _stackArg.pop();

            // make the maths for temp result :

            switch (secondOperator)
            {
                case '+':
                    tempResult = leftNb + rightNb;
                    break;
                case '-':
                    tempResult = leftNb - rightNb;
                    break;
                case '*':
                    tempResult = leftNb * rightNb;
                    break;
                case '/':
                    if (rightNb == 0)
                        throw DivideByZero();
                    tempResult = leftNb / rightNb;
                    break;
            }
            leftNb = tempResult;
        }
        else{

            mainOperator = _stackArg.top();
            _stackArg.pop();
        }
        
        switch (mainOperator)
        {
            case '+':
                result += leftNb;
                break;
            case '-':
                result -= leftNb;
                break;
            case '*':
                result *= leftNb;
                break;
            case '/':
                if (leftNb == 0)
                    throw DivideByZero();
                result /= leftNb;
                break;
        }
    }

    return result;
}

const char* RPN::DivideByZero::what( void )const throw() { return "Can't divide by Zero, aborting RPN"; }

RPN::~RPN( void ){}

