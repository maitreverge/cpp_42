/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:08 by flverge           #+#    #+#             */
/*   Updated: 2024/06/03 14:12:36 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

/**
 * @brief Wrapper function to print a message and exit the program.
 * 
 */
static void wrongInput( void ){
	printColor(RED, "⛔ Wrong Arguments ⛔");
	print("Usage : ");
	printColorNoEndl(GREEN, "./sed_is_for_losers   ");
	printColorNoEndl(MAGENTA, "\"test_files/koala.txt\"   ");
	printColorNoEndl(YELLOW, "\"Target string\"   ");
	printColor(BLUE, "\"String to remplace\"");
	print("Example :");
	printColor(YELLOW, "./sed_is_for_losers   test_files/koala.txt   koala      kangaroo");
	exit(EXIT_FAILURE);
}

/**
 * @brief Takes the string read from the file descriptor
 * Search for any occurence of the target string.
 * If so : erase it, then write the replace string, all at the same position.
 * 
 * @param target 
 * @param replace 
 * @param currentLine 
 */
static void replaceCurrentLine(const string& target, const string& replace, string& currentLine)
{
	size_t pos;
	
	const size_t lenTarget = target.size();
	
	// string::npos == -1
	// so when `find()` does not find target in currentLine
	while ((pos = currentLine.find(target)) != string::npos)
	{
		currentLine.erase(pos, lenTarget);
		currentLine.insert(pos, replace);
	}
}

static void safeClosingFile(ofstream& myTargetFile, ifstream& myOriginFile){
	if (myOriginFile.is_open())
		myOriginFile.close();
	if (myTargetFile.is_open())
		myTargetFile.close();
}

int main(int ac, char**av){
	if (ac != 4)
		wrongInput();
	
	Utils myStrings(av[1], av[2], av[3]);
	
	// Chekcs if both strings av[2] and av[3] are equal or not, exit if so.
	myStrings.areStringEqual();
	
	// Opening origin file with checking both read and write permissions
	ifstream myOriginFile(myStrings.getOriginFile().c_str());

	// Opening AND creating target file with write permissions
	ofstream myTargetFile(myStrings.getTargetFile().c_str());
	
	if (myOriginFile.is_open())
	{
		string currentLine;
		
		while (getline(myOriginFile, currentLine))
		{
			replaceCurrentLine(myStrings.getTargetString(), myStrings.getReplaceString(), currentLine);
			// Write the replaced line straight in the output file
			myTargetFile << currentLine;

			// If the fd is not in EOF state, print a new line, except for the last line
			if (!myOriginFile.eof())
				myTargetFile << std::endl;
		}
	}
	else
		printColor(RED, "⛔ Failed ORIGIN to open file in both read and write mode ⛔");
	
	safeClosingFile(myTargetFile, myOriginFile);
	
	return (0);
}