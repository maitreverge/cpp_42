/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_explicit.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:44:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/19 21:25:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

#include <iostream>

class MyClass {
public:
    MyClass(int x) { 
        value = x; 
    }
    int value;
};

void printValue(const MyClass &obj) {
    std::cout << "Value: " << obj.value << std::endl;
}

int main() {
    MyClass obj1 = 10; // Implicit conversion from int to MyClass
    printValue(20);    // Implicit conversion from int to MyClass
    return 0;
}


// --------------------- WITH EXPLICIT --------------------------------------

/*
In this example, the explicit keyword prevents the compiler from using
the constructor for implicit conversions.
You must explicitly create a MyClass object when assigning or passing an int.
*/

#include <iostream>

class MyClass {
public:
    explicit MyClass(int x) { 
        value = x; 
    }
    int value;
};

void printValue(const MyClass &obj) {
    std::cout << "Value: " << obj.value << std::endl;
}

int main() {
    MyClass obj1 = 10; // Error: no implicit conversion allowed
    MyClass obj2(10);  // Correct: explicit conversion
    printValue(20);    // Error: no implicit conversion allowed
    printValue(MyClass(20)); // Correct: explicit conversion
    return 0;
}


//----------------------------- ANOTHER EXAMPLE -----------------------------

#include <iostream>

class MyClass {
public:
    explicit MyClass(int x) { 
        value = x; 
    }
    int value;
};

void printValue(const MyClass &obj) {
    std::cout << "Value: " << obj.value << std::endl;
}

int main() {
    //MyClass obj1 = 10; // Error: no implicit conversion allowed
    MyClass obj2(10);  // Correct: explicit conversion
    //printValue(20);    // Error: no implicit conversion allowed
    printValue(MyClass(20)); // Correct: explicit conversion

    // Using casting
    int num = 30;
    MyClass obj3 = static_cast<MyClass>(num); // Correct: explicit conversion using static_cast
    printValue(obj3);

    return 0;
}
