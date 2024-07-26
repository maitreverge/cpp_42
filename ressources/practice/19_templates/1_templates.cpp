/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:11:23 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/24 11:36:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
L'idee derriere les templates est de creer du code a trou
que le compilateur va pouvoir ainsi remplacer et generer

*/

// Prennons la syntaxe d'une fonction max avec un retour ternaire
int max( int x, int y){

    return (x >= y ? x : y);
}

// L'idee est de remplacer le type int par un type T,
// Cependant, dans l'etat, cela ne peut pas compiler

T max( T x, T y){

    return (x >= y ? x : y);
}


// Nous allons donc specifier un template, avec un typename T (qui est une convention)

template<typename T>
T max( T x, T y){

    return (x >= y ? x : y);
}


// Il peut etre judicieux de les passer par reference, si jamais nous faison appel a des lourdes instances de classes

template<typename T>
T max( T &x, T &y){

    return (x >= y ? x : y);
}


// Pour des raisons de securite, nous pouvons "constifier" le code, mais pour
//illustrer les template, ce n'est absolument pas obligatoire

template<typename T>
const T& max( const T &x, const T &y){

    return (x >= y ? x : y);
}


// Pour appeler la fonction, C++ nous propose deux choix

int main(void)
{

    int a = 21;
    int b = 42;

    // Explicit instanciation
    std::cout << "Maximum between a and b is " << max<int>(a, b) << std::endl;

    
    // Implicit instanciation
    std::cout << "Maximum between a and b is " << max(a, b) << std::endl;
}

