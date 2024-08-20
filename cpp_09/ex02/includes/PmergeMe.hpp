/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:44:12 by flverge           #+#    #+#             */
/*   Updated: 2024/08/20 10:43:18 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

template < typename Container >
class PmergeMe
{

private:

    PmergeMe( void );
    PmergeMe( const PmergeMe& copy );
    PmergeMe& operator=( const PmergeMe& right_operator );

    Container           _mainContainer;
    
    std::clock_t        _timeStart;
    std::clock_t        _timeEnd;

    double              _totalTime;

public:

    PmergeMe( char **av );
    ~PmergeMe();

    void    printContainer( string when, string what );

	void    printTimeExecution( string input );

    void    sortContainer( void );

    long    calculateJacobsthal( int i, std::vector< unsigned long long > &jacob );

    double  getTotalTime( void )const;

};

#include "../src/PmergeMe.tpp"