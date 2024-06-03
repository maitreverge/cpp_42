/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:08 by flverge           #+#    #+#             */
/*   Updated: 2024/06/03 11:14:15 by flverge          ###   ########.fr       */
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
	printColorNoEndl(MAGENTA, "\"test_files/koala.txt\"   ");
	printColorNoEndl(YELLOW, "\"Target string\"   ");
	printColor(BLUE, "\"String to remplace\"");
	print("Example :");
	printColor(YELLOW, "./sed_is_for_losers   test_files/koala.txt   koala      kangaroo");
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

static void safeClosingFile(fstream& myTargetFile, fstream& myOriginFile){
	if (myOriginFile.is_open())
		myOriginFile.close();
	if (myTargetFile.is_open())
		myTargetFile.close();
}

int main(int ac, char**av){
	if (ac != 4)
		wrongInput();
	
	Utils myStrings(av[1], av[2], av[3]);
	
	// ! delete any occurence of *.replace file
	// myStrings.deleteReplaceFile();
	// deleteReplaceFile(myStrings.getOriginFile());

	// myStringsssssss
	
	// Chekcs if both strings are equal or not, exit if so.
	myStrings.areStringEqual();
	
	// Oppening origin file with checking both read and write permissions
	// ! bug
	fstream myOriginFile(myStrings.getOriginFile().c_str(), fstream::in | fstream::out);
	// fstream myOriginFile("whgrefvergfvj",	 fstream::in | fstream::out);

	
	// ! TO DO : Creating target file
	// Oppening AND target file
	fstream myTargetFile(myStrings.getTargetFile().c_str(), fstream::in | fstream::out);
	
	// myFile.open(fileName, std::ios_base::in & std::ios_base::out);

	if (myOriginFile.is_open() and myTargetFile.is_open())
	{
		
		string currentLine;
		// string temp;
		
		while (getline(myOriginFile, currentLine))
		{
			// temp = currentLine;
			// if (!currentLine.empty())
			replaceCurrentLine(myStrings.getTargetString(), myStrings.getReplaceString(), currentLine);
			myTargetFile << currentLine;
		}
	}
	else
		printColor(RED, "⛔ Failed to open file in both read and write mode ⛔");
	
	safeClosingFile(myTargetFile, myOriginFile);
	
	return (0);
}
