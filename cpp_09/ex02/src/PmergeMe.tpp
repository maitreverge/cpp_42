/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:15:01 by flverge           #+#    #+#             */
/*   Updated: 2024/08/19 12:30:36 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename Container >
PmergeMe< Container >::PmergeMe( void ){}

/**
 * @brief Construct a new Pmerge Me
 * 
 * and append the arguments to _mainContainer.
 * 
 * @param av 
 */
template < typename Container >
PmergeMe< Container >::PmergeMe( char **av ):
    _timeStart(0),
    _timeEnd(0),
    _totalTime(0) {

    for ( size_t i = 0; av[i]; ++i )
	{
		_mainContainer.push_back( std::atoi(av[i]) );
	}
}

template < typename Container >
void PmergeMe< Container >::printContainer( string input ){

    if (input == "Before")
        printColor(BOLD_YELLOW, "Dequeu before sort :");
    else
        printColor(BOLD_GREEN, "Dequeu after sort :");
    
    // We need to use a temp iterator instead of _dequeContainer.end() - 1
    typename Container::iterator tempIt;
    for ( typename Container::iterator it = _mainContainer.begin(); it != _mainContainer.end() ; ++it )
    {
        tempIt = it;
        tempIt++;
        
        printNoEndl(*it);
        if (tempIt != _mainContainer.end())
            printNoEndl(" - ");
    }

    extraLine();
}


template < typename Container >
void    PmergeMe< Container >::printTimeExecution( string input ){

    extraLine();
    
    if (input == "Vector")
        printColorNoEndl(BOLD_BLUE, "Time to process sort with std::vector = ");
    else
        printColorNoEndl(BOLD_BLUE, "Time to process sort with std::deque = ");
    
    _totalTime = static_cast<double>(_timeEnd - _timeStart) / CLOCKS_PER_SEC;
    printColor(BOLD_GREEN, _totalTime);

    extraLine();
}

template < typename Container>
long    PmergeMe< Container >::calculateJacobsthal( int i, std::vector< unsigned long long > &jacob ){

    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    
    return ( jacob[i - 1] + (2 * jacob[i - 2]) ); // Switch from recursive to reference
}


template < typename Container >
void    PmergeMe< Container >::sortContainer( void ){
    
    // Clock in
    this->_timeStart = std::clock();

    // ! STEP 1: If there is an odd number in the vector, push it away
    bool isStruggle = false;
    int struggle = 0;

    if (_mainContainer.size() % 2 != 0) {
        isStruggle = true;
        struggle = *(_mainContainer.end() - 1);
        _mainContainer.pop_back();
    }

    // ! STEP 2: Make pairs of two numbers from the original vector
    std::vector<std::pair<int, int> > pairedVector;

    // Init the double vector and swap the values of big and small number if necessary
    for (typename Container::iterator it = _mainContainer.begin(); it != _mainContainer.end(); ++it) {
        int bigNb = *it;
        int smallNb = *(++it);
        if (bigNb < smallNb)
            std::swap(bigNb, smallNb);
        pairedVector.push_back(std::make_pair(bigNb, smallNb));
    }

    // ! STEP 3: Create two vectors of both big and small numbers
    Container bigNumbers; // the big numbers need to be sorted
    Container smallNumbers;

    for (std::vector<std::pair<int, int> >::iterator it = pairedVector.begin(); it != pairedVector.end(); ++it) {
        int big = it->first;
        int small = it->second;
        
        bigNumbers.push_back(big);
        smallNumbers.push_back(small);
    }

    // Sort the first array
    std::sort(bigNumbers.begin(), bigNumbers.end());


    // ! STEP 4 : Calculate Jacobsthal numbers
    std::vector< unsigned long long > jacobsthalNumbers;
    int n = smallNumbers.size();
    
    for (int i = 0; i < n; ++i) {
        
        unsigned long long jacobsthal = calculateJacobsthal(i, jacobsthalNumbers);
        jacobsthalNumbers.push_back(jacobsthal);
    }

    // ! STEP 5 : Merge the remaining smallNumbers into bigNumbers using Jacobsthal numbers
    // lower_bound is a binary search algo
    for (size_t i = 0; i < jacobsthalNumbers.size(); ++i) {
        
        size_t pos = jacobsthalNumbers[i];
        if (pos < smallNumbers.size()) {
            
            typename Container::iterator insertPos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), smallNumbers[pos]);
            bigNumbers.insert(insertPos, smallNumbers[pos]);
        }
    }

    // If there was an odd number of elements, insert the struggle element
    if (isStruggle) {
        
        typename Container::iterator pos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), struggle);
        bigNumbers.insert(pos, struggle);
    }

    // Replace the original vector with the sorted vector
    this->_mainContainer = bigNumbers;

    // Clock out
    this->_timeEnd = std::clock();
}

template < typename Container >
double  PmergeMe< Container >::getTotalTime( void )const{ return this->_totalTime; }

template < typename Container >
PmergeMe< Container >::PmergeMe( const PmergeMe& copy ) {*this = copy;}


template < typename Container >
PmergeMe< Container >& PmergeMe< Container >::operator=( const PmergeMe& right_operator ){ static_cast<void>(right_operator); return *this; }


template < typename Container >
PmergeMe< Container >::~PmergeMe( void ){}