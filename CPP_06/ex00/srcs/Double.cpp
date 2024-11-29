/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/29 15:23:26 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

/* bool ScalarConverter::isDouble(const std::string &input) {
	if (input.empty() || std::strchr(input.c_str(), '.') == NULL) {
		return false;
	}

	int i = 0;
	bool hasDot = false;
	if (input[0] == '+' || input[0] == '-') {
		i++;
	}

	// Check if there is a dot at the beginning
	if (input[i] == '.') {
		hasDot = true;
        i++;
        if (i == input.length() || !std::isdigit(input[i])) {
            return false;
        }
    }

	// Check if is a float
	for (; i < input.length(); i++) {
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
} */

bool ScalarConverter::isDouble(const std::string &input) {
	if (input.compare("-inf") == 0 || input.compare("inf") == 0 || input.compare("nan") == 0) {
		return true;
	}
	if (std::strchr(input.c_str(), '.') == NULL
		|| input[input.size() - 1] == 'f' || input[input.size() - 1] == 'F') {
		return false;
	}

	size_t i = 0;
	
	// Check if there is a sign
	if (input[0] == '+' || input[0] == '-') {
		i++;
	}

    bool hasDot = false;
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

//**********************************************************************
bool printPseudoLitteral(std::string input, std::string type, int isDouble) {
	if (input.compare("nan") == 0 || input.compare("-inf") == 0 || input.compare("inf") == 0) {
		if (isDouble) {
			printColor(type + ": " + input, DEF, 0);
			return true;
		}
		printColor(type + ": " + input + "f", DEF, 0);
		return true;
	}
	return false;
}


static void printChar(std::string input, float x) {
	if (input.compare("nan") == 0 || input.compare("-inf") == 0 || input.compare("inf") == 0) {
		printColor("char: impossible", RED, 0);
		return ;
	}
	if (x >= CHAR_MIN && x <= CHAR_MAX) {
		char c = static_cast<char>(x);
		if (std::isprint(c)) {
			std::cout << "char: '" << c << "'" << std::endl;
			return ;
		}
		else {
			printColor("char: Non displayable", RED, 0);
			return ;
		}
	}
	printColor("char: impossible", RED, 0);
}

static void printInt(std::string input, float x) {
	if (input.compare("nan") == 0 || input.compare("-inf") == 0 || input.compare("inf") == 0) {
		printColor("int: impossible", RED, 0);
		return ;
	}
	int i = static_cast<int>(x);
	if (i >= INT_MIN && i <= INT_MAX) {
		std::cout << "int: " << i << std::endl;
		return ;
	}
	printColor("int: impossible", RED, 0);
}

static void printFloat(std::string input, float x) {
	if (printPseudoLitteral(input, "float", 0)) {
		return ;
	}
	float f = static_cast<float>(x);
	if (f >= -FLT_MAX && f <= FLT_MAX) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		return ;
	}
	printColor("float: impossible", RED, 0);
}

static void printDouble(std::string input, float x) {
	if (printPseudoLitteral(input, "double", 1)) {
		return ;
	}
	double d = static_cast<double>(x);
	if (d >= -DBL_MAX && d <= DBL_MAX) {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return ;
	}
	printColor("double: impossible", RED, 0);
}

void ScalarConverter::convertDouble(const std::string &input) {
	std::stringstream ss;
	ss << input;

	double x = 0;
	ss >> x;

	printChar(input, x);
	printInt(input, x);
	printFloat(input, x);
	printDouble(input, x);
}

/*
int main() {
	printColor("==============TEST FLOAT=============\n", RED, 1);

	printColor("--------vALID test-------", YELLOW, 1);

	printColor("Test case: '-3.0'", YELLOW, 1);
    ScalarConverter::convertDouble("-3.0");  // Invalid input for int
    std::cout << std::endl;

	printColor("Test case: '.3'", YELLOW, 1);
    ScalarConverter::convertDouble(".3");  // Valid input within char range
    std::cout << std::endl;

	printColor("Test case: '-0.'", YELLOW, 1);
    ScalarConverter::convertDouble("-0.");  // Valid input but out of char range
    std::cout << std::endl;

	printColor("Test case: '+3.65841'", YELLOW, 1);
    ScalarConverter::convertDouble("+3.65841");  // Invalid input for int
    std::cout << std::endl;

	printColor("Test case: '5.45646", YELLOW, 1);
    ScalarConverter::convertDouble("5.45646");  // Invalid input for int
    std::cout << std::endl;
	
	printColor("--------Invalid test-------", YELLOW, 1);

    // Test cases for convertDouble
	printColor("Test case: '42'", YELLOW, 1);
    ScalarConverter::convertDouble("42");  // A valid int input
    std::cout << std::endl;

	printColor("Test case: '-21474836493'", YELLOW, 1);
    ScalarConverter::convertDouble("-21474836493");  // Out of int range (too small)
    std::cout << std::endl;

	printColor("Test case: '-2sdf'", YELLOW, 1);
    ScalarConverter::convertDouble("-2sdf");  // Invalid input (non-integer)
    std::cout << std::endl;
	
	printColor("Test case: '--1.2'", YELLOW, 1);
    ScalarConverter::convertDouble("--1.2");  // Valid input within char range
    std::cout << std::endl;

	printColor("Test case: '0.F'", YELLOW, 1);
    ScalarConverter::convertDouble("0.F");  // Valid input but out of char range
    std::cout << std::endl;

	printColor("Test case: '6.0f'", YELLOW, 1);
    ScalarConverter::convertDouble("0.0f");  // Valid input but out of char range
    std::cout << std::endl;

	return 0;
}*/