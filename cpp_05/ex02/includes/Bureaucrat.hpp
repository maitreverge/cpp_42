/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:08:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 11:58:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class AForm;

class Bureaucrat
{

private:

	Bureaucrat( void );
	
	string	_name;
	
	// 1 ==  HIGH, 150 == LOW
	int		_grade;

public:

	Bureaucrat( string nameInput, int gradeInput );
	Bureaucrat( const Bureaucrat& copy );
	Bureaucrat& operator=( const Bureaucrat& right_operator );
	~Bureaucrat();

	// Getters
	const string&	getName( void )const;
	const int&		getGrade( void )const;

	void			incrementGrade( void );
	void			decrementGrade( void );
	void			signForm( int wasSigned, string nameForm, string reason = "" );

	void			executeForm(AForm const & form);

	// Nested Exception Classes
	class GradeTooHighException : public exception
	{
		public:
			virtual const char* what( void ) const throw();
	};

	class GradeTooLowException : public exception
	{
		public:
			virtual const char* what( void ) const throw();
	};

};

ostream& operator<<( ostream& output_stream, const Bureaucrat& input );