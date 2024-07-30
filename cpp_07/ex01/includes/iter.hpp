/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:48:59 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/30 09:36:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"

template< typename T >
void    theFunctionTemplate( T &a){

    (void)(a);

    printColor(BOLD_RED, "Default instance will do nothing");
}

template<>
void    theFunctionTemplate<int>( int &a ){

    
    printColor(BOLD_YELLOW, "Value of int number before function");

    cout << a << endl;

    a++;

    printColor(BOLD_GREEN, "Value of int number after function");
    
    
    cout << a << endl;
    
}

template<>
void    theFunctionTemplate<float>( float &a ){

    
    printColor(BOLD_CYAN, "Value of float number before function");

    cout << a << endl;

    a -= 0.1f;

    printColor(BOLD_GREEN, "Value of float number after function");
    
    
    cout << a << endl;
    
}

template<>
void    theFunctionTemplate<string>( string &a ){

    
    printColor(BOLD_YELLOW, "Value of int number before function");

    cout << a << endl;

    a[0] = '_';

    printColor(BOLD_GREEN, "Value of int number after function");
    
    
    cout << a << endl;
    
}

template< typename T >
void    iter( T *adress, int lenghArray, void(function)(T &) ){
    

    print("The adress given is :");
    
    cout << adress << endl;

    for (int i = 0; i < lenghArray; i++)
    {
        function( adress[i] );
    }
    
}