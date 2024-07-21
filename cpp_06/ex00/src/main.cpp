/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:17:10 by flverge           #+#    #+#             */
/*   Updated: 2024/07/21 09:09:58 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(){

    string promptUser;

    clearScreen();
    
    printColor(BOLD_YELLOW, "Welcome to Scalar Converter");
    
    printColor(BOLD_GREEN, "Type anything to be converted");
    print("Example : 65, k, 2.02f, 42, Hello World, 1000000000000000");
    printColor(BOLD_RED, "Type \"EXIT\" for quitting");
    
    do
    {
        getline(cin, promptUser);

        // trim le prompt des whitespaces

        ScalarConverter::convert(promptUser);
    } while (promptUser != "EXIT");
    
    
    clearScreen();
    
    printColor(BOLD_CYAN, "Thanks for using ScalarConverter");

}