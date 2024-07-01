/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:08:18 by flverge           #+#    #+#             */
/*   Updated: 2024/07/01 15:42:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class Bureaucrat
{

private:

	Bureaucrat( void );
	
	string	_name;
	int		_grade; // From 1 to 150 ( 1 = hight, 150 = low)

protected:

	// Some protected members

public:

	Bureaucrat( string nameInput, int gradeInput );
	Bureaucrat( const Bureaucrat& copy );
	Bureaucrat& operator=( const Bureaucrat& right_operator );
	~Bureaucrat();

	const string&	getName( void )const;
	const int&		getGrade( void )const;

	void			incrementGrade( int value );
	void			decrementGrade( int value );

	// Nested Exception Classes
	class GradeTooHighException : public exception
	{
		public:
			virtual const char* _what( void ) const;
	};

	class GradeTooLowException : public exception
	{
		public:
			virtual const char* _what( void ) const;
	};

};

ostream& operator<<( ostream& output_stream, const Bureaucrat& input );