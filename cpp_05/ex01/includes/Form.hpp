/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:29:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 13:11:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Form
{

private:
	
	Form( void );
	
	// 1 ==  HIGH, 150 == LOW
	const string	_name;
	bool			_isFormSigned;
	const int		_requiredGradeSign;
	const int		_requiredGradeExecution;

public:

	Form( string nameInput, int gradeSign, int gradeExecute );
	Form( const Form& copy );
	Form& operator=( const Form& right_operator );
	~Form();
	
	// Getters
	const string&	getName( void )const;
	const bool&		getIsFormSigned( void )const;
	const int&		getRequiredGradeSign( void )const;
	const int&		getRequiredGradeExecution( void )const;

	void			beSigned( Bureaucrat &person );
	
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
	
	class FormAlreadySigned : public exception
	{
		public:
			virtual const char* what( void ) const throw();
	};

};

ostream& operator<<( ostream& output_stream, const Form& input );

// Declaration function

