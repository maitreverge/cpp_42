/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_static_cast.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:52:54 by flverge           #+#    #+#             */
/*   Updated: 2024/07/18 10:05:27 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){

    int a = 42; // valeur de reference

    double b = a; // Implicit promotion
    int c = b; // Implicit demotion, could be problematic
    int d = static_cast<int>(b); // Demotion explicite
}

/*
! 5 types de cast possibles
- Conversions
- reinterpretation
- Changement de type qualifiers
- Downcast
- Upcast

*/

class Parent{};
class Child1 : public Parent{};
class Child2 : public Parent{};

class Random{};

int main(void){

    Child1 a; // Reference value

    Parent* b = &a; // Implicit upcast

    Child1 c = b; // Implicit downcast -> NOOOOOOOOOOO

    Child2* d = static_cast<Child2*>(b); // explicit downcast, mmmmmmmmmmmmmmokay

    Random* e = static_cast<Random*>(&a); // Explicit conversion, NOOOOOOO

    /*
    ! STATIC CAST
    Le static cast nous permet de upcast ET de downcast des classes dans un meme arbre d'heritage
    ! MAIS
    nous empeche de caster des classes qui ne sont pas dans le meme arbre d'heritage
    */
    
}