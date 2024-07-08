/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:28:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/08 10:36:54 by flverge          ###   ########.fr       */
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

static void test1( void ){

	Bureaucrat hercule("Hercule", 1);

	RobotomyRequestForm f1("this_is_target_name");

	f1.beSigned(hercule);

	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
	f1.execute(hercule);
}

int main(void){

	srand(time(NULL));

	string promptUser = "";
	clearScreen();

	triggerTest(promptUser, "TEST failed Bureaucrat and Form");

	test1();
	
	triggerTest(promptUser, "TEST valid Bureaucrat and Form");

	// test2();
	
	return 0;
}