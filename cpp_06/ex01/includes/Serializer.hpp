/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:18:30 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/22 20:52:50 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "Data.hpp"

class Serializer
{

private:

    Serializer( void );
    Serializer( const Serializer& copy );
    Serializer& operator=( const Serializer& right_operator );
    ~Serializer();

public:
    // https://blog.feabhas.com/2024/02/navigating-memory-in-c-a-guide-to-using-stduintptr_t-for-address-handling/
    static uintptr_t serialize( Data* ptr );
    static Data* deserialize( uintptr_t raw) ;


};

// ---------- Functions declarations ---------------


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