/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_default_type.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:43:12 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/24 13:04:10 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


// We can specify a default value to template if not specified
template< typename T = int >
const T &min( const T &x, const T &y ){

    return (x <= y ? x : y );
}

// We can also specify multiple typenames
template< typename T, typename U >
const T &max( const T &x, const U &y ){

    return (x >= y ? x : y );
}

int main(void){

    int a = 21;
    int b = 42;

    // For calling a default type
    std::cout << min<>(a, b) << std::endl;

    // For calling a multiple default types
    std::cout << max<int, float>(a, b) << std::endl;
    
}