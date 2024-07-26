/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_vector.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:42:22 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/26 16:54:22 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Vectors are the same as dynamic arrays with the ability to resize themselves
automatically when an element is inserted or deleted, with their storage being handled automatically by the container.
Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.
!       In vectors, data is inserted at the end.
Inserting at the end takes differential time, as sometimes the array may need to be extended.
Removing the last element takes only constant time because no resizing happens.
Inserting and erasing at the beginning or in the middle is linear in time.
*/


#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;

int main(void){

    std::vector<int> v1;

    v1 = {1, 2, 3, 4, 5};


    // We can also declare a vector full of 42, let's say a vector of size 10 with the value 42
    std::vector<int> v2(/*size*/ 10, /* value*/ 42);

    // We can also make a copy constructor
    std::vector<int> v3(v2);



    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
        cout << *it << " ";

        cout << endl;
    
    // begin actually points on the first elements on the vector
    // end actually points to the THEORICAL element following the last element of the vector
    
    // We also got reverse iterators like rbegin and rend

    for(std::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); ++it)
        cout << *it << " ";
    
    cout << endl;
        
    
    for( std::vector<int>::const_reverse_iterator it = v1.crbegin(); it != v1.crend(); ++it){

        cout << *it << " ";
        // v1.insert(v1.begin(), 42);
    }

    /*
    !           CAPACITY
    
    We got methods such as size, capcity, empty, shrink_to_fit
    */

    std::cout << v1.size() << std::endl;
    
    /*
    !           ELEMENTS ACCESS
    
    Operator[]
    at(1) == vector[1]
    */

    cout << v1.at(0) /* equivalent to v1[0] */ << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;

    int * ptrVector = v1.data(); // .data() methods is for accessing the pointer to the first element.

    cout << &v1[0] << "  and   " << ptrVector << endl;

    /*
    !           MODIFIERS
    
    assign(nb of value, value)
    push_back / pop_back
    insert(iterator, value) / erase()
    swap()
    
    
    */

    std::vector<string> v4 = {"Hello", "World", "!"};

   
    
    std::vector<string> v5 = {"Bonjour", "Monde", "Je", "suis", "Elon", "Musk"}; 

    cout << "Value of v4 before swap" << endl;
    // printing for v4
    for ( std::vector<string>::iterator it = v4.begin(); it != v4.end(); ++it )
        cout << *it << " ";

    cout << endl;
    
    cout << "Value of v5 before swap" << endl;
    // printing for v5
    for ( std::vector<string>::iterator it = v5.begin(); it != v5.end(); ++it )
        cout << *it << " ";
   
    cout << endl;
    v4.swap(v5);

    
    cout << endl;
    cout << "Value of v4 after swap" << endl;
    // printing for v4
    for ( std::vector<string>::iterator it = v4.begin(); it != v4.end(); ++it )
        cout << *it << " ";

    cout << endl;
    
    cout << "Value of v5 after swap" << endl;
    // printing for v5
    for ( std::vector<string>::iterator it = v5.begin(); it != v5.end(); ++it )
        cout << *it << " ";
    

}