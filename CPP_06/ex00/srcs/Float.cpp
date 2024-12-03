/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 15:02:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// FLT_MIN and FLT_MAX are the minimum and maximum values of a float
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

// Check if the input is in range
void printChar(float x) {
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

// Check if the value is within the range of an int
void printInt(float x) {
    if (x < static_cast<float>(INT_MIN) || x > static_cast<float>(INT_MAX)) {
        printColor("int: impossible", RED, 0);
        return;
    }

    int i = static_cast<int>(x);
    std::cout << "int: " << i << std::endl;
}

// Check if the value is within the range of a float
void printFloat(float x) {
	if (x >= -FLT_MAX && x <= FLT_MAX) {
		std::cout << "float: " << std::fixed
			<< std::setprecision(1) << x << "f" << std::endl;
	}
	else {
		printColor("float: impossible", RED, 0);
	}
}

// Check if the value is within the range of a double
void printDouble(float x) {
	double d = static_cast<double>(x);
	if (d >= -DBL_MAX && d <= DBL_MAX) {
		std::cout << "double: " << std::fixed
			<< std::setprecision(1) << d << std::endl;
	}
	else {
		printColor("double: impossible", RED, 0);
	}
}

void ScalarConverter::convertFloat(const std::string &input) {
	float x = static_cast<float>(std::atof(input.c_str()));
	
	printChar(x);
	printInt(x);
	printFloat(x);
	printDouble(x);
}

/* int main() {
	printColor("==============TEST FLOAT=============\n", RED, 1);

	printColor("--------vALID test-------", YELLOW, 1);

	printColor("Test case: '-3.0f'", YELLOW, 1);
	ScalarConverter::convertFloat("-3.0f");  // Invalid input for int
	std::cout << std::endl;

	printColor("Test case: '.3f'", YELLOW, 1);
	ScalarConverter::convertFloat(".3f");  // Valid input within char range
	std::cout << std::endl;

	printColor("Test case: '-0.f'", YELLOW, 1);
	ScalarConverter::convertFloat("-0.f");  // Valid input but out of char range
	std::cout << std::endl;

	printColor("Test case: '+3.65841f'", YELLOW, 1);
	ScalarConverter::convertFloat("+3.65841f");  // Invalid input for int
	std::cout << std::endl;

	printColor("Test case: '5.F", YELLOW, 1);
	ScalarConverter::convertFloat("5.f");  // Invalid input for int
	std::cout << std::endl;

	printColor("--------Invalid test-------", YELLOW, 1);

	// Test cases for convertFloat
	printColor("Test case: '42'", YELLOW, 1);
	ScalarConverter::convertFloat("42");  // A valid int input
	std::cout << std::endl;

	printColor("Test case: '-21474836493'", YELLOW, 1);
	ScalarConverter::convertFloat("-21474836493");  // Out of int range (too small)
	std::cout << std::endl;

	printColor("Test case: '-2sdf'", YELLOW, 1);
	ScalarConverter::convertFloat("-2sdf");  // Invalid input (non-integer)
	std::cout << std::endl;

	printColor("Test case: '--1.2'", YELLOW, 1);
	ScalarConverter::convertFloat("--1.2");  // Valid input within char range
	std::cout << std::endl;

	printColor("Test case: '0.'", YELLOW, 1);
	ScalarConverter::convertFloat("0.");  // Valid input but out of char range
	std::cout << std::endl;

	printColor("Test case: '0.0'", YELLOW, 1);
	ScalarConverter::convertFloat("0.0");  // Valid input but out of char range
	std::cout << std::endl;

	return 0;
} */