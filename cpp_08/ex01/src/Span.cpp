/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:45:09 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 23:34:54 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Unused constructor
Span::Span( void ){}

/**
 * @brief Construct a new Span:: Span object
 * 
 * Throws an error with NULL input.
 * 
 * @param sizeInput 
 */
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


/**
 * @brief Function `push_back` the given number to the vector `_mainVector`.
 * 
 * Throws an error if vector size is alrealy or over `_sizeMax`
 * 
 * @param inputNumber 
 */
void    Span::addNumber( int inputNumber ){

    if (_mainVector.size() < _sizeMax )
        _mainVector.push_back(inputNumber);
    else
        throw FullVector();
}

/**
 * @brief fillInVector create a temp vector of size `nbInputs`,
 * fills it with timebased random generate algorithm
 * and append it to the _mainVector.
 * 
 * Function throws an error if size of `_mainVector` could
 * be exceded by the function call.
 * 
 * @param nbInputs 
 */
void    Span::fillInVector( unsigned int nbInputs ){

    if (_sizeMax >= this->_mainVector.size() + nbInputs){
        
        std::vector<int> temp(nbInputs);
        
        // I choose to put sed as a static value, and incrementing it at each method call.
        // If not incremented, I'd end up with the same vectors accross several class instances.
        
        static unsigned int sed = static_cast<unsigned int>(std::time(NULL));
        std::srand(sed);
        sed++;
        
        // Generating a random number for each position, from begin to end
        std::generate(temp.begin(), temp.end(), std::rand);
        
        // Append at the end of _mainVector the temp vector created and filled.
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
/**
 * @brief Shortest Span will alway be calculated on the sorted vector
 * between the actual iterator and the next one.
 * 
 * If such result is shorter than the actual `result` init to __INT_MAX__, store the result
 * 
 * Once the vector is fully compared, return the result.
 * 
 * @return int 
 */
int Span::shortestSpan( void ){

    if (this->_mainVector.size() > 1){

        std::vector<int> sortedVector(_mainVector);

        std::sort(sortedVector.begin(), sortedVector.end());

        int curNb = 0; // Value of the actual iterator
        int nextNb = 0; // Value of the following iterator
        int result = __INT_MAX__;
        
        // Loop stop 1 step before .end(), because .end() actually points outside the vector
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
 * @brief Longest span actually returns the max element minus the minimum element.
 * 
 * @return int 
 */
int Span::longestSpan( void ){

    if (this->_mainVector.size() > 1){
        
        int max = *(std::max_element(_mainVector.begin(), _mainVector.end()));
        int min = *(std::min_element(_mainVector.begin(), _mainVector.end()));

        return (max - min);
    }
    else
        throw VectorTooShort();  
}