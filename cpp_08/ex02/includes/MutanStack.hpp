/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:28:53 by flverge           #+#    #+#             */
/*   Updated: 2024/07/28 12:32:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

template < typename TypeOfContainer >
class MutanStack : public std::stack<TypeOfContainer>
{
    private:
    
        // some private members
        
    protected:
    
        // some protected members
        
    public:
    
        MutanStack( void );
        MutanStack( const MutanStack& copy );
        MutanStack& operator=( const MutanStack& right_operator );
        ~MutanStack( void );
};

// Functions declarations

MutanStack::MutanStack( void ){}

MutanStack::MutanStack( const MutanStack& copy ){

    // ! TO DO depending on what's in the class
}

MutanStack& MutanStack::operator=( const MutanStack& right_operator ){

    
    // ! TO DO depending on what's in the class
}

MutanStack::~MutanStack( void ){}

// it ++