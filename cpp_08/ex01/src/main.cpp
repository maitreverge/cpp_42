/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:56:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 23:27:00 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void){

    // Init a vector with a max_size of 500 ints.
    Span s1(500);

    try
    {
        Span s2(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    s1.fillInVector(100);
    s1.fillInVector(100);
    s1.fillInVector(100);
    s1.fillInVector(100);
    s1.fillInVector(100);

    try
    {
        s1.fillInVector(10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //!          Subject example
    // s1.addNumber(6);
    // s1.addNumber(3);
    // s1.addNumber(17);
    // s1.addNumber(9);
    // s1.addNumber(11);


    try
    {
        s1.addNumber(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    s1.displayVector();

    print(s1.shortestSpan());
   
    print(s1.longestSpan());
    
}

