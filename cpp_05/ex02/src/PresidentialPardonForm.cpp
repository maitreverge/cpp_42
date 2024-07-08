/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:41:28 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 11:41:45 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// AForm base constructor is in protected base class, but infine won't be used because private in the derived class
PresidentialPardonForm::PresidentialPardonForm( void ) : AForm(){}


PresidentialPardonForm::PresidentialPardonForm( string targetInput ) :
	AForm("Fabulous Robotomy Form", 25, 5), // ! ASKED IN THE SUBJECT
	_target(targetInput){}


PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) :
	AForm( this->getName(), this->getRequiredGradeSign(), this->getRequiredGradeExecution()),
	_target(copy._target){}


/**
 * @brief Only the `_isFormSigned` and `_isTargetRobotomized` could be reassigned
 * as it is the only non const value.
 * 
 * @param right_operator 
 * @return PresidentialPardonForm& 
 */
PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& right_operator ){

	if (this != &right_operator){
		// Reassign every value with the getter value
		this->setIsFormSigned(right_operator.getIsFormSigned());
	}
	return *this;
}


PresidentialPardonForm::~PresidentialPardonForm( void ){}


// Getters and setters 
const string&	PresidentialPardonForm::getTarget( void )const{ return this->_target; }
void			PresidentialPardonForm::setTarget( string input ){ this->_target = input; }

void 			PresidentialPardonForm::execute( const Bureaucrat& executor )const{

	// prerequesites checks
	if (!this->getIsFormSigned())
		throw AForm::AFormIsNotSigned();
	else if ( executor.getGrade() > this->getRequiredGradeExecution())
		throw Bureaucrat::GradeTooLowException();
	else {

		printColor(BOLD_BLUE, this->_target + "'has been pardoned by Zaphod Beeblebrox 👽");
	}
}


ostream& operator<<( ostream& output_stream, const PresidentialPardonForm& right_input ){

	output_stream << "PresidentialPardonForm ";
	output_stream << CYAN << right_input.getName() << RESET;
	output_stream << (right_input.getIsFormSigned() ? BOLD_GREEN : BOLD_RED );
	output_stream << (right_input.getIsFormSigned() ? " is signed, " :  " is not signed, ");
	output_stream << RESET << endl;
	output_stream << "have a required Grade of ";
	output_stream << right_input.getRequiredGradeSign();
	output_stream << " for signing and a required Grade of ";
	output_stream << right_input.getRequiredGradeExecution();
	output_stream << " for being executed.";
	output_stream << endl;

	return output_stream;
}