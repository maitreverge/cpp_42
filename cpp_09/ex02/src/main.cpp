#include "PmergeMe.hpp"

static void printUsage( void ){

	printColor(BOLD_RED, "Wrong Usage");

	printNoEndl("Usage: ");
	printColorNoEndl(BOLD_YELLOW, "  ./PmergeMe  ");
	printColor(BOLD_GREEN, "  < positives numbers >   ");

	print("Ex :");
	print("./PmergeMe   5 22 1 8 9 66 44 ");
}
int main( int ac, char**av ){
	
	if ( ac < 2){
		
		printUsage();
		return 1;
	}
}
