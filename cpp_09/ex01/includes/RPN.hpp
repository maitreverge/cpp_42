/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:31:02 by flverge           #+#    #+#             */
/*   Updated: 2024/08/07 10:51:10 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class RPN
{

private:

    RPN& operator=( const RPN& right_operator );
    
    const string        _promptARGV;
    std::stack<char>    _stackArg;

public:

    RPN( void );
    RPN( string input );
    RPN( const RPN& copy );
    ~RPN();

};


// ---------- Functions declarations ---------------


RPN::RPN( void ){}

RPN::RPN( string input) :
    _promptARGV(input){}


RPN::RPN( const RPN& copy ) :
    _promptARGV(copy._promptARGV) {}


RPN& RPN::operator=( const RPN& right_operator ){ static_cast<void>(right_operator); return *this; }


RPN::~RPN( void ){}

