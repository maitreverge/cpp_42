/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:28:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/14 16:31:06 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	triggerTest( string &promptUser ,string testName ){

	printColor(BOLD_CYAN, "----------------  " + testName + "  ----------------\n");
	
	do
	{
		print("Please hit the key [ ENTER ] for launching " + testName);
		getline(cin, promptUser);
	} while (!promptUser.empty());
}

static void testIntern( void ){

	try
	{
		Bureaucrat hercule("Hercule", 1);
		Intern titouan_en_stage;
		
		string formTarget = "Jean-Didier";
		string formName = "robotomy"; // can be set to "" 
		
		AForm* intern_form = titouan_en_stage.makeForm(formTarget,formName);

		intern_form->beSigned(hercule);

		hercule.executeForm(*intern_form);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

int main( void ){

	srand(time(NULL)); // seed time in rand() to achieve true randomness


	string promptUser = "";
	clearScreen();

	triggerTest(promptUser, "TEST Testing Intern ");

	testIntern();
	
	return 0;
}