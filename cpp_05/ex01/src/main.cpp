/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:28:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 14:43:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	triggerTest(string &promptUser ,string testName){

	printColor(BOLD_CYAN, "----------------  " + testName + "  ----------------\n");
	
	do
	{
		print("Please hit the key [ ENTER ] for launching " + testName);
		getline(cin, promptUser);
	} while (!promptUser.empty());
}

void	test1(void){

	try
	{
		Bureaucrat ulysse("Ulysse", 180);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");

	try
	{
		Bureaucrat ulysse("Ulysse", -10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");

	try
	{
		Form f1("Slavery Contract", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");

	try
	{
		Form f1("Slavery Contract", 1, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");

	try
	{
		Form f1("Slavery Contract", 200, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");

	try
	{
		Form f1("Slavery Contract", 1, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print("");
}

void	test2(void){

	// Declaring both a valid Bureaucrat and Form
	Bureaucrat ulysse("Ulysse", 5);
	Form f1("Slavery Contract", 1, 1);

	print("Initial state of Ulysse");
	cout << ulysse << endl;
	
	print("Initial state of Form f1");
	cout << f1 << endl;

	printColor(BOLD_GREEN, "====================== START OF THE LOOP ======================\n\n");	
	
	// In this test, we will try to increment Bureaucrat grade until he can sign the form
	// We will also increment it further 1, and still try to sign it after the form being signed.
	for (size_t i = 0; i < 7; i++)
	{
		print("Ulysse state before increment\n");
		cout << ulysse << endl;
		
		try
		{
			ulysse.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		print("Ulysse state after an increment try");
		cout << ulysse << endl;

		try
		{
			f1.beSigned(ulysse);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		print("\n--------------------------------\n");
		
	}
	
}

int main(void){

	string promptUser = "";
	clearScreen();

	triggerTest(promptUser, "TEST failed Bureaucrat and Form");

	test1();
	
	triggerTest(promptUser, "TEST valid Bureaucrat and Form");

	test2();
	
	return 0;
}