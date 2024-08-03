/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:53:32 by flverge           #+#    #+#             */
/*   Updated: 2024/08/03 17:23:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void printUsage( void ){

    printColor(BOLD_RED, "Wrong Argumennts Provided");
    print("Usage :");
    printColorNoEndl(BOLD_GREEN, "./btc      ");
    printColorNoEndl(BOLD_YELLOW, "<input_file>");
}

/**
 * @brief Wrapper function initial check of :
 * - argc
 * - Letting the user type a net datafile
 * - Checking access write to both input and data file
 * 
 * @param btc 
 * @param ac 
 * @param av 
 * @return true 
 * @return false 
 */
static bool isPreCheckValid( BitcoinExchange &btc, int &ac, char **av ){

    if (ac != 2){

        printUsage();
        return false;
    }
    
    btc.setInputFile(av[1]);
    
    btc.setDataFile("data.csv");

    string promptUser = "";
    
    // User either confirms or not if data.csv is still the correct file
    do
    {
        printColor(BOLD_YELLOW, "Is \"data.csv\" the main data.file ? ");
        printNoEndl("Type [y] for ");
        printColor(BOLD_GREEN, " YES");
        printNoEndl("[n] for ");
        printColor(BOLD_RED, "NO");
        printColorNoEndl(BOLD_YELLOW, "CHOICE : ");
        getline(cin, promptUser);
        print("Debug prompt = " + promptUser);
    } while (promptUser != "y" and promptUser != "n" );

    // Let's the user prompt the desired file
    if (promptUser == "n"){

        btc.setDataFile("");
        promptUser.clear();        
        
        do
        {
            print("Please enter the data file name with the extension");
            printColor(BOLD_YELLOW, "[ Make sure the file needs to be at the repo's root ]");
            getline(cin, promptUser);
            btc.setDataFile(promptUser);
        } while (btc.getDataFile().empty());
    }
    
    // Checks access file
    // if (not doesFileExists(btc.getInputFile())
    //     or not doesFileExists(btc.getDataFile())){

    //     printColor(BOLD_RED, "Either input file or data file can't be accessed");
    //     return false;
    // }

    // un-factored function for debugging
    if ( not doesFileExists(btc.getDataFile()) ){

        print(btc.getDataFile());
        printColor(BOLD_RED, "Either input file or data file can't be accessed");
        return false;
    }
    if (not doesFileExists(btc.getInputFile()) ){

        print(btc.getInputFile());
        printColor(BOLD_RED, "Either input file or data file can't be accessed");
        return false;
    }

    return true;
}

int main(int ac, char **av){

    BitcoinExchange btc;

    if (not isPreCheckValid(btc, ac, av))
        return (1);
    
    // ! map data done
    btc.mapData();
    
    // ! check if data.csv is corrupted in any way ()
    btc.mapInput();

    btc.printDataFile();

    btc.printInputFile();
    

    return 0;
}