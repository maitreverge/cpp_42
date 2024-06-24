#include <iostream>

void	test_positive(int nb)
{
	if (nb > 0)
		std::cout << "Number is positive" << std::endl;
	else if (nb < 0)
		std::cout << "Number is negative" << std::endl;
	else
		std::cout << "Number is zero" << std::endl;
}

int main(void)
{
	int number(0.0);

	test_positive(number);

	return 0;
}