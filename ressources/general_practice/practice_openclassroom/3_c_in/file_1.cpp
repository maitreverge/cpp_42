#include <iostream>

int main(void)
{
	int a, b;

	std::cout << "What is a : " << std::endl;

	std::cin >> a;

	std::cout << "a = " << a << std::endl;

	std::cout << "What is b : " << std::endl;

	std::cin >> b;

	std::cout << "b = " << b << std::endl;

	std::cout << "Result = " << a + b << std::endl;
}