/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/27 17:04:15 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"
# include <sstream>

bool ScalarConverter::isChar(const std::string &input) {
	if (input.empty())
		return false;
	
	for (int i; i < input.length(); i++) {
		if (!std::isprint(input[i])) {
			return false;
		}
	}
	return true;
}

void ScalarConverter::convertChar(const std::string &input) {
	char c = static_cast<char>(input[0]);
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	
	if (input.length() != 1) {
		printColor("char: impossible", RED);
	} else if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
		printColor("char: Non displayable", RED);
    }
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

int main() {
	std::cout << YELLOW << "Test case 1: '42'" << DEF << std::endl;
	ScalarConverter::convertChar("42");
    
	std::cout << YELLOW << std::endl << "Test case 2: 'a456'" << DEF<< std::endl;
	ScalarConverter::convertChar("a456"); // Example with printable char
    
	std::cout << YELLOW << std::endl << "Test case 3: ' '" << DEF<< std::endl;
	ScalarConverter::convertChar("\n"); // Example with non-displayable char (newline)
    
	std::cout << YELLOW << std::endl << "Test case 4: ' '" << DEF<< std::endl;
	ScalarConverter::convertChar(" "); // Example with space (printable but not often considered "visible")
	
	std::cout << YELLOW << std::endl << "Test case 5: 'nan'" << DEF<< std::endl;
	ScalarConverter::convertChar("nan"); // Example with printable char

	std::cout << YELLOW << std::endl << "Test case 6: 'A'" << DEF<< std::endl;
	ScalarConverter::convertChar("A"); // Example with printable char
    return 0;
}