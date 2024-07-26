/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_cast_operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:20:31 by flverge           #+#    #+#             */
/*   Updated: 2024/07/18 13:35:03 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

/*
The operator keyword in this example, will allows us to initialize
a simple variable with the value of the private variable.

*/

class Foo
{
private:
    float _v;
    int _k;
    
public:
    Foo(const float v, const int k ) : _v(v), _k(k){};

    // float getV( void ) {return this->_v;}

    operator float() {return this->_v;}
    // operator int() {return static_cast<int>(this->_v);}
    operator int() {return this->_k;}
};


int main(void){

    Foo hehe(420.042f, 888);

    float a = hehe;

    int b = hehe;

    cout << "Valeur de a = " << a << endl;
    cout << "Valeur de b = " << b << endl;
}