#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	std::string str;

	if (argc > 1)
	{
		while (++i < argc && argv[i])
		{
			str = argv[i];
			j = 0;
			while (str[j])
			{
				if (str[j] >= 97 && str[j] <= 122)
					str[j] -=32;
				j++;
			}
			std::cout << str;
		}
		std::cout << "" << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}