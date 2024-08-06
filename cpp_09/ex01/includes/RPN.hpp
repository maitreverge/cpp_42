/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:31:02 by flverge           #+#    #+#             */
/*   Updated: 2024/08/06 15:57:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class RPN
{

private:

    RPN( void );
    RPN& operator=( const RPN& right_operator );
    
    const string _promptARGV;
    // probably a stack

public:

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

