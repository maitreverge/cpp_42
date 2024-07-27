/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:56:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/27 21:34:45 by ubuntu           ###   ########.fr       */
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
    

}

