/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:09:41 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/22 21:09:51 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ){}


Serializer::Serializer( const Serializer& copy ) {*this = copy;}


Serializer& Serializer::operator=( const Serializer& right_operator ){
    (void)(right_operator);   
    return *this;
}


Serializer::~Serializer( void ){}

uintptr_t Serializer::serialize( Data* ptr ){

    return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data* Serializer::deserialize( uintptr_t raw ){

    return ( reinterpret_cast<Data*>(raw) );
}