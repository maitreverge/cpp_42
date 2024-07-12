/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:05:16 by flverge           #+#    #+#             */
/*   Updated: 2024/07/12 10:44:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "Form.hpp"

class Intern
{

private:

    // Some private members

protected:

    // Some protected members

public:

    Intern( void );
    Intern( const Intern& copy );
    Intern& operator=( const Intern& right_operator );
    ~Intern();

    Form*    makeForm( string formName, string formTarget );

};

ostream& operator<<( ostream& output_stream, const Intern& input );


// ---------- Functions declarations ---------------


Intern::Intern( void ){}


Intern::Intern( const Intern& copy ) :
    _foo(copy._foo), // List init each value individually
    _bar(copy._bar) {}


Intern& Intern::operator=( const Intern& right_operator ){

    if (this != &right_operator){
        // Reassign every value with the getter value 
        // this->_foo = right_operator.getFoo()
    }
    return *this;
}


Form*    Intern::makeForm( string formName, string formTarget ){

    Form f1(formName, 1, 1);

    return &f1;
}


Intern::~Intern( void ){}


ostream& operator<<( ostream& output_stream, const Intern& right_input ){

    // output_stream << right_input.PutAGetterFunctionhere();

    return output_stream;
}
