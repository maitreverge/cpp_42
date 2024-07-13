/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:05:16 by flverge           #+#    #+#             */
/*   Updated: 2024/07/13 16:34:44 by flverge          ###   ########.fr       */
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