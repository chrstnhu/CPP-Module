/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 17:42:18 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// Check if the input is an int
bool ScalarConverter::isInt(const std::string &input) {
	if (input.empty())
		return false;
		
	int i = 0;
	int len = input.length();
	bool hasSign = false;
	if (input[0] == '+' || input[0] == '-') {
		hasSign = true;
		i++;
	}
	for (; i < len; i++) {
		if (!std::isdigit(input[i])) {
			return false;
		}
	}
	return true;
}

// Convert an int to a char
void printChar(int x) {
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

// Convert an int to an float
void printFloat(int x) {
	float f = static_cast<float>(x);
	
	if (f < -FLT_MAX || f > FLT_MAX) {
		printColor("float: impossible", RED, 0);
		return ;
	}
	std::cout << "float: " << std::fixed
		<< std::setprecision(1) << f << "f" << std::endl;
}

// Convert an int to a double
void printDouble(int x) {
	double d = static_cast<double>(x);
	
	if (d < -DBL_MAX && d > DBL_MAX) {
		printColor("double: impossible", RED, 0);
		return ;
    }
	std::cout << "double: " << std::fixed
		<< std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convertInt(const std::string &input) {
	char *end;
	long l = std::strtol(input.c_str(), &end, 10);

	int x = static_cast<int>(l);

	// Print char
    printChar(x);

	// Print int
	if (*end != '\0' || x < INT_MIN || x > INT_MAX) {
		printColor("int: impossible", RED, 0);
    }
	else {
		std::cout << "int: " << x << std::endl;
	}

	// Print float
	printFloat(x);
	
	// Print double
	printDouble(x);
}
