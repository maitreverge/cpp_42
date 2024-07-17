/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_cast.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:29:02 by flverge           #+#    #+#             */
/*   Updated: 2024/07/17 09:52:34 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <stdio.h>

using namespace std;

int main(void){
    
    float a = 420.042f;

    void* b = &a; // Implicit reinterpreation cast

    void* c = (void*) &a; // explicit reinterpretation cast

    void* d = &a; // Implicit promotion, from float to void* OKAY

    int* e = d; // Implicit demotion, hazardeous, dangerous and savage.

    
    int* f = (int*)d; // Implicit demotion, hazardeous, dangerous and savage.

    printf("Valeur de a = %f\n", a);
    
    printf("Adresse de a = %p\n", &a);

    printf("Valeur de b = %p\n", b);    
    
    printf("Adresse de c = %p\n", &c);

    printf("Valeur de c = %p\n", c);    
    
    




        

}