/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:32 by flverge           #+#    #+#             */
/*   Updated: 2024/07/29 11:27:15 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void printUsage( void ){

    printColor(BOLD_RED, "Wrong Argumennts Provided");
    print("Usage :");
    printColorNoEndl(BOLD_GREEN, "./btc      ");
    printColorNoEndl(BOLD_YELLOW, "<input_file>");
}

int main(int ac, char **av){

    // VALUES FROM CSV

    // max   2022-03-29  ,  47115.93
    // min   2009-01-02  ,  0

    // STEP 1 : check basic inputs
    if (ac != 2){

        printUsage();
        return 1;
    }

    string inputFile = av[1];
    string dataFile = "data.csv";

    string promptUser = "";
    do
    {
        printColor(BOLD_YELLOW, "Is \"data.csv\" the main data.file ? ");
        printNoEndl("Type [y] for ");
        printColorNoEndl(BOLD_GREEN, " YES");
        printNoEndl(", [n] for ");
        printColorNoEndl(BOLD_RED, "NO");
        printColorNoEndl(BOLD_YELLOW, "CHOICE : ");
    } while (promptUser != "y" or promptUser != "n" );

    if (promptUser == "n"){

        // clear dataFile variable for future parsing.
        dataFile.clear();
        
        do
        {
            print("Please enter the data file name with the extension");
            printColor(BOLD_YELLOW, "[ Please note that the file need to be at the repo root ]");
        } while (dataFile.empty());
    }
    

    if (not doesFileExists())

    // ! check if data.csv contains a double value

    // ! check if data.csv is corrupted in any way (too much bitcoin)
    

    return 0;
}