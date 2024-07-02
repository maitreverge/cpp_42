/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:28:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 14:12:04 by flverge          ###   ########.fr       */
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

int main(void){

	string promptUser = "";
	clearScreen();


	triggerTest(promptUser, "TEST failed Bureaucrat and Form");

	test1();
	


	// Declaring both a valid Bureaucrat and Form
	// Bureaucrat ulysse("Ulysse", 5);

	// cout << ulysse << endl;

	// Form f1("Slavery Contract", 1, 1);
	
	// cout << f1 << endl;

	
	// for (size_t i = 0; i < 7; i++)
	// {
	// 	print("Ulysse state before increment");
	// 	cout << ulysse << endl << endl;
	// 	try
	// 	{
	// 		ulysse.incrementGrade();
	// 		// f1.beSigned(ulysse);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
		
	// 	print("Ulysse state after increment");

	// 	try
	// 	{
	// 		// ulysse.incrementGrade();
	// 		f1.beSigned(ulysse);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
		
	// }
	

	


	return 0;
}