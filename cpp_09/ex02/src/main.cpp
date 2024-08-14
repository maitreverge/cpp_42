#include "PmergeMe.hpp"

static void printUsage( void ){

	printColor(BOLD_RED, "Wrong Usage");

	printNoEndl("Usage: ");
	printColorNoEndl(BOLD_YELLOW, "  ./PmergeMe  ");
	printColor(BOLD_GREEN, "  < positives numbers >   ");

	print("Ex :");
	print("./PmergeMe   5 22 1 8 9 66 44 ");
}

static bool correctArgs( char **av ){

	++av;

	// ! Checks if each char is a number
	for (size_t i = 0; av[i]; ++i)
	{
		for (size_t j = 0; av[i][j]; ++j)
		{
			if ( not std::isdigit(av[i][j]) )
				return false;
		}
		
	}
	// print(av);

	// ! Check if there is no duplicate
	std::vector<int> tempVector;

	for (size_t i = 0; av[i]; ++i)
	{
		tempVector.push_back( std::atoi(av[i]) );
	}

	
	std::sort(tempVector.begin(), tempVector.end());

	for (std::vector<int>::iterator it = tempVector.begin(); it != tempVector.end(); ++it)
	{
		print(*it);
	}

	std::vector<int>::iterator it = std::unique(tempVector.begin(), tempVector.end());

	return ( it != tempVector.end() ) ? false : true;

	// if ( it != tempVector.end()){

	// 	printColor(BOLD_RED, "Duplicate nb has been found");
	// 	return false;
	// }


	// return true;
}

int main( int ac, char**av ){
	
	if ( ac < 2){
		
		printUsage();
		return 1;
	}

	if ( not correctArgs(av) ){

		printUsage();
		return 1;
	}
}
