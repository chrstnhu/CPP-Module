/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 17:32:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// Default constructor
ScalarConverter::ScalarConverter() {
	std::cout << ITALICGREEN << "ScalarConverter Default constructor" << DEF << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << ITALICGREEN << "ScalarConverter Copy constructor" << DEF << std::endl;
	*this = other;
}

// Destructor
ScalarConverter::~ScalarConverter() {
	std::cout << ITALICGREEN << "ScalarConverter Destructor" << DEF << std::endl;
}

//Copy assignement operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	std::cout << ITALICGREEN << "ScalarConverter Copy assignement operator" << DEF << std::endl;
	if (this == &other) {
		*this = other;	
	}
	return (*this);
}


// METHODS

// Check if the input has special values
bool ScalarConverter::isSpecialValues(const std::string &input) {
	if (input == "-inff" || input == "+inff" || input == "nanf") {
		return true;
	}
	if (input == "-inf" || input == "+inf" || input == "nan") {
		return true;
	}
	return false;
}

// Handle special values
void ScalarConverter::handleSpecialValues(const std::string &input) {
	printColor("char: impossible", RED, 0);
	printColor("int: impossible", RED, 0);
	if (input == "-inff" || input == "+inff" || input == "nanf") {
		std::cout << "float: " << input << std::endl;
		std::cout <<  "double: " << input.substr(0, input.size() - 1) <<  std::endl;
	} else {
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input.substr(0, input.size()) << std::endl;
	}
}

// Check if the input can be converted 
void ScalarConverter::convert(const std::string &input) {
	if (isSpecialValues(input)) {
		handleSpecialValues(input);
	}
	else if (isChar(input)) {
		convertChar(input);
	}
	else if (isInt(input)) {
		convertInt(input);
	}
	else if (isFloat(input)) {
		convertFloat(input);
	}
	else if (isDouble(input)) {
		convertDouble(input);
	}
	else {
		printColor("Please enter a valid CHAR, INT, FLOAT, DOUBLE", RED, 0);
	}
}
