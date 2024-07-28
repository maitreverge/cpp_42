/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:28:53 by flverge           #+#    #+#             */
/*   Updated: 2024/07/28 17:57:15 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

template < typename T >
class MutanStack : public std::stack<T>
{
    private:
    
        // some private members
        
    protected:
    
        // some protected members
        
    public:
    
        MutanStack( void ) : std::stack<T> {};
        MutanStack( const MutanStack& copy ) { *this = copy };
        MutanStack& operator=( const MutanStack& right_operator ){
            if (this != right_operator)
                std::stack::opera
        };
        ~MutanStack( void );
};

// Functions declarations

// Default constructor
// template < typename T >
// MutanStack<T>::MutanStack( void ) : std::stack<T>{}

// template < typename T >
// MutanStack<T>::MutanStack( const MutanStack& copy ){

//     // ! TO DO depending on what's in the class
// }

MutanStack& MutanStack::operator=( const MutanStack& right_operator ){

    
    // ! TO DO depending on what's in the class
}

MutanStack::~MutanStack( void ){}

// it ++