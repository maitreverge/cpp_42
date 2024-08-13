/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:44:12 by flverge           #+#    #+#             */
/*   Updated: 2024/08/13 12:44:33 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class PmergeMe
{

private:

    // Some private members

public:

    PmergeMe( void );
    PmergeMe( const PmergeMe& copy );
    PmergeMe& operator=( const PmergeMe& right_operator );
    ~PmergeMe();

};

ostream& operator<<( ostream& output_stream, const PmergeMe& input );


// ---------- Functions declarations ---------------


PmergeMe::PmergeMe( void ){}


PmergeMe::PmergeMe( const PmergeMe& copy ) :
    foo(copy._foo), // List init each value individually
    bar(copy._bar) {}
    // {*this = copy;} in case of non-member values


PmergeMe& PmergeMe::operator=( const PmergeMe& right_operator ){

   if (this != &right_operator){
        // Reassign every value with the getter value 
        // this->_foo = right_operator.getFoo()
    }
    return *this;
}


PmergeMe::~PmergeMe( void ){}


ostream& operator<<( ostream& output_stream, const PmergeMe& right_input ){

    // output_stream << right_input.PutAGetterFunctionhere();

    return output_stream;
}
