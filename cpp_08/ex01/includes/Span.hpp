/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:24:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 18:03:21 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class Span
{

private:

    Span( void );
    std::vector<int>    _mainVector;
    unsigned int        _size;

public:

    Span ( unsigned int sizeInput );
    Span( const Span& copy );
    Span& operator=( const Span& right_operator );
    ~Span();

    void checksize (void) { cout << _mainVector.max_size() << endl;}

    // Size Input Exception
    class NullSizeInput : public exception
    {
        virtual const char* what() throw(){
            return "Input Can't Be Null";
        } 
    };

};

// ostream& operator<<( ostream& output_stream, const Span& input );


// ---------- Functions declarations ---------------


Span::Span( void ){}

Span::Span( unsigned int sizeInput ) :
    _size(sizeInput) {
        
    if (!sizeInput)
        throw NullSizeInput();
}

Span::Span( const Span& copy ) :
    _mainVector(copy._mainVector),
    _size(copy._size){}


Span& Span::operator=( const Span& right_operator ){

   if (this != &right_operator){

        this->_mainVector.erase(_mainVector.begin(), _mainVector.end()); // really usefull
        this->_mainVector = right_operator._mainVector;
        
        this->_size = right_operator._size;
    }
    return *this;
}


Span::~Span( void ){

    // maybe erase vector ??
}


// ostream& operator<<( ostream& output_stream, const Span& right_input ){

//     // output_stream << right_input.PutAGetterFunctionhere();

//     return output_stream;
// }
