/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:13:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 18:54:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) :
	_requiredGradeSign(50),
	_requiredGradeExecution(50){}

AForm::AForm( string nameInput, int gradeSign, int gradeExecute ) :
	_name(nameInput),
	_isFormSigned(false),
	_requiredGradeSign(gradeSign),
	_requiredGradeExecution(gradeExecute){

	if (_requiredGradeExecution < 1 or _requiredGradeSign < 1)
		throw AForm::GradeTooHighException();
	if (_requiredGradeExecution > 150 or _requiredGradeSign > 150)
		throw AForm::GradeTooLowException();
}


AForm::AForm( const AForm& copy ) : 
	_name(copy._name),
	_isFormSigned(copy._isFormSigned),
	_requiredGradeExecution(copy._requiredGradeExecution),
	_requiredGradeSign(copy._requiredGradeSign) {}

/**
 * @brief This operator overload can only copy `_isAFormSigned`
 * the only non `const` member.
 * 
 * @param right_operator 
 * @return AForm& 
 */
AForm& AForm::operator=( const AForm& right_operator ){

	if (this != &right_operator){
		this->_isFormSigned = right_operator.getIsFormSigned();
	}
	return *this;
}


AForm::~AForm( void ){}


void	AForm::beSigned( Bureaucrat &person ){
	
	if (this->_isFormSigned){

		person.signForm(0, this->_name ,"Aform is already signed.");
		throw AFormAlreadySigned();
	}
	else{
		
		if (this->getRequiredGradeSign() < person.getGrade()) {
			
			person.signForm(0, this->_name ,"bureaucrat grade is too low");
			throw AForm::GradeTooLowException();
		}
		else{
			
			person.signForm(1, this->_name);
			this->_isFormSigned = true;
		}
	}
}

// Setter
void			AForm::setIsFormSigned( bool value ){ this->_isFormSigned = value; }


// Getters
const string&	AForm::getName( void )const{ return this->_name; }
const bool&		AForm::getIsFormSigned( void )const{ return this->_isFormSigned; }
const int&		AForm::getRequiredGradeSign( void )const{ return this->_requiredGradeSign; }
const int&		AForm::getRequiredGradeExecution( void )const{ return this->_requiredGradeExecution; }


// Nested Exception Classes
const char* AForm::GradeTooHighException::what( void ) const throw(){ return "The AForm Grade is too High"; }
const char* AForm::GradeTooLowException::what( void ) const throw(){ return "The AForm Grade is too Low"; }
const char* AForm::AFormAlreadySigned::what( void ) const throw(){ return "The AForm Is Already Signed"; }
const char* AForm::AFormIsNotSigned::what( void ) const throw(){ return "The AForm Is Not Signed"; }



ostream& operator<<( ostream& output_stream, const AForm& right_input ){

	output_stream << "AForm ";
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