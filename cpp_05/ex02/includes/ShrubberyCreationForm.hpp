/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:43 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 09:06:58 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

private:

	ShrubberyCreationForm( void ); // done
	
	string _target;

public:
	
	ShrubberyCreationForm( string targetInput ); // done
	ShrubberyCreationForm( const ShrubberyCreationForm& copy ); // done
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& right_operator );
	~ShrubberyCreationForm();

	const string&	getTarget( void )const;
	void			setTarget( string input );

	const string	drawAsciiTree( void )const;

	void 			execute( const Bureaucrat& executor )const;

	class FileAlreadyExists : public exception
	{
		public:
			virtual const char* what( void )const throw();
	};


};

ostream& operator<<( ostream& output_stream, const ShrubberyCreationForm& input );