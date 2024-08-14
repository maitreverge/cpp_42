/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:44:12 by flverge           #+#    #+#             */
/*   Updated: 2024/08/14 12:58:00 by flverge          ###   ########.fr       */
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
    
    std::list<int>      _listContainer;
    std::clock_t        _timeStartList;
    std::clock_t        _timeEndList;


public:

    PmergeMe( char **av );
    ~PmergeMe();

    void    printVector( string input );
    void    printList( string input );

	void    printTimeExecution( string input );

    void    sortVector( void );
    void    sortList( void );

};

// ---------- Functions declarations ---------------


PmergeMe::PmergeMe( void ){}

/**
 * @brief Construct a new Pmerge Me
 * 
 * and append the arguments to both the vector and the list.
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
        _listContainer.push_back( std::atoi(av[i]) );
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

void PmergeMe::printList( string input ){

    if (input == "Before")
        printColor(BOLD_YELLOW, "List before sort :");
    else
        printColor(BOLD_GREEN, "List after sort :");
    
    // We need to use a temp iterator instead of _listContainer.end() - 1
    std::list<int>::iterator tempIt;
    for ( std::list<int>::iterator it = _listContainer.begin(); it != _listContainer.end() ; ++it )
    {
        tempIt = it;
        tempIt++;
        
        printNoEndl(*it);
        if (tempIt != _listContainer.end())
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

        printColorNoEndl(BOLD_BLUE, "Time to process sort with std::list = ");
        printColor(BOLD_GREEN, static_cast<double>(_timeEndList - _timeStartList) / CLOCKS_PER_SEC);
    }
    
    extraLine();
}

void    PmergeMe::sortVector( void ){

    // Clock in
    this->_timeStartVector = std::clock();

    sleep(3);
    // Clock out
    this->_timeEndVector = std::clock();
}

void    PmergeMe::sortList( void ){

    // Clock in
    this->_timeStartList = std::clock();

    
    sleep(3);
    // Clock out
    this->_timeEndList = std::clock();
}




PmergeMe::PmergeMe( const PmergeMe& copy ) {*this = copy;}


PmergeMe& PmergeMe::operator=( const PmergeMe& right_operator ){ static_cast<void>(right_operator); return *this; }


PmergeMe::~PmergeMe( void ){}