/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:11:31 by flverge           #+#    #+#             */
/*   Updated: 2024/07/16 11:21:11 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// implicit cast

using namespace std;

void hexdump_int(int value) {
    unsigned char* ptr = reinterpret_cast<unsigned char*>(&value);
    for (int i = sizeof(value) - 1; i >= 0; i--) {
        cout << hex << static_cast<int>(ptr[i]) << " ";
    }
    cout << endl;
}

void hexdump_double(double value) {
    unsigned char* ptr = reinterpret_cast<unsigned char*>(&value);
    for (int i = sizeof(value) - 1; i >= 0; i--) {
        cout << hex << static_cast<int>(ptr[i]) << " ";
    }
    cout << endl;
}

int main(void){

    int i = 42;

    double j = i; // same thing infine

    double k = (double)i; // same thing infine

    double l = 42;

    /*
    This kind of thing is called an implicit demotion
    And will throw an compilation error on moderns versions of g++
    */
    int m = l;  

    /*
    However, if losing precision and potential data is okay,
    We can explicitelly cast a bigger variable within a smallest one
    */
    int hehe = (int)l; 

    cout << j << endl;
    
    cout << k << endl;
    
    cout << l << endl;

    cout << m << endl;

    hexdump_double(l);
    hexdump_int(i);



    
}