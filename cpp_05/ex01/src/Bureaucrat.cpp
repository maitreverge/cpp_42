/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:15:11 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 12:14:24 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ){}

Bureaucrat::Bureaucrat( string nameInput, int gradeInput ) :
	_name(nameInput){
	
	if (gradeInput < 1)
		throw GradeTooHighException();
	else if (gradeInput > 150)
		throw GradeTooLowException();
	else
		this->_grade = gradeInput;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ){ *this = copy; }


Bureaucrat& Bureaucrat::operator=( const Bureaucrat& right_operator ){

	if (this != &right_operator){
		this->_grade = right_operator.getGrade();
		this->_name = right_operator.getName();
	}
	return *this;
}


Bureaucrat::~Bureaucrat( void ){}

// Getters
const string&	Bureaucrat::getName( void )const{ return this->_name; }
const int&		Bureaucrat::getGrade( void )const{ return this->_grade; }


void			Bureaucrat::incrementGrade( void ){

	(this->_grade <= 1) ? throw GradeTooHighException() : this->_grade--;
}

void			Bureaucrat::decrementGrade( void ){

	(this->_grade >= 150) ? throw GradeTooLowException() : this->_grade++;
}

void	Bureaucrat::signForm( int wasSigned, string nameForm, string reason ){

	if (wasSigned)
		printColor(BOLD_GREEN, this->getName() + " bureaucrat signed " + nameForm);
	else
		printColor(BOLD_RED, this->getName() + " couldn't sign form " + nameForm + " because " + reason);
}

// Exceptions functions
const char* Bureaucrat::GradeTooHighException::what( void ) const throw(){ return ("The Bureaucrat Grade is too High"); }
const char* Bureaucrat::GradeTooLowException::what( void ) const throw(){ return ("The Bureacrat Grade is too Low"); }


ostream& operator<<( ostream& output_stream, const Bureaucrat& right_input ){

	output_stream << right_input.getName();
	output_stream << ", bureaucrat grade ";
	output_stream << right_input.getGrade();
	output_stream << "\n";
	return output_stream;
}