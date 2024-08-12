/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:31:02 by flverge           #+#    #+#             */
/*   Updated: 2024/08/12 15:57:48 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class RPN
{

private:

    RPN( void );
    RPN& operator=( const RPN& right_operator );
    
    string        _promptARGV;
    std::stack<char>    _stackArg;

public:

    RPN( string input );
    RPN( const RPN& copy );
    ~RPN();

    void    parseStack( void );

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

    print(_stackArg.top());
    _stackArg.pop();
    print(_stackArg.top());
 
 
}

RPN::~RPN( void ){}

