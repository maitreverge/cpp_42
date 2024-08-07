/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:24:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 23:28:52 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

typedef std::vector<int>::const_iterator ConstIterator;

class Span
{

private:

    Span( void );
    std::vector<int>    _mainVector;
    unsigned int        _sizeMax;

public:

    Span ( unsigned int sizeInput );
    Span( const Span& copy );
    Span& operator=( const Span& right_operator );
    ~Span();

    void    addNumber( int inputNumber );

    void    fillInVector( unsigned int nbInputs );

    void    displayVector( void )const;

    int     shortestSpan();
    
    int     longestSpan();

    // ---------- Exceptions ----------
    class NullSizeInput : public exception
    {
        public:
            virtual const char* what() const throw(){
                return "Input can't be NULL.";
        } 
    };

    class FullVector : public exception
    {
        public:
            virtual const char* what() const throw(){
                return "Vector is Full.";
        } 
    };

    class VectorTooShort : public exception
    {
        public:
            virtual const char* what() const throw(){
                return "Vector is too short to calculate both SPANs.";
        } 
    };

};