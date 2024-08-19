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

static void		printResume( PmergeMe< std::vector<int> > &vectorPmerge, PmergeMe< std::deque<int> > &dequePmerge ){

	extraLine();

	printColorNoEndl(BOLD_YELLOW, "=============");
	printColorNoEndl(BOLD_YELLOW, "  RESUME  ");
	printColor(BOLD_YELLOW, "=============");

	extraLine();

	printNoEndl("Total time for std::vector Container = ");
	printColor(BOLD_CYAN, vectorPmerge.getTotalTime());

	printNoEndl("Total time for std::deque Container = ");
	printColor(BOLD_CYAN, dequePmerge.getTotalTime());

	extraLine();

	printColor(BOLD_YELLOW, "The time difference between vector and deque containers is :");

	double timeDifference = dequePmerge.getTotalTime() - vectorPmerge.getTotalTime();


	if (timeDifference < 0) // Vector Slower
		printColor(BOLD_GREEN, timeDifference);
	else // Deque slower
		printColor(BOLD_GREEN, timeDifference);

	printNoEndl("Which makes a difference of ");

	printColorNoEndl(BOLD_GREEN, " + ");
	printColorNoEndl(BOLD_GREEN, ( ((dequePmerge.getTotalTime()) / vectorPmerge.getTotalTime() ) - 1) * 100);
	printColorNoEndl(BOLD_GREEN, " %");

	extraLine();

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

	// ================ VECTOR CONTAINER =================

	PmergeMe< std::vector<int> > vectorPmerge(av);

	vectorPmerge.printContainer("Before");

	vectorPmerge.sortContainer();

	vectorPmerge.printContainer("After");
	
	vectorPmerge.printTimeExecution("Vector");

	// ================ DEQUE CONTAINER =================

	PmergeMe< std::deque<int> > dequePmerge(av);

	dequePmerge.printContainer("Before");

	dequePmerge.sortContainer();

	dequePmerge.printContainer("After");
	
	dequePmerge.printTimeExecution("Deque");


	// ================ PRINT RESUME =================

	printResume(vectorPmerge, dequePmerge);

}
