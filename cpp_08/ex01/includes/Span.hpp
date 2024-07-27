/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:24:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 20:39:49 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

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

    int     getRand( void )const;

    // Size Input Exception
    class NullSizeInput : public exception
    {
        public:
            virtual const char* what() const throw(){
                return "Input Can't Be Null";
        } 
    };

    class FullVector : public exception
    {
        public:
            virtual const char* what() const throw(){
                return "Vector is Full";
        } 
    };

};

// ostream& operator<<( ostream& output_stream, const Span& input );


// ---------- Functions declarations ---------------


Span::Span( void ){}

Span::Span( unsigned int sizeInput ) :
    _sizeMax(sizeInput) {
        
    if (!sizeInput)
        throw NullSizeInput();
}

Span::Span( const Span& copy ) :
    _mainVector(copy._mainVector),
    _sizeMax(copy._sizeMax){}


Span& Span::operator=( const Span& right_operator ){

   if (this != &right_operator){

        // Erasing the first vector
        this->_mainVector.erase(_mainVector.begin(), _mainVector.end());

        // Assigning the r_o to the actual vector
        this->_mainVector = right_operator._mainVector;
        
        this->_sizeMax = right_operator._sizeMax;
    }
    return *this;
}


Span::~Span( void ){}

void    Span::addNumber( int inputNumber ){

    if (_mainVector.size() < _sizeMax )
        _mainVector.push_back(inputNumber);
    else
        throw FullVector();
}

void    Span::fillInVector( unsigned int nbInputs ){

    if (_sizeMax >= this->_mainVector.size() + nbInputs){
        
        std::vector<int> temp(nbInputs);
        
        // Putting sed as a static value, and incrementing it.
        // If not incremented, I'd end up with the same vectors in several class instances.
        
        static unsigned int sed = static_cast<unsigned int>(std::time(NULL));
        std::srand(sed);
        sed++;
        
        // Generating a random number for each position, from begin to end
        std::generate(temp.begin(), temp.end(), std::rand);

        _mainVector.insert(_mainVector.end(), temp.begin(), temp.end());
        
    } 
    else
        throw FullVector();
    
}

int    Span::getRand( void )const {
    
    
    return rand();
}

typedef std::vector<int>::const_iterator ConstIterator;

void    Span::displayVector( void )const {
    
    printNoEndl("[  ");

    
    for ( ConstIterator it = this->_mainVector.begin() ; it != this->_mainVector.end(); ++it)
    {
        cout << *it << " ";
    }
    print("  ]");
    
}


// ostream& operator<<( ostream& output_stream, const Span& right_input ){

//     // output_stream << right_input.PutAGetterFunctionhere();

//     return output_stream;
// }
