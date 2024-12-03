/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 15:34:53 by chrhu            ###   ########.fr       */
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
    if (x < static_cast<float>(INT_MIN) || x > static_cast<float>(INT_MAX)) {
        printColor("int: impossible", RED, 0);
		return ;
    }

	int i = static_cast<int>(x);
	std::cout << "int: " << i << std::endl;
}

// Convert a double to a float
static void printFloat(double x) {
	float f = static_cast<float>(x);
	
	// Check if the value is within the range of a float
	if (f < -FLT_MAX || f > FLT_MAX) {
		printColor("float: impossible", RED, 0);
		return ;
	}
	std::cout << "float: " << std::fixed
		<< std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::convertDouble(const std::string &input) {
    double x = 0.0;

	std::stringstream ss;
	
	ss << input;
	ss >> x;

	// Print char
	printChar(x);

	// Print int
	printInt(x);
	
	// Print float
	printFloat(x);

	// Print double
	if (ss.fail() || !ss.eof() || x < -DBL_MAX || x > DBL_MAX) {
		printColor("double: impossible", RED, 0);
		return ;
	}
    std::cout << "double: " << std::fixed
		<< std::setprecision(1) << x << std::endl;
}
