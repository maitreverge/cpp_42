/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:13:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 13:52:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) :
	_requiredGradeSign(50),
	_requiredGradeExecution(50){}

Form::Form( string nameInput, int gradeSign, int gradeExecute ) :
	_name(nameInput),
	_isFormSigned(false),
	_requiredGradeSign(gradeSign),
	_requiredGradeExecution(gradeExecute){

	if (_requiredGradeExecution < 1 or _requiredGradeSign < 1)
		throw Form::GradeTooHighException();
	if (_requiredGradeExecution > 150 or _requiredGradeSign > 150)
		throw Form::GradeTooLowException();
}


Form::Form( const Form& copy ) : 
	_name(copy._name),
	_isFormSigned(copy._isFormSigned),
	_requiredGradeExecution(copy._requiredGradeExecution),
	_requiredGradeSign(copy._requiredGradeSign) {}

/**
 * @brief This operator overload can only copy `_isFormSigned`
 * the only non `const` member.
 * 
 * @param right_operator 
 * @return Form& 
 */
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

	output_stream << "Form ";
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