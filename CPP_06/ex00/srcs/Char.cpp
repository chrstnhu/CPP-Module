/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 15:33:59 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"
# include <sstream>

// Check if the input is a char
bool ScalarConverter::isChar(const std::string &input) {
	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'') {
		if (std::isprint(input[1])) {
			return true;
		}
	}
	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) {
		return true;
	}
	return false;
}


// Convert char to int
static void printInt(char c) {
	int i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;
}

// Convert char to float
static void printFloat(char c) {
	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << std::endl;
}

// Convert char to double
static void printDouble(char c) {
	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << std::endl;
}

// Convert the input to a char
void ScalarConverter::convertChar(const std::string &input) {
	char c = static_cast<char>(input[0]);

	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'') {
		c = static_cast<char>(input[1]);
	}

	if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
		printColor("char: Non displayable", RED, 0);
    }

	printInt(c);
	printFloat(c);
	printDouble(c);
}
