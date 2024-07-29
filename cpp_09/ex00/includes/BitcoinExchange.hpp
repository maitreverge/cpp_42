/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:06 by flverge           #+#    #+#             */
/*   Updated: 2024/07/29 11:15:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

// #define DATA_FILE data.csv

class BitcoinExchange
{

private:

    // Some private members

protected:

    // Some protected members

public:

    BitcoinExchange( void );
    BitcoinExchange( const BitcoinExchange& copy );
    BitcoinExchange& operator=( const BitcoinExchange& right_operator );
    ~BitcoinExchange();

};

ostream& operator<<( ostream& output_stream, const BitcoinExchange& input );


// ---------- Functions declarations ---------------


BitcoinExchange::BitcoinExchange( void ){}


BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) :
    foo(copy._foo), // List init each value individually
    bar(copy._bar) {}
    // {*this = copy;} in case of non-member values


BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& right_operator ){

   if (this != &right_operator){
        // Reassign every value with the getter value 
        // this->_foo = right_operator.getFoo()
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange( void ){}


ostream& operator<<( ostream& output_stream, const BitcoinExchange& right_input ){

    // output_stream << right_input.PutAGetterFunctionhere();

    return output_stream;
}
