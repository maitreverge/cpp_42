/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idFunctions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:24:46 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/23 12:47:03 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){

	srand(time(NULL)); // seed time in rand() to achieve true randomness

    int value = rand() % 3;

    switch (value)
    {
    case 0:
        {
        printColor(BOLD_GREEN, "A Class has been randomly generated");
        A *baseA = new A;
        return baseA;
        }
    case 1:
        {
        printColor(BOLD_GREEN, "B Class has been randomly generated");
        B *baseB = new B;
        return baseB;
        }
    }

    // This statement was in switch statement scope,
    // I put it out to return at least smth.
    printColor(BOLD_GREEN, "C Class has been randomly generated");
    C *baseC = new C;
    return baseC;
}

void identify(Base* p){
    
    A *baseA = dynamic_cast<A*>(p);
    B *baseB = dynamic_cast<B*>(p);
    C *baseC = dynamic_cast<C*>(p);
    
    if (baseA != NULL)
        printColor(BOLD_GREEN, "The Given pointer is of type A class");
    else if (baseB != NULL)
        printColor(BOLD_GREEN, "The Given pointer is of type B class");
    else if (baseC != NULL)
        printColor(BOLD_GREEN, "The Given pointer is of type C class");
}

void identify(Base& p){

    /*
    In this function, <typeinfo> header was forbidden.
    Then, I could not direclty catch exceptions of type bad_cast like
    !                          catch( std::bad_cast &e)
    Because bad_cast if a derived class from exceptions, I just had to catch any exception

    For proving that I really catch exceptions of type bad_cast, uncomment the lines 
    !                      std::cerr << e.what() << endl;
    
    within the catch statements
    
    see : https://en.cppreference.com/w/cpp/types/bad_cast
    */
    try
    {
        A &baseA = dynamic_cast<A&>(p);
        printColor(BOLD_GREEN, "Given reference is of type A");
        (void)(baseA);
        return;
    }
    catch( std::exception &e)
    {
        printColor(BOLD_RED, "Given reference is not of type A");
        // std::cerr << e.what() << endl;
    }
    

    try
    {
        B &baseB = dynamic_cast<B&>(p);
        printColor(BOLD_GREEN, "Given reference is of type B");
        (void)(baseB);
        return;
    }
    catch( std::exception &e)
    {
        printColor(BOLD_RED, "Given reference is not of type B");
        // std::cerr << e.what() << endl;
    }

    try
    {
        C &baseC = dynamic_cast<C&>(p);
        printColor(BOLD_GREEN, "Given reference is of type C");
        (void)(baseC);
        return;
    }
    catch( std::exception &e)
    {
        printColor(BOLD_RED, "Given reference is not of type C");
        // std::cerr << e.what() << endl;
    }
    
    return;
}