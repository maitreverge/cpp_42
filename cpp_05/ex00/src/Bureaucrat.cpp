/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:15:11 by flverge           #+#    #+#             */
/*   Updated: 2024/07/01 15:39:35 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ){}

Bureaucrat::Bureaucrat( string nameInput, int gradeInput ) :
	_name(nameInput), _grade(gradeInput){
	
	
	if (gradeInput < 1)
		throw GradeTooHighException();
	else if (gradeInput > 150)
		throw GradeTooLowException();
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

void			Bureaucrat::incrementGrade( int value ){

	if (this->_grade - value < 1)
		throw GradeTooHighException();
}
void			Bureaucrat::decrementGrade( int value ){

	if (this->_grade + value > 150)
		throw GradeTooLowException();
}

// Exceptions functions
const char* Bureaucrat::GradeTooHighException::_what( void ) const{ return "The Grade is too High"; }
const char* Bureaucrat::GradeTooLowException::_what( void ) const{ return "The Grade is too Low"; }


ostream& operator<<( ostream& output_stream, const Bureaucrat& right_input ){

	output_stream << right_input.getName();
	output_stream << ", bureaucrat grade ";
	output_stream << right_input.getGrade();
	output_stream << "\n";
	return output_stream;
}