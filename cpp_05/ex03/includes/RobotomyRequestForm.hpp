/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:04:52 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 11:05:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

private:

	RobotomyRequestForm( void ); // done
	
	string	_target;

public:
	
	RobotomyRequestForm( string targetInput ); // done
	RobotomyRequestForm( const RobotomyRequestForm& copy ); // done
	RobotomyRequestForm& operator=( const RobotomyRequestForm& right_operator );
	~RobotomyRequestForm();

	const string&	getTarget( void )const;
	void			setTarget( string input );

	// const string	drawAsciiTree( void )const;

	void 			execute( const Bureaucrat& executor )const;

};

ostream& operator<<( ostream& output_stream, const RobotomyRequestForm& input );