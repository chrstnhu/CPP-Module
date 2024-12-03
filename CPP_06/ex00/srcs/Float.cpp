/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 19:17:00 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// Check if the input is a float
bool ScalarConverter::isFloat(const std::string &input) {
	if (input.find('.') == std::string::npos
		|| input == ".f" || input == ".F") {
		return false;
	}

	size_t i = 0;
	size_t length = input.size();

	// Check if there is a sign
	if (input[0] == '+' || input[0] == '-') {
		i++;
	}

	// Check if the last char is a 'f' or 'F'
	if (input[length - 1] != 'f' && input[length - 1] != 'F') {
		return false;
	}
	length--;

	bool hasDot = false;
	for (; i < length - 1; i++) {
		if (input[i] == '.') {
			if (hasDot) {
				return false;
			}
			hasDot = true;
		}
		else if (!std::isdigit(input[i])) {
			return false;
		}
	}
	return true;
}

// Convert a float to a char
void printChar(float x) {
	// Check if the input is in range
    if (x <= CHAR_MIN || x >= CHAR_MAX ) {
        printColor("char: impossible", RED, 0);
        return;
    }
	
	char c = static_cast<char>(x);
	if (std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else {
		printColor("char: Non displayable", RED, 0);
	}
}

// Convert a float to an int
void printInt(float x) {
	// Check if the value is within the range of an int
    if (x < static_cast<float>(INT_MIN) || x > static_cast<float>(INT_MAX)) {
        printColor("int: impossible", RED, 0);
        return;
    }

    int i = static_cast<int>(x);
    std::cout << "int: " << i << std::endl;
}

// Convert a float to a double
void printDouble(float x) {
	// Check if the value is within the range of a double
	if (x < static_cast<float>(-DBL_MAX) || x > static_cast<float>(DBL_MAX)) {
		printColor("double: impossible", RED, 0);
		return ;
	}

	double d = static_cast<double>(x);
	std::cout << "double: " << std::fixed
		<< std::setprecision(1) << d << std::endl;
}


void ScalarConverter::convertFloat(const std::string &input) {
	char *end;
	float x = std::strtof(input.c_str(), &end);
	
	if (*end != '\0' && (*end != 'f' && *end != 'F')) {
		printColor("impossible to convert", RED, 0);
		return;
	}
	// Print char
	printChar(x);

	// Print int
	printInt(x);
	
	// Print float
	if (x < -FLT_MAX || x > FLT_MAX) {
		printColor("float: impossible", RED, 0);
	}
	else {
		std::cout << "float: " << std::fixed
			<< std::setprecision(1) << x << "f" << std::endl;
	}

	// Print double
	printDouble(x);
}
