#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;

	if (argc > 1)
	{
		while (++i < argc && argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] >= 97 &&argv[i][j] <= 122)
					argv[i][j] -=32;
				j++;
			}
			std::cout << argv[i];
		}
		std::cout << "" << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

