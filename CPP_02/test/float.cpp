#include <iostream>

int main() {
	float i = 3.6;
	int a =  4;

	std::cout << "Float :" << i  << std::endl;
	if (i == 3.6)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	std::cout << "Integer :" << a << std::endl;
	if (a == 4)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
}