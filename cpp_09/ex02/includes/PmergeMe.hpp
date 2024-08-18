/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:44:12 by flverge           #+#    #+#             */
/*   Updated: 2024/08/18 18:46:54 by ubuntu           ###   ########.fr       */
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

    long    calculateJacobsthal( int i, std::vector< unsigned long long > &jacob );

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

long    PmergeMe::calculateJacobsthal( int i, std::vector< unsigned long long > &jacob ){

    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    
    return ( jacob[i - 1] + (2 * jacob[i - 2]) ); // Switch from reference to recursive
    
}

void    PmergeMe::sortVector( void ){
    // Clock in
    this->_timeStartVector = std::clock();

    // STEP 1: If there is an odd number in the vector, push it away
    bool isStruggle = false;
    int struggle;

    if (_vectorContainer.size() % 2 != 0) {
        isStruggle = true;
        struggle = *(_vectorContainer.end() - 1);
        _vectorContainer.pop_back();
    }

    // STEP 2: Make pairs of two numbers from the original vector
    std::vector<std::pair<int, int> > pairedVector;

    // Init the double vector and swap the values of big and small number if necessary
    for (std::vector<int>::iterator it = _vectorContainer.begin(); it != _vectorContainer.end(); ++it) {
        int bigNb = *it;
        int smallNb = *(++it);
        if (bigNb < smallNb)
            std::swap(bigNb, smallNb);
        pairedVector.push_back(std::make_pair(bigNb, smallNb));
    }

    // STEP 3: Create two vectors of both big and small numbers
    std::vector<int> bigNumbers; // the big numbers need to be sorted
    std::vector<int> smallNumbers;

    for (std::vector<std::pair<int, int> >::iterator it = pairedVector.begin(); it != pairedVector.end(); ++it) {
        int big = it->first;
        int small = it->second;
        
        bigNumbers.push_back(big);
        smallNumbers.push_back(small);
    }

    // Sort the first array
    std::sort(bigNumbers.begin(), bigNumbers.end());

    // Insert the first element of smallNumbers into bigNumbers
    // bigNumbers.insert(bigNumbers.begin(), smallNumbers.front());
    // smallNumbers.erase(smallNumbers.begin());

    // Calculate Jacobsthal numbers
    std::vector< unsigned long long > jacobsthalNumbers;
    int n = smallNumbers.size();
    
    for (int i = 0; i < n; ++i) {
        
        unsigned long long jacobsthal = calculateJacobsthal(i, jacobsthalNumbers);
        jacobsthalNumbers.push_back(jacobsthal);
    }

    // Merge the remaining smallNumbers into bigNumbers using Jacobsthal numbers
    for (size_t i = 0; i < jacobsthalNumbers.size(); ++i) {
        
        size_t pos = jacobsthalNumbers[i];
        if (pos < smallNumbers.size()) {
            std::vector<int>::iterator insertPos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), smallNumbers[pos]);
            bigNumbers.insert(insertPos, smallNumbers[pos]);
        }
    }

    // If there was an odd number of elements, insert the struggle element
    if (isStruggle) {
        
        std::vector<int>::iterator pos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), struggle);
        bigNumbers.insert(pos, struggle);
    }

    // Replace the original vector with the sorted vector
    this->_vectorContainer = bigNumbers;

    // Print the sorted bigNumbers
    print("Sorted numbers:");
    for (std::vector<int>::iterator it = bigNumbers.begin(); it != bigNumbers.end(); ++it) {
        print(*it);
    }

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