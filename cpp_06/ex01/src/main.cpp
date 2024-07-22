/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:40:33 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/22 21:12:39 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void){

    Data dataMember;

    dataMember.x = 42;
    dataMember.y = "This is a Welcome String";
    dataMember.z = 42.42f;
    
    cout << "Adress of dataMember = " << BOLD_GREEN << &dataMember << RESET << endl;
    
    cout << "dataMember.x = " << CYAN << dataMember.x << RESET << endl;
    cout << "dataMember.y = " << RED << dataMember.y << RESET << endl;
    cout << "dataMember.z = " << YELLOW << dataMember.z << RESET << endl;

    print("");

    uintptr_t ptr = Serializer::serialize(&dataMember);

    Data *newDataMember = Serializer::deserialize(ptr);

    print("");
    
    cout << "Adress of newDataMember = " BOLD_GREEN <<  &dataMember << RESET << endl;

    cout << "newDataMember->x = " << CYAN << newDataMember->x << RESET << endl;
    cout << "newDataMember->y = " << RED << newDataMember->y << RESET << endl;
    cout << "newDataMember->z = " << YELLOW << newDataMember->z << RESET << endl;

    
}