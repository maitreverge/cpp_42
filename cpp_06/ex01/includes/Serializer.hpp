/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:18:30 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/22 21:13:52 by ubuntu           ###   ########.fr       */
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