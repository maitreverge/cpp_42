/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:29:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 18:54:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class AForm
{

private:
	
	
	// 1 ==  HIGH, 150 == LOW
	const string	_name;
	bool			_isFormSigned;
	const int		_requiredGradeSign;
	const int		_requiredGradeExecution;

protected :

	AForm( void );

public:

	AForm( string nameInput, int gradeSign, int gradeExecute );
	AForm( const AForm& copy );
	AForm& operator=( const AForm& right_operator );
	virtual ~AForm();
	
	// Setter
	virtual void			setIsFormSigned( bool value );
	
	// Getters
	virtual const string&	getName( void )const;
	virtual const bool&		getIsFormSigned( void )const;
	virtual const int&		getRequiredGradeSign( void )const;
	virtual const int&		getRequiredGradeExecution( void )const;

	virtual void			beSigned( Bureaucrat &person );

	virtual void 			execute( const Bureaucrat& executor )const = 0;
	
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

	class AFormIsNotSigned : public exception
	{
		public:
			virtual const char* what( void ) const throw();
	};

};

ostream& operator<<( ostream& output_stream, const AForm& input );