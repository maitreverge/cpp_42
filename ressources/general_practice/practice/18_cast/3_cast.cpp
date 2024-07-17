#include <iostream>
/*
Work with casting
*/

class Parent{};
class Child1 : public Parent{};
class Child2 : public Parent{};

int main(void){

    Parent papa;

    Child1 baby;

    Child2 *test = papa; // won't 


    
}