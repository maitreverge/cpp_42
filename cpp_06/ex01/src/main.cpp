/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:40:33 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/22 20:55:02 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void){

    Data dataMember;

    dataMember.x = 42;
    dataMember.y = "This is a Welcome String";
    dataMember.z = 42.42f;
    
    cout << "Adress of dataMember = " << &dataMember << endl;
    
    cout << "dataMember.x = " << dataMember.x << endl;
    cout << "dataMember.y = " << dataMember.y << endl;
    cout << "dataMember.z = " << dataMember.z << endl;

    print("");

    uintptr_t ptr = Serializer::serialize(&dataMember);

    Data *newDataMember = Serializer::deserialize(ptr);

    print("");
    
    cout << "Adress of newDataMember = " << &dataMember << endl;

    cout << "newDataMember->x = " << newDataMember->x << endl;
    cout << "newDataMember->y = " << newDataMember->y << endl;
    cout << "newDataMember->z = " << newDataMember->z << endl;

    
}