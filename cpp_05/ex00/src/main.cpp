/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:34:06 by flverge           #+#    #+#             */
/*   Updated: 2024/07/01 18:19:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	
	// Test with a too low grade
	try
	{
		Bureaucrat alice("Alice", 200);
		printColor(GREEN, alice.getName()); // In consequence, this line won't be executed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Test with a too high test
	try
	{
		Bureaucrat bob("Bob", 0);
		printColor(GREEN, bob.getName()); // This line won't be executed neither
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		// Once we got correct parametters,
		Bureaucrat charli("Charli avec un i", 75);
		// The rest of the program can be executed
		printColor(GREEN, charli.getName());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// Test with a regular Bureaucrat in which we increment too far
	try
	{
		Bureaucrat hercule("Hercule", 5);

		// We will increment Hercule grade 5 times
		// So the grade will drop under 1, raising an error
		for (size_t i = 0; i < 5; i++)
		{
			cout << hercule.getName() << " grade is before increment = ";
			printColor(GREEN, customItoA(hercule.getGrade()));
			hercule.incrementGrade();
		}

		print("This line of code won't be executed");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Test with a regular Bureaucrat in which we increment too far
	try
	{
		Bureaucrat ulysse("Ulysse", 146);

		cout << endl;
		cout << ulysse << endl;

		// We will increment Ulysse grade 5 times
		// So the grade will drop under 1, raising an error
		for (size_t i = 0; i < 5; i++)
		{
			cout << ulysse.getName() << " grade is before increment = ";
			printColor(GREEN, customItoA(ulysse.getGrade()));
			ulysse.decrementGrade();
		}

		print("This line of code won't be executed");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}