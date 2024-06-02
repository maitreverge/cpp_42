/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:08 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 17:15:03 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

/**
 * @brief Wrapper function to print a message and exit the program.
 * 
 */
static void wrongInput( void ){
	printColor(RED, "⛔ Wrong Arguments ⛔");
	print("Usage : ");
	printColorNoEndl(GREEN, "./sed_is_for_losers   ");
	printColorNoEndl(YELLOW, "\"Target string\"   ");
	printColor(BLUE, "\"String to remplace\"");
	print("Example :");
	printColor(YELLOW, "./sed_is_for_losers      koala      kangaroo");
	exit(EXIT_FAILURE);
}

static void replaceCurrentLine(const string& target, const string& replace, string& currentLine)
{
	size_t pos;
	
	const size_t lenTarget = target.size();
	// const size_t lenReplace = replace.length();
	// checks if there is target in the string
	
	// string::npos == -1, so when find does not find target in currentLine
	while ((pos = currentLine.find(target)) != string::npos)
	{
		currentLine.erase(pos, lenTarget);
		currentLine.insert(pos, replace);
	}
}

int main(int ac, char**av){
	if (ac != 3)
		wrongInput();
	
	Utils myStrings(av[1], av[2]);
	
	// Chekcs if both strings are equal or not, exit if so.
	myStrings.areStringEqual();
	
	// Oppening file with checking both read and write permissions
	fstream myFile("test_files/koala.txt", fstream::in | fstream::out);

	// myFile.open(fileName, std::ios_base::in & std::ios_base::out);

	if (myFile.is_open())
	{
		string currentLine;
		string temp;
		
		while (getline(myFile, currentLine))
		{
			temp = currentLine;
			if (!currentLine.empty())
				replaceCurrentLine(myStrings.getTarget(), myStrings.getReplace(), currentLine);
			if (temp != currentLine)
			{
				myFile << currentLine;
			}
		}
	}
	else
		printColor(RED, "⛔ Failed to open file in both read and write mode ⛔");
	
	myFile.close();
	
	return (0);
}