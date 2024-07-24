/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:35:26 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/24 18:24:24 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void){

    int lenght = 5;

    int arrayInt[lenght] = {4, -9, 42, -12, 0};
    
    float arrayFloat[lenght] = {4.42f, -9.9f, 42.42f, -12.12f, 0.0f};

    string arrayString[lenght] = {"Heap is Better",
                            "Stack is Better",
                            "Elon Musk is Better",
                            "Jeff Bezos is better",
                            "Nutella is better with butter"};

    double arrayNope[lenght] = {4.33, -9.7, 42.2, -12.1, 0.9};
    
    iter<int>(arrayInt, lenght, *theFunctionTemplate<int>);
    iter<float>(arrayFloat, lenght, *theFunctionTemplate<float>);
    iter<string>(arrayString, lenght, *theFunctionTemplate<string>);
    iter<double>(arrayNope, lenght, *theFunctionTemplate<double>);
}