/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:04:52 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 10:14:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

private:

	RobotomyRequestForm( void ); // done
	
	string	_target;
	bool	_isTargetRobotomized;

public:
	
	RobotomyRequestForm( string targetInput ); // done
	RobotomyRequestForm( const RobotomyRequestForm& copy ); // done
	RobotomyRequestForm& operator=( const RobotomyRequestForm& right_operator );
	~RobotomyRequestForm();

	const string&	getTarget( void )const;
	void			setTarget( string input );
	const bool&			getIsTargetRobotomized( void )const;

	// const string	drawAsciiTree( void )const;

	void 			execute( const Bureaucrat& executor )const;

	class FileAlreadyExists : public exception
	{
		public:
			virtual const char* what( void )const throw();
	};


};

ostream& operator<<( ostream& output_stream, const RobotomyRequestForm& input );

// -------------------------------------------

// AForm base constructor is in protected base class, but infine won't be used because private in the derived class
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm(), _isTargetRobotomized(false){}


RobotomyRequestForm::RobotomyRequestForm( string targetInput ) :
	AForm("Fabulous Robotomy Form", 72, 45), // ! ASKED IN THE SUBJECT
	_target(targetInput),
	_isTargetRobotomized(false){}


RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) :
	AForm( this->getName(), this->getRequiredGradeSign(), this->getRequiredGradeExecution()),
	_target(copy._target),
	_isTargetRobotomized(false){}


/**
 * @brief Only the `_isFormSigned` and `_isTargetRobotomized` could be reassigned
 * as it is the only non const value.
 * 
 * @param right_operator 
 * @return RobotomyRequestForm& 
 */
RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& right_operator ){

	if (this != &right_operator){
		// Reassign every value with the getter value
		this->setIsFormSigned(right_operator.getIsFormSigned());
		this->_isTargetRobotomized = right_operator.getIsTargetRobotomized();
	}
	return *this;
}


RobotomyRequestForm::~RobotomyRequestForm( void ){}


// Getters and setters 
const string&	RobotomyRequestForm::getTarget( void )const{ return this->_target; }
void			RobotomyRequestForm::setTarget( string input ){ this->_target = input; }
const bool&		RobotomyRequestForm::getIsTargetRobotomized( void )const{ return this->_isTargetRobotomized; }


void 			RobotomyRequestForm::execute( const Bureaucrat& executor )const{

	// ! TO DO
}


const char* RobotomyRequestForm::FileAlreadyExists::what( void )const throw(){ return "File with extension \"_shrubbery\" already exists."; }


ostream& operator<<( ostream& output_stream, const RobotomyRequestForm& right_input ){

	output_stream << "RobotomyRequestForm ";
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