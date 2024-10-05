/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:16:48 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/05 14:31:32 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

# define DEF "\033[0;39m"
# define YELLOW "\033[0;33m" 

int main(int ac, char **av) {
	(void)ac;
	if (av[1] != NULL)
	{
		std::cout << YELLOW << " Usage : ./brain " << DEF << std::endl;
		return (1);
	}
	std::string str("HI THIS IS BRAIN");
	std::string str2("Hello");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << YELLOW << "--- Print str ---" << DEF << std::endl;
	std::cout << str << std::endl;
	
	std::cout << YELLOW << "--- Print memory adress ---" << DEF << std::endl;
	std::cout << "   string: " << &str << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << YELLOW << "--- Print value ---" << DEF << std::endl;
	std::cout << "   string: " << str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	
	std::cout << YELLOW << "--- Change ---" << DEF << std::endl;
	std::cout << "string: " << str << std::endl;
	*stringPTR = "Can I change the value with stringPTR ?";
	std::cout << "string: " << str << std::endl;
	stringREF = "Can I also change stringREF ?";
	std::cout << "string: " << str << std::endl;
	str = "HI THIS IS BRAIN ?";
	std::cout << "string: " << str << std::endl;

	std::cout << YELLOW << "--- Reaffecter ---" << DEF << std::endl;
	stringPTR = &str2;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	// stringREF = &str2;
	std::cout << "stringREF: " << stringREF << std::endl;
}
