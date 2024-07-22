/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:40:33 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/22 21:15:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void){

    // Declaring a basic struc with 3 types of data
    Data dataMember;

    dataMember.x = 42;
    dataMember.y = "This is a Welcome String";
    dataMember.z = 42.42f;
    
    // Printing out this data
    cout << "Adress of dataMember = " << BOLD_GREEN << &dataMember << RESET << endl;
    
    cout << "dataMember.x = " << CYAN << dataMember.x << RESET << endl;
    cout << "dataMember.y = " << RED << dataMember.y << RESET << endl;
    cout << "dataMember.z = " << YELLOW << dataMember.z << RESET << endl;

    print("");

    // Serializing in a unintptr_t data structure
    uintptr_t ptr = Serializer::serialize(&dataMember);

    // Deserializing it within a pointer to another instance of Data struct.
    Data *newDataMember = Serializer::deserialize(ptr);

    print("");
    
    // Printing out this data
    cout << "Adress of newDataMember = " BOLD_GREEN <<  &dataMember << RESET << endl;

    cout << "newDataMember->x = " << CYAN << newDataMember->x << RESET << endl;
    cout << "newDataMember->y = " << RED << newDataMember->y << RESET << endl;
    cout << "newDataMember->z = " << YELLOW << newDataMember->z << RESET << endl;

}