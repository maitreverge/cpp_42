/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:05:16 by flverge           #+#    #+#             */
/*   Updated: 2024/07/13 16:31:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "AForm.hpp"

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

    AForm*    makeForm( string formTarget, string formName = 0 );

    typedef enum{
        PRESIDENTIAL,
        ROBOTOMY,
        SHRUBBERY,
        NONE
    }   e_formChoice;
    
    class FormNameError : public exception
	{
		public:
			virtual const char* what( void ) const throw();
	};

};


// ---------- Functions declarations ---------------


Intern::Intern( void ){

    print("An useless Intern has been Created");
}


Intern::Intern( const Intern& copy ) {*this = copy;}


Intern& Intern::operator=( const Intern& right_operator ){

    // no member values on this class
    return *this;
}


AForm*    Intern::makeForm( string formTarget, string formName ){

    if (formName.empty()) // ! as asked in the subject
        throw Intern::FormNameError();

    string typesOfForms[3] = {"presidential", "robotomy", "shrubbery"};

    int result = 3; // default value as in e_formChoice for NONE

    for (size_t i = 0; i < 3; i++)
    {
        if (formName == typesOfForms[i]){
            
            result = i;
            break;
        }
    }

    printNoEndl("Intern creates ");
    switch (result)
    {
        case PRESIDENTIAL:
            print("a PresidentialPardonForm");
            return new PresidentialPardonForm(formTarget);
            break;
        case ROBOTOMY:
            print("a RobotomyRequestForm");
            return new RobotomyRequestForm(formTarget);
            break;
        case SHRUBBERY:
            print("a RobotomyRequestForm");
            return new RobotomyRequestForm(formTarget);
            break;
        case NONE:
            print("nothing because he's incompetent (and also severely underpaid)");
            throw Intern::FormNameError();
            break;
        default:
            print("nothing because he's incompetent (and also severely underpaid)");
            throw Intern::FormNameError();
            break;
    }
    
}

const char* Intern::FormNameError::what( void ) const throw(){ return ("No formNane has been given"); }



Intern::~Intern( void ){

    print("An useless Intern has been fired, good fo him he was useless");
    
}