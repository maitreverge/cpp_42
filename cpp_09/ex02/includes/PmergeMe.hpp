/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:44:12 by flverge           #+#    #+#             */
/*   Updated: 2024/08/14 09:34:42 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class PmergeMe
{

private:

    PmergeMe( const PmergeMe& copy );
    PmergeMe& operator=( const PmergeMe& right_operator );

public:

    PmergeMe( void );
    ~PmergeMe();

};

// ---------- Functions declarations ---------------


PmergeMe::PmergeMe( void ){}


PmergeMe::PmergeMe( const PmergeMe& copy ) {*this = copy;}


PmergeMe& PmergeMe::operator=( const PmergeMe& right_operator ){ static_cast<void>(right_operator); return *this; }


PmergeMe::~PmergeMe( void ){}