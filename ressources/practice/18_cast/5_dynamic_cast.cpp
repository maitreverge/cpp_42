/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_dynamic_cast.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:10:17 by flverge           #+#    #+#             */
/*   Updated: 2024/07/23 11:36:19 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;
/*
! DYNAMIC CAST
Le dynamic_cast est le seul cast qui est un runt_time cast.

Les autre cast sont a la compilation.

Le dynamic cast va donc avoir lieu a l'execution, donc peut echouer.

Il faut donc faire de la gestion d'erreur.

2 : il ne va fonctionner que dans le cadre d'une instance polymorphique
=> l'une des fonction membre doit etre virtuelle

!3 : le dynamic_cast s'utlise UNIQUEMENT dans le cas d'un downcast, et verifier si ce donwncast est possible ou pas

! 4 : le dynamic_cast va pouvoir UNIQUEMENT fonctionner sur des cast de pointeur ou de reference





*/

class Base
{
    public:
    virtual ~Base(void){}
};
class A : public Base{};
class B : public Base{};

class Random{};

int main(void){

    A a; // Reference value

    Base* b = &a; // Implicit upcast

    A* c = dynamic_cast<A*>(b);

    /*
    Dans le cas ou le dynamic cast essaie de downcaster, il peut renvoyer NULL si le dynamic_cast echoue
    */
    if (c == NULL)
        cout << "Conversion is not OKAY"  << endl;
    else
        cout << "Conversion is OKAY"  << endl;        

    try{
        B & d = dynamic_cast<B &>(*b);
        cout << "Conversion is OKAY" << endl;
    }
    catch(std::bad_cast &bc){
        cout << "Conversion is OKAY"  << bc.what() <<  endl;        
        return 0;
        
    }
    return 0;
    
}