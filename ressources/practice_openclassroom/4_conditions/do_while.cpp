#include <iostream>

int main(void)
{
	int nb(1);

	do
	{
		std::cout << nb << std::endl;
		nb++;
	} while (nb <= 10);
}