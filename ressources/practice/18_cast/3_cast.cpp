#include <iostream>
/*
Work with casting
*/

class Animal{};
class Dog : public Animal{};
class Cat : public Animal{};

/*
In a way, the Dog and Cat classes are more specialized than the Animal one,
which can be considered as 

*/

int main(void){

    Dog a;

    Animal* b = &a; // Implicit reinterpretation cast

    Animal* c = (Animal*) &a; // explicit reinterpretation cast

    Animal* d = &a; // An Animal Pointer can be a Dog

    Dog* e = d; // A Dog* can't be neceseraly an Animal

    Cat* f = (Cat *)d;
    
    /*
    
    d variable is a Dog*, but still can be casted in a Cat*
    Because Cat and DOG are both derived from Animal, we clearly understand that
    A Dog can't be interpreted as a Cat, because those two class are very different
    
    */


    
}