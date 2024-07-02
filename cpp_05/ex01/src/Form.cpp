/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:13:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 12:10:30 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Can't use this constructor, left empty
Form::Form( void ) : {}

Form::Form( string nameInput, int gradeSign, int gradeExecute ) :
	_name(nameInput), _isFormSigned(false), _requiredGradeSign(gradeSign), _requiredGradeExecution(gradeExecute){}


Form::Form( const Form& copy ) { *this = copy; }


Form& Form::operator=( const Form& right_operator ){

	if (this != &right_operator){
		this->_isFormSigned = right_operator.getIsFormSigned();
	}
	return *this;
}


Form::~Form( void ){}

void	Form::beSigned( Bureaucrat &person ){
	
	if (this->_isFormSigned){

		person.signForm(0, this->_name ,"form is already signed.");
		throw FormAlreadySigned();
	}
	else{
		
		if (this->getRequiredGradeSign() < person.getGrade()) {
			
			person.signForm(0, this->_name ,"bureaucrat grade is too low");
			throw Form::GradeTooLowException();
		}
		else{
			
			person.signForm(1, this->_name);
			this->_isFormSigned = true;
		}
	}
}


// Getters
const string&	Form::getName( void )const{ return this->_name; }
const bool&		Form::getIsFormSigned( void )const{ return this->_isFormSigned; }
const int&		Form::getRequiredGradeSign( void )const{ return this->_requiredGradeSign; }
const int&		Form::getRequiredGradeExecution( void )const{ return this->_requiredGradeExecution; }


// Nested Exception Classes
const char* Form::GradeTooHighException::what( void ) const throw(){ return "The Form Grade is too High"; }
const char* Form::GradeTooLowException::what( void ) const throw(){ return "The Form Grade is too Low"; }
const char* Form::FormAlreadySigned::what( void ) const throw(){ return "The Form Is Already Signed"; }



ostream& operator<<( ostream& output_stream, const Form& right_input ){

	output_stream << "Form";
	output_stream << right_input.getName();
	output_stream << right_input.getIsFormSigned() ? BOLD_GREEN " is signed, " : BOLD_RED " is not signed, ";
	output_stream << RESET "have a required Grade of ";
	output_stream << right_input.getRequiredGradeSign();
	output_stream << " for signing and a required Grade of ";
	output_stream << right_input.getRequiredGradeExecution();
	output_stream << " for being executed.";
	output_stream << endl;
	return output_stream;
}