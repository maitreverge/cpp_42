/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:17:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/21 17:29:02 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ! Add to templates
// This function trims leading and trailing whitespace from a given string.
string trimWhitespace(const string& str) {
    // Copy the input string to a new string which will be trimmed
    string trimmed = str;

    // Find the first character position after leading whitespace
    string::size_type left = trimmed.find_first_not_of(" \t\n\r");

    // Find the last character position before trailing whitespace
    string::size_type right = trimmed.find_last_not_of(" \t\n\r");
    
    // If both 'left' and 'right' are not string::npos (indicating that the string is not all whitespace)
    if (left != string::npos && right != string::npos) {
        // Trim the string by taking a substring from 'left' to 'right'
        trimmed = trimmed.substr(left, right - left + 1);
    } else {
        // If the string is all whitespace, clear it
        trimmed.clear();
    }
    
    // Return the trimmed string
    return trimmed;
}

int main(){

    string promptUser;

    clearScreen();
    
    printColor(BOLD_YELLOW, "Welcome to Scalar Converter");
    
    printColor(BOLD_GREEN, "Type anything to be converted");
    print("Example : 65, k, 2.02f, 42, Hello World, 1000000000000000");
    print("You can also type limits such as : \"+inff\", \"+inf\", \"-inff\", \"-inf\", \"nan\", \"nanf\"");
    printColor(BOLD_RED, "Type \"EXIT\" for quitting");
    
    do
    {
        getline(cin, promptUser);

        promptUser = trimWhitespace(promptUser);

        ScalarConverter::convert(promptUser);
    } while (promptUser != "EXIT");
    
    
    clearScreen();
    
    printColor(BOLD_CYAN, "Thanks for using ScalarConverter");

}

#include <string>
#include <cctype>
