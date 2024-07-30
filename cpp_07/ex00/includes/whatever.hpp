/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:18:18 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/30 13:26:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"
// Implement swap function
template<typename T>
void    swap( T &a, T &b ){

    // Temp value of type T to temporaly hold values
    T temp;

    temp = a;

    a = b;

    b = temp;
}

// Implement min function
template<typename U>
const U &min ( const U &a, const U &b ){

    return (a < b) ? a : b;
}

// Implement max function
template<typename V>
const V &max ( const V &a, const V &b ){

    return ( a > b) ? a : b;
}
