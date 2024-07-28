/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:28:53 by flverge           #+#    #+#             */
/*   Updated: 2024/07/28 18:35:49 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "MutantStack.tpp"

template < typename T >
class MutantStack : public std::stack<T>
{
    typedef typename std::stack<T>::container_type::iterator Iterator;
    private:
    
        // some private members
        
    protected:
    
        // some protected members
        
    public:
    
        MutantStack( void );
        
        MutantStack( const MutantStack& copy );
        
        MutantStack& operator=( const MutantStack& right_operator );
        
        ~MutantStack( void );

        Iterator begin();
	    Iterator end();
};
