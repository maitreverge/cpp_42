/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:44:12 by flverge           #+#    #+#             */
/*   Updated: 2024/08/14 14:44:34 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class PmergeMe
{

private:

    PmergeMe( void );
    PmergeMe( const PmergeMe& copy );
    PmergeMe& operator=( const PmergeMe& right_operator );

    std::vector<int>    _vectorContainer;
    std::clock_t        _timeStartVector;
    std::clock_t        _timeEndVector;
    
    std::deque<int>      _dequeContainer;
    std::clock_t        _timeStartDeque;
    std::clock_t        _timeEndDeque;


public:

    PmergeMe( char **av );
    ~PmergeMe();

    void    printVector( string input );
    void    printDeque( string input );

	void    printTimeExecution( string input );

    void    sortVector( void );
    void    sortDeque( void );

};

// ---------- Functions declarations ---------------


PmergeMe::PmergeMe( void ){}

/**
 * @brief Construct a new Pmerge Me
 * 
 * and append the arguments to both the vector and the deque.
 * 
 * @param av 
 */
PmergeMe::PmergeMe( char **av ){

    for ( size_t i = 0; av[i]; ++i )
	{
		_vectorContainer.push_back( std::atoi(av[i]) );
	}

    for ( size_t i = 0; av[i]; ++i )
    {
        _dequeContainer.push_back( std::atoi(av[i]) );
    }
}

void PmergeMe::printVector( string input ){

    if (input == "Before")
        printColor(BOLD_YELLOW, "Vector before sort :");
    else
        printColor(BOLD_GREEN, "Vector after sort :");
    
    
    for ( std::vector<int>::iterator it = _vectorContainer.begin(); it != _vectorContainer.end() ; ++it )
    {
        printNoEndl(*it);
        if (it != _vectorContainer.end() - 1)
            printNoEndl(" - ");
    }

    extraLine();
}

void PmergeMe::printDeque( string input ){

    if (input == "Before")
        printColor(BOLD_YELLOW, "Dequeu before sort :");
    else
        printColor(BOLD_GREEN, "Dequeu after sort :");
    
    // We need to use a temp iterator instead of _dequeContainer.end() - 1
    std::deque<int>::iterator tempIt;
    for ( std::deque<int>::iterator it = _dequeContainer.begin(); it != _dequeContainer.end() ; ++it )
    {
        tempIt = it;
        tempIt++;
        
        printNoEndl(*it);
        if (tempIt != _dequeContainer.end())
            printNoEndl(" - ");
    }

    extraLine();
}

void    PmergeMe::printTimeExecution( string input ){

    extraLine();
    
    if (input == "Vector"){

        printColorNoEndl(BOLD_BLUE, "Time to process sort with std::vector = ");
        printColor(BOLD_GREEN, static_cast<double>(_timeEndVector - _timeStartVector) / CLOCKS_PER_SEC);
    }
    else{

        printColorNoEndl(BOLD_BLUE, "Time to process sort with std::deque = ");
        printColor(BOLD_GREEN, static_cast<double>(_timeEndDeque - _timeStartDeque) / CLOCKS_PER_SEC);
    }

    extraLine();
}

void    PmergeMe::sortVector( void ){

    // Clock in
    this->_timeStartVector = std::clock();

    
    
    // Clock out
    this->_timeEndVector = std::clock();
}

void    PmergeMe::sortDeque( void ){

    // Clock in
    this->_timeStartDeque = std::clock();

    
    sleep(3);
    // Clock out
    this->_timeEndDeque = std::clock();
}




PmergeMe::PmergeMe( const PmergeMe& copy ) {*this = copy;}


PmergeMe& PmergeMe::operator=( const PmergeMe& right_operator ){ static_cast<void>(right_operator); return *this; }


PmergeMe::~PmergeMe( void ){}