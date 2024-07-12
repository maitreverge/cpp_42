/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:28:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 12:21:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	triggerTest(string &promptUser ,string testName){

	printColor(BOLD_CYAN, "----------------  " + testName + "  ----------------\n");
	
	do
	{
		print("Please hit the key [ ENTER ] for launching " + testName);
		getline(cin, promptUser);
	} while (!promptUser.empty());
}

static void testShrub( void ){

	try
	{
		Bureaucrat hercule("Hercule", 1);
		ShrubberyCreationForm f1("this_is_target_name");
		f1.beSigned(hercule);
		f1.execute(hercule);
		hercule.executeForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

static void testRobot( void ){

	try
	{
		Bureaucrat ulysse("Ulysse", 1);

		RobotomyRequestForm f1("Robot Form hehe");

		f1.beSigned(ulysse);

		// Multiples executions for drilling
		f1.execute(ulysse);
		f1.execute(ulysse);
		f1.execute(ulysse);
		f1.execute(ulysse);

		// Multiples executions for drilling
		ulysse.executeForm(f1);
		ulysse.executeForm(f1);
		ulysse.executeForm(f1);
		ulysse.executeForm(f1);
		ulysse.executeForm(f1);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


static void testPresident( void ){

	try
	{
		Bureaucrat arthemis("Arthemis", 1);

		PresidentialPardonForm f1("Presidential Form jaja");

		f1.beSigned(arthemis);

		f1.execute(arthemis);
		f1.execute(arthemis);

		arthemis.executeForm(f1);
		arthemis.executeForm(f1);
		arthemis.executeForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


int main(void){

	srand(time(NULL)); // seed time in rand() to achieve true randomness


	string promptUser = "";
	clearScreen();

	triggerTest(promptUser, "TEST Shrubberry Form");

	testShrub();
	
	triggerTest(promptUser, "TEST Robotomy Form");

	testRobot();
	
	triggerTest(promptUser, "TEST Presidential Form");

	testPresident();
	
	return 0;
}