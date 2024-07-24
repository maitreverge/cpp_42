/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:18:23 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/24 14:45:30 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    cout << "a = " << a << ", b = " << b << endl;
    cout << "min( a, b ) = " << ::min( a, b ) << endl;
    cout << "max( a, b ) = " << ::max( a, b ) << endl;
    string c = "chaine1";
    string d = "chaine2";
    ::swap(c, d);
    cout << "c = " << c << ", d = " << d << endl;
    cout << "min( c, d ) = " << ::min( c, d ) << endl;
    cout << "max( c, d ) = " << ::max( c, d ) << endl;
    return 0;
}