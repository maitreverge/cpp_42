#include <stdio.h>
#include <string>
#include <iostream>

int test_1 = 42;
std::string str = "Hello World";

namespace Foo {
	int test_1 = 21;
	std::string str = "Hello World, okaaaaaaay"; // Use the fully qualified name std::string
}

// ! Les name space sont des micro structures

namespace Bar {
	int test_1 = 6;
	std::string str = "Hello World, pain au chocolatine";
}

// les namespaces differents peuvent avoir des noms de variables identiques a un autre namespace

namespace Short = Bar;

// Aliasing de namespace possible

int main (void) {
	// ! not standart to printf std::string, have to use a converter
	printf("Test 1 scope main = %d\n", test_1);
	printf("STR scope main = %s\n", str.c_str());


	printf("Test 1 scope main = %d\n", Foo::test_1);
	printf("STR scope main = %s\n", Foo::str.c_str());

	printf("Test 1 scope main = %d\n", Short::test_1);
	printf("STR scope main = %s\n", Short::str.c_str()); // on adore la syntaxe
}