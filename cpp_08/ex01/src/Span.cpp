/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:45:09 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 22:49:15 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Unused constructor
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

/**
 * @brief fillInVector create a temp vector,
 * fills it with timebased random generate algorithm
 * and append it to the _mainVector.
 * 
 * @param nbInputs 
 */
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


void    Span::displayVector( void )const {
    
    printNoEndl("{");

    
    for ( ConstIterator it = this->_mainVector.begin() ; it != this->_mainVector.end(); ++it)
    {
        printNoEndl(*it);
        if (it != (this->_mainVector.end() - 1) )
            printNoEndl(", ");
    }
    print("}");
    
}

int Span::shortestSpan( void ){

    if (this->_mainVector.size() > 1){

        std::vector<int> sortedVector(_mainVector);

        std::sort(sortedVector.begin(), sortedVector.end());

        int curNb = 0;
        int nextNb = 0;
        int result = __INT_MAX__;
        
        for ( ConstIterator it = sortedVector.begin(); it != sortedVector.end() - 1; ++it )
        {
            curNb = *it;
            nextNb = *(it + 1);
            if ( result > ( nextNb - curNb ) )
                result = nextNb - curNb;
        }
        return result;
        
    }
    else
        throw VectorTooShort();  
}

/**
 * @brief Longest span actually
 * 
 * @return int 
 */
int Span::longestSpan( void ){

    if (this->_mainVector.size() > 1){
        
        std::vector<int> sortedVector(_mainVector);
        
        std::sort(sortedVector.begin(), sortedVector.end());

        
        int firstValue = *sortedVector.begin();
        
        // end() actually points outside of the vector
        int lastValue = *(sortedVector.end() - 1);
        
        return (lastValue - firstValue);
    }
    else
        throw VectorTooShort();  
}