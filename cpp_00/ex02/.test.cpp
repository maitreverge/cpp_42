#include <iostream>
#include <ctime>

int main(void)
{
	std::time_t time_t_stamp = std::time(NULL);
	std::tm* tm = std::localtime(&time_t_stamp);
	char buffer[16];

	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm);

	std::cout << "[" << buffer << "] " << std::endl;

	return 0;
}