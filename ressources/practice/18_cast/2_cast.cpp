#include <iostream>

using namespace std;

int main(void){

	int a = 42;

	int const* b = &a; // okay, because const is higher 
	
	int const *c = (int const*)&a;

	
	int *e = c; // won't compile
	/*
	When not especially specified, the compiler won't work because
       we are trying to access through a pointer a variable which is const,
       and kind of bypass the security of const
	 */
	
	
	int *e = (int * const)c;
	/*
	 * However, we can still bypass the compiler security by explicitely\
	 * casting it as const to still access despite the const
	 *
	*/

	cout << *e << endl;
}
