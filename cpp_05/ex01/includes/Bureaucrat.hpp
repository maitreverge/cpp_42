/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:08:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 13:29:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
// #include "Form.hpp"

class Bureaucrat
{

private:

	string	_name;
	int		_grade; // From 1 to 150 ( 1 = hight, 150 = low)

public:

	Bureaucrat( void );
	Bureaucrat( string nameInput, int gradeInput );
	Bureaucrat( const Bureaucrat& copy );
	Bureaucrat& operator=( const Bureaucrat& right_operator );
	~Bureaucrat();

	const string&	getName( void )const;
	const int&		getGrade( void )const;

	void			incrementGrade( void );
	void			decrementGrade( void );

	void			signForm( int wasSigned, string nameForm, string reason = "" );

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

// to add to Bureaucrap.pp
