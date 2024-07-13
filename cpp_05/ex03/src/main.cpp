/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:28:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/13 18:08:29 by flverge          ###   ########.fr       */
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
		Intern titouan_en_stage();
		
		AForm* intern_form = titouan_en_stage.// mdr ca compile pas
		
		// hercule.executeForm(f1);
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