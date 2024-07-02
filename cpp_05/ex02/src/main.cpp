/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:28:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 14:56:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	triggerTest(string &promptUser ,string testName){

	printColor(BOLD_CYAN, "----------------  " + testName + "  ----------------\n");
	
	do
	{
		print("Please hit the key [ ENTER ] for launching " + testName);
		getline(cin, promptUser);
	} while (!promptUser.empty());
}

int main(void){

	string promptUser = "";
	clearScreen();

	triggerTest(promptUser, "TEST failed Bureaucrat and Form");

	// test1();
	
	triggerTest(promptUser, "TEST valid Bureaucrat and Form");

	// test2();
	
	return 0;
}