/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 15:06:03 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << ITALICGREEN << "ScalarConverter Default constructor" << DEF << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << ITALICGREEN << "ScalarConverter Copy constructor" << DEF << std::endl;
	*this = other;
}

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

bool ScalarConverter::isSpecialValues(const std::string &input) {
	if (input == "-inff" || input == "inff" || input == "nanf") {
		return true;
	}
	if (input == "-inf" || input == "inf" || input == "nan") {
		return true;
	}
	return false;
}

void ScalarConverter::handleSpecialValues(const std::string &input) {
	float f = static_cast<float>(std::atof(input.c_str()));
    double d = 0.0;

	std::stringstream ss;
	
	ss << input;
	ss >> d;
	
	if (input == "nan" || input == "nanf" 
		|| f != f || d != d) {
        printColor("int: impossible", RED, 0);
        printColor("char: impossible", RED, 0);
        printColor("float: nanf", DEF, 0);
        printColor("double: nan", DEF, 0);

    }
    if (input == "inf" || input == "inff" 
		|| f == std::numeric_limits<float>::infinity()
		|| d == std::numeric_limits<double>::infinity()) {
        printColor("char: impossible", RED, 0);
        printColor("int: impossible", RED, 0);
        printColor("float: inff", DEF, 0);
        printColor("double: inf", DEF, 0);

    }
    if (input == "-inf" || input == "-inff" 
		|| f == -std::numeric_limits<float>::infinity()
		|| d == -std::numeric_limits<double>::infinity()) {
        printColor("char: impossible", RED, 0);
        printColor("int: impossible", RED, 0);
        printColor("float: -inff", DEF, 0);
        printColor("double: -inf", DEF, 0);
    }
}

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
		printColor("char: impossible", RED, 0);
        printColor("int: impossible", RED, 0);
		printColor("float: impossible", RED, 0);
        printColor("double: impossible", RED, 0);
	}
}
