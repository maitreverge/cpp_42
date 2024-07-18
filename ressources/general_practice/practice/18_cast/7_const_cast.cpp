/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_const_cast.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:52:55 by flverge           #+#    #+#             */
/*   Updated: 2024/07/18 12:55:03 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main(void){

    int a = 42;

    int *b = &a;

    int *d = const_cast<int*>(&a);

    cout << *d << endl;
}