/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:15:42 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 17:14:18 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

/**
 * @brief Find then first occurence of needle in a container of type int
 * 
 * @tparam T 
 * @param haystack 
 * @param needle 
 * @return int 
 */
template < typename T >
void easyfind( T &haystack, int needle ){
    
    // ! The "easy" way to do it
    // typedef typename T::iterator Iterator;
    // for ( Iterator it = haystack.begin(); it != haystack.end(); ++it ){
        
    //     if (*it == needle){
            
    //         return;
    //     }
    // }

    std::find(haystack.begin(), haystack.end(), needle) != haystack.end()
    ? printColor(BOLD_GREEN, "Needle has been found !")
    : printColor(BOLD_RED, "Needle has not been found !");
    
    return;
}