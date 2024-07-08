/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:55:03 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 11:41:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

private:

	PresidentialPardonForm( void ); // done
	
	string	_target;

public:
	
	PresidentialPardonForm( string targetInput ); // done
	PresidentialPardonForm( const PresidentialPardonForm& copy ); // done
	PresidentialPardonForm& operator=( const PresidentialPardonForm& right_operator );
	~PresidentialPardonForm();

	const string&	getTarget( void )const;
	void			setTarget( string input );

	void 			execute( const Bureaucrat& executor )const;

};

ostream& operator<<( ostream& output_stream, const PresidentialPardonForm& input );