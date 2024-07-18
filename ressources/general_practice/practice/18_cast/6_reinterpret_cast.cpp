/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_reinterpret_cast.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:50:14 by flverge           #+#    #+#             */
/*   Updated: 2024/07/18 11:55:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
! reinterpret cast

Le cast le + permissif, permet de reinterpreter n'importe quelle adresse vers une autre adresse

Un cas d'utilisation courant est un retypage.

reception de donnees brutes dans un void*, qui permet de stocker les donnees brutes.

Reinterpret cast va permettre de redefinir ce que signifie ces donnes et donc permettre
une flexibilite quant a la reinterpretation des donnes.
*/

int main(void){

    float a = 420.042f;

    void* b = &a;

    int* c = reinterpret_cast<int*>(b); 
    int& d = reinterpret_cast<int&>(b);
}