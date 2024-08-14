#include "PmergeMe.hpp"

static void printUsage( void ){

	printColor(BOLD_RED, "Wrong Usage");

	printNoEndl("Usage: ");
	printColorNoEndl(BOLD_YELLOW, "  ./PmergeMe  ");
	printColor(BOLD_GREEN, "  < positives numbers >   ");

	print("Ex :");
	print("./PmergeMe   5 22 1 8 9 66 44 ");
}

static void  paseArgs( char **av ){

	// ++av;

	// ! Checks if each char is a number
	for ( size_t i = 0; av[i]; ++i )
	{
		for ( size_t j = 0; av[i][j]; ++j )
		{
			if ( not std::isdigit(av[i][j]) )
				throw std::invalid_argument("Invalid Character detected");
		}
		
	}
	// print(av);

	// ! Check if there is no duplicate
	std::vector<int> tempVector;

	for ( size_t i = 0; av[i]; ++i )
	{
		if ( atol(av[i]) > __INT_MAX__ or atol(av[i]) < 0 )
			throw std::out_of_range("INT_MAX / Negative value detected");
		tempVector.push_back( std::atoi(av[i]) );
	}

	

	// for (std::vector<int>::iterator it = tempVector.begin(); it != tempVector.end(); ++it)
	// {
	// 	print(*it);
	// }

	// ! Check for duplicate numbers in a sorted vector
	std::sort(tempVector.begin(), tempVector.end());
	std::vector<int>::iterator it = std::unique(tempVector.begin(), tempVector.end());


	// return ( it != tempVector.end() ) ? false : true;

	if ( it != tempVector.end())
		throw std::invalid_argument("Duplicate Value detected");
}

int main( int ac, char**av ){
	
	if (ac < 2){
		
		printUsage();
		return 1;
	}

	try
	{
		paseArgs(++av);
	}
	catch(const std::exception& e)
	{
		std::cerr <<BOLD_RED << e.what() << RESET << '\n';
		return 1;
	}

	// Constructor + append to the list
	PmergeMe pmerge(av);

	pmerge.printVector("Before");

	pmerge.sortVector();

	pmerge.printVector("After");

	pmerge.printTimeExecution("Vector");

	//=========================

	pmerge.printList("Before");

	pmerge.sortList();

	pmerge.printList("After");

	pmerge.printTimeExecution("List");
	// print("Hello");
	
}
