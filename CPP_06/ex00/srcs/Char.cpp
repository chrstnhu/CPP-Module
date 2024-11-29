/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/29 17:22:52 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"
# include <sstream>

bool ScalarConverter::isChar(const std::string &input) {
	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) {
		return true;
	}
	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'') {
		if (std::isprint(input[1])) {
			return true;
		}
	}
	return false;
}

void ScalarConverter::convertChar(const std::string &input) {
	char c = static_cast<char>(input[1]);
	if (input.size() == 1) {
		c = static_cast<char>(input[0]);
	}
	
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	
	if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
		printColor("char: Non displayable", RED, 0);
    }
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

/* int main() {
	printColor("==============TEST CHAR=============\n", RED, 1);

	printColor("Test case 1: '42'", YELLOW, 1);
	ScalarConverter::convertChar("42");
    
	printColor("Test case 2: 'a456'", YELLOW, 1);
	ScalarConverter::convertChar("a456"); // Example with printable char
    
	printColor("Test case 3: '\n'", YELLOW, 1);
	ScalarConverter::convertChar("\n"); // Example with non-displayable char (newline)
    
	printColor("Test case 4: ' '", YELLOW, 1);
	ScalarConverter::convertChar(" "); // Example with space (printable but not often considered "visible")
	
	printColor("Test case 5: 'nan'", YELLOW, 1);
	ScalarConverter::convertChar("nan"); // Example with printable char

	printColor("Test case 6: '127'", YELLOW, 1);
	ScalarConverter::convertChar("127"); // Example with printable char

	printColor("Test case 7: ' '", YELLOW, 1);
	ScalarConverter::convertChar("' '"); // Example with printable char

	printColor("Test case 8: A", YELLOW, 1);
	ScalarConverter::convertChar("A"); // Example with printable char
    return 0;
} */