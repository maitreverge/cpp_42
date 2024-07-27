/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:56:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 22:41:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void){

    Span s1(500);

    s1.fillInVector(100);
    s1.fillInVector(100);
    s1.fillInVector(100);
    s1.fillInVector(100);
    s1.fillInVector(100);

    
    // Subject example
    // s1.addNumber(6);
    // s1.addNumber(3);
    // s1.addNumber(17);
    // s1.addNumber(9);
    // s1.addNumber(11);

    s1.displayVector();

    try
    {
        s1.addNumber(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        s1.fillInVector(10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

   print(s1.shortestSpan());
   
   print(s1.longestSpan());
    
}

