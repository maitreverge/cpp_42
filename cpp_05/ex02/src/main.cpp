/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:28:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 11:02:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void	triggerTest(string &promptUser ,string testName){

	printColor(BOLD_CYAN, "----------------  " + testName + "  ----------------\n");
	
	do
	{
		print("Please hit the key [ ENTER ] for launching " + testName);
		getline(cin, promptUser);
	} while (!promptUser.empty());
}

static void testShrub( void ){

	Bureaucrat hercule("Hercule", 1);

	ShrubberyCreationForm f1("this_is_target_name");

	f1.beSigned(hercule);

	f1.execute(hercule);
}

static void testRobot( void ){

	Bureaucrat ulysse("Ulysse", 1);

	RobotomyRequestForm f1("this_is_target_name");

	f1.beSigned(ulysse);

	f1.execute(ulysse);
}


int main(void){

	string promptUser = "";
	clearScreen();

	triggerTest(promptUser, "TEST Shrubberry Form");

	testShrub();
	
	triggerTest(promptUser, "TEST Robotomy Form");

	testRobot();
	
	return 0;
}