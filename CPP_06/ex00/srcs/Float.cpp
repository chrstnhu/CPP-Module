/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/29 15:28:57 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// FLT_MIN and FLT_MAX are the minimum and maximum values of a float
bool ScalarConverter::isFloat(const std::string &input)
{
	if (input.compare("-inff") == 0 || input.compare("inff") == 0 || input.compare("nanf") == 0) {
		return true;
	}
	if (std::strchr(input.c_str(), '.') == NULL) {
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
			if (hasDot)
			{
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

bool printPseudoLitteralF(std::string input, std::string type, int isDouble)
{
	if (input.compare("nanf") == 0 || input.compare("-inff") == 0 || input.compare("inff") == 0)
	{
		if (isDouble) {
			printColor(type + ": " + input.substr(0, input.size() - 1), DEF, 0);
			return true;
		}
		printColor(type + ": " + input, DEF, 0);
		return true;
	}
	return false;
}

void printChar(std::string input, float x)
{
	if (input.compare("nan") == 0 || input.compare("-inf") == 0 || input.compare("inf") == 0) {
		printColor("char: impossible", RED, 0);
		return ;
	}
	if (x >= CHAR_MIN && x <= CHAR_MAX) {
		char c = static_cast<char>(x);
		if (std::isprint(c)) {
			std::cout << "char: '" << c << "'" << std::endl;
			return;
		}
		else {
			printColor("char: Non displayable", RED, 0);
			return;
		}
	}
	printColor("char: impossible", RED, 0);
}

void printInt(std::string input, float x)
{
	if (input == "nanf" || input == "-inff" || input == "inff") {
		printColor("int: impossible", RED, 0);
		return;
	}

	int i = static_cast<int>(x);
	if (i >= INT_MIN && i <= INT_MAX) {
		std::cout << "int: " << i << std::endl;
		return;
	}
	printColor("int: impossible", RED, 0);
}

void printFloat(std::string input, float x)
{
	if (printPseudoLitteralF(input, "float", 0)) {
		return;
	}

	float f = static_cast<float>(x);
	if (f >= -FLT_MAX && f <= FLT_MAX) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		return;
	}
	printColor("float: impossible", RED, 0);
}

void printDouble(std::string input, float x)
{
	if (printPseudoLitteralF(input, "double", 1)) {
		return;
	}

	double d = static_cast<double>(x);
	if (d >= -DBL_MAX && d <= DBL_MAX) {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return;
	}
	printColor("double: impossible", RED, 0);
}

void ScalarConverter::convertFloat(const std::string &input)
{
	float x = 0.0f;
	std::cout << "input: " << input << std::endl;
	if (input.compare("nanf") == 0) {
		x = static_cast<float>(std::numeric_limits<float>::quiet_NaN());
	}
	else if (input.compare("-inff") == 0) {
		x = static_cast<float>(-std::numeric_limits<float>::infinity());
	}
	else if (input.compare("inff") == 0) {
		x = static_cast<float>(std::numeric_limits<float>::infinity());
	}
	else {
		x = static_cast<float>(std::atof(input.c_str()));
		// std::stringstream ss;
		// ss << input;
		// ss >> x;
	}

	// std::stringstream ss;
	// ss << input;

	// float x = 0;
	// ss >> x;

	/*
	if (x >= CHAR_MIN_VAL && x <= CHAR_MAX_VAL) {
		char c = static_cast<char>(x);
		if (std::isprint(c)) {
			std::cout << "char: '" << c << "'" << std::endl;
		}
		else {
			printColor("char: Non displayable", RED, 0);
		}
	} else {
		printColor("char: impossible", RED, 0);
	}

	// Print int
	if (ss.fail() || !ss.eof() || x < INT_MIN_VAL || x > INT_MAX_VAL) {
		printColor("int: impossible", RED, 0);
	}
	else {
		std::cout << "int: " << x << std::endl;
	}

	// Print float
	float f = static_cast<float>(x);
	if (f < FLOAT_MIN_VAL || f > FLOAT_MAX_VAL) {
		printColor("float: impossible", RED, 0);
	}
	else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}

	// Print double
	double d = static_cast<double>(x);
	if (d < DOUBLE_MIN_VAL || d > DOUBLE_MAX_VAL) {
		printColor("double: impossible", RED, 0);
	}
	else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	*/

	printChar(input, x);
	printInt(input, x);
	printFloat(input, x);
	printDouble(input, x);
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