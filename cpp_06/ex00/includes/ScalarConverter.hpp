/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:52:34 by flverge           #+#    #+#             */
/*   Updated: 2024/07/22 09:32:59 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class ScalarConverter
{

private:

    ScalarConverter( void );
    ScalarConverter( const ScalarConverter& copy );
    ScalarConverter& operator=( const ScalarConverter& right_operator );
    ~ScalarConverter();

public:

    // Les fonctions statiques sont utilisables sans instances d'objet.
    static void convert( string &input );

};