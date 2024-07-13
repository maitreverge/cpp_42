/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:32:09 by flverge           #+#    #+#             */
/*   Updated: 2024/07/13 16:37:01 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

    size_t result = 3; // default value as in e_formChoice for NONE

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
            print("a ShrubberyCreationForm");
            return new ShrubberyCreationForm(formTarget);
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