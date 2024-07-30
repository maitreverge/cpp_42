/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:35:26 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/30 09:36:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void){

    int arrayInt[5] = {4, -9, 42, -12, 0};
    
    float arrayFloat[5] = {4.42f, -9.9f, 42.42f, -12.12f, 0.0f};

    string arrayString[5] = {"Heap is Better",
                            "Stack is Better",
                            "Elon Musk is Better",
                            "Jeff Bezos is better",
                            "Nutella is better with butter"};

    double arrayNope[5] = {4.33, -9.7, 42.2, -12.1, 0.9};
    
    iter<int>(arrayInt, 5, *theFunctionTemplate<int>);
    iter<float>(arrayFloat, 5, *theFunctionTemplate<float>);
    iter<string>(arrayString, 5, *theFunctionTemplate<string>);
    iter<double>(arrayNope, 5, *theFunctionTemplate<double>);
}