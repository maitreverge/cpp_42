/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:34:06 by flverge           #+#    #+#             */
/*   Updated: 2024/07/01 15:42:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){

	try
	{
		Bureaucrat b1("Bob", 200);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e._what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e._what() << '\n';
	}

	b1.getGrade();
	
}