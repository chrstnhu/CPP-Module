/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 19:17:07 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// Check if the input is a double
bool ScalarConverter::isDouble(const std::string &input) {
	// Check if the input is a float
	if (std::strchr(input.c_str(), '.') == NULL
		|| input[input.size() - 1] == 'f'
		|| input[input.size() - 1] == 'F') {
		return false;
	}

	size_t i = 0;
	bool hasDot = false;

	// Check if there is a sign
	if (input[0] == '+' || input[0] == '-') {
		i++;
	}
	// Check if there is double
    for (; i < input.size(); i++) {
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

// Convert a double to a char
static void printChar(double x) {
	// Check if the value is within the range of a char
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
	
// Convert a double to an int
static void printInt(double x) {
	// Check if the value is within the range of an int
    if (x < static_cast<double>(INT_MIN) || x > static_cast<double>(INT_MAX)) {
        printColor("int: impossible", RED, 0);
		return ;
    }

	int i = static_cast<int>(x);
	std::cout << "int: " << i << std::endl;
}

// Convert a double to a float
static void printFloat(double x) {
	// Check if the value is within the range of a float
	if (x < static_cast<double>(-FLT_MAX) || x > static_cast<double>(FLT_MAX)) {
		printColor("float: impossible", RED, 0);
		return ;
	}
	
	float f = static_cast<float>(x);
	std::cout << "float: " << std::fixed
		<< std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::convertDouble(const std::string &input) {
	char *end;
    double x = std::strtod(input.c_str(), &end);
	
	if (end == input.c_str()) {
		printColor("impossible to convert", RED, 0);
		return;
	}
	
	// Print char
	printChar(x);

	// Print int
	printInt(x);
	
	// Print float
	printFloat(x);

	// Print double
	if (x < -DBL_MAX || x > DBL_MAX) {
		printColor("double: impossible", RED, 0);
		return ;
	}
    std::cout << "double: " << std::fixed
		<< std::setprecision(1) << x << std::endl;
}
