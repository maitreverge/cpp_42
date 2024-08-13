/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:31:02 by flverge           #+#    #+#             */
/*   Updated: 2024/08/13 12:34:43 by flverge          ###   ########.fr       */
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

    void    parseStack( void );

    int     printResult( void );

    int     popAndConvert ( void );

    int     performSwitch( int leftNb, int rightNb, char op );

    class DivideByZero : public exception
    {
        virtual const char* what() const throw();   
    };
};