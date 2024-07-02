/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:43 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 15:25:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.cpp"

class ShrubberyCreationForm : public AForm
{

private:

	ShrubberyCreationForm( void ); // done

public:
	
	ShrubberyCreationForm( string nameInput ); // done
	ShrubberyCreationForm( const ShrubberyCreationForm& copy ); // done
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& right_operator );
	~ShrubberyCreationForm();

};

ostream& operator<<( ostream& output_stream, const ShrubberyCreationForm& input );


// ---------- Functions declarations ---------------

// AForm base constructor in in protected base class, but infine won't be used because private in the derived class
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm(){}


ShrubberyCreationForm::ShrubberyCreationForm( string nameInput ) : AForm(nameInput, 145, 137){}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) :
	AForm( this->getName(), this->getRequiredGradeSign(), this->getRequiredGradeExecution()) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& right_operator ){

	if (this != &right_operator){
		// Reassign every value with the getter value
		
		// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TO DO
		this->_isFormSigned = right_operator.getIsFormSigned();

	}
	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm( void ){}


ostream& operator<<( ostream& output_stream, const ShrubberyCreationForm& right_input ){

	// output_stream << right_input.PutAGetterFunctionhere();

	return output_stream;
}
