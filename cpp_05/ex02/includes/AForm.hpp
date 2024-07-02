/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:29:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 14:54:40 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class AForm
{

private:
	
	AForm( void );
	
	// 1 ==  HIGH, 150 == LOW
	const string	_name;
	bool			_isAFormSigned;
	const int		_requiredGradeSign;
	const int		_requiredGradeExecution;

public:

	AForm( string nameInput, int gradeSign, int gradeExecute );
	AForm( const AForm& copy );
	AForm& operator=( const AForm& right_operator );
	virtual ~AForm();
	
	// Getters
	virtual const string&	getName( void )const = 0;
	virtual const bool&		getIsAFormSigned( void )const;
	virtual const int&		getRequiredGradeSign( void )const;
	virtual const int&		getRequiredGradeExecution( void )const;

	virtual void			beSigned( Bureaucrat &person );
	
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
	
	class AFormAlreadySigned : public exception
	{
		public:
			virtual const char* what( void ) const throw();
	};

};

ostream& operator<<( ostream& output_stream, const AForm& input );