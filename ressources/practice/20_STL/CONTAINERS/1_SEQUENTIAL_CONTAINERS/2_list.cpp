/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_list.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:58:44 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/26 17:31:47 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

using std::cout;
using std::endl;
/*

!                   LIST
Lists are sequence containers that allow non-contiguous memory allocation.
As compared to the vector, the list has slow traversal,
but once a position has been found, insertion and deletion are quick (constant time).
 Normally, when we say a List, we talk about a doubly linked list. 


*/

int main(void){

    std::list<int> list1 = {1, 2, 3, 4, 5};

    for( std::list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
        cout << *it << " ";
    
    list1.push_back(42);
    list1.push_front(0);

    cout << endl;

    for( std::list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
        cout << *it << " ";
    
}