/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:24:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 19:41:18 by ubuntu           ###   ########.fr       */
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

    void    addNumber( int inputNumber );

    void    fillInVector( unsigned int nbInputs );

    void    displayVector( void )const;

    // Size Input Exception
    class NullSizeInput : public exception
    {
        virtual const char* what() throw(){
            return "Input Can't Be Null";
        } 
    };

    class FullVector : public exception
    {
        virtual const char* what() throw(){
            return "Vector is Full";
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

void    Span::addNumber( int inputNumber ){

    if (_mainVector.size() < _size )
        _mainVector.push_back(inputNumber);
    else
        throw FullVector();
}

void    Span::fillInVector( unsigned int nbInputs ){

     if (_size < this->_mainVector.size() + nbInputs){
        
        
        
    } 
    else
        throw FullVector();
    
}

typedef std::vector<int>::const_iterator ConstIterator;

void    Span::displayVector( void )const {
    
    print("[  ");

    
    for ( ConstIterator it = this->_mainVector.begin() ; it != this->_mainVector.end(); ++it)
    {
        cout << *it << " " << endl;
    }
    print("  ]");
    
}


// ostream& operator<<( ostream& output_stream, const Span& right_input ){

//     // output_stream << right_input.PutAGetterFunctionhere();

//     return output_stream;
// }
