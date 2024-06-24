#include <iostream>
#include <string>

int main(void)
{
	int nombres[5];

	for (int i = 0; i <= 4; i++)
		nombres[i] = i * 2;
	
	for (int i = 0; i < 600; i++)
		std::cout << nombres[i] << std::endl;
	
}