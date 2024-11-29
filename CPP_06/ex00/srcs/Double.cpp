/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/29 16:42:21 by chrhu            ###   ########.fr       */
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
	// Check if the input is a special value
	if (input == "-inf" || input == "inf" || input == "nan") {
		return true;
	}
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

static void printChar(double x) {
	// Check if the input is a special value
    if (x != x || x == std::numeric_limits<double>::infinity()
		|| x == -std::numeric_limits<double>::infinity()) {
        printColor("char: impossible", RED, 0);
        return;
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

static void printInt(double x) {
	// Check if the input is a special value
    if (x != x || x == std::numeric_limits<double>::infinity()
		|| x == -std::numeric_limits<double>::infinity()) {
        printColor("int: impossible", RED, 0);
        return;
    }
	int i = static_cast<int>(x);
	if (i >= INT_MIN && i <= INT_MAX) {
		std::cout << "int: " << i << std::endl;
		return ;
	}
	printColor("int: impossible", RED, 0);
}

static void printFloat(double x) {
	// Check if the input is a special value
    if (x != x) {  // x est NaN
        printColor("float: nanf", DEF, 0);
        return;
    }

    // Check if the value is infinity or -infinity
    if (x == std::numeric_limits<double>::infinity()) {
        printColor("float: inff", DEF, 0);
        return;
    }
    if (x == -std::numeric_limits<double>::infinity()) {
        printColor("float: -inff", DEF, 0);
        return;
    }

	float f = static_cast<float>(x);
	if (f >= -FLT_MAX && f <= FLT_MAX) {
		std::cout << "float: " << std::fixed
			<< std::setprecision(1) << f << "f" << std::endl;
		return ;
	}
	printColor("float: impossible", RED, 0);
}

static void printDouble(double x) {
	// Check if the input is a special value

	if (x != x) {
        printColor("double: nan", DEF, 0);
        return;
    }

	// Check if the value is infinity or -infinity
    if (x == std::numeric_limits<double>::infinity()) {
        printColor("double: inf", DEF, 0);
        return;
    }
    if (x == -std::numeric_limits<double>::infinity()) {
        printColor("double: -inf", DEF, 0);
        return;
    }
	if (x >= -DBL_MAX && x <= DBL_MAX) {
		std::cout << "double: " << std::fixed
			<< std::setprecision(1) << x << std::endl;
		return ;
	}
	printColor("double: impossible", RED, 0);
}


void ScalarConverter::convertDouble(const std::string &input) {
    double x = 0.0;

	if (input == "nan") {
        x = std::numeric_limits<double>::quiet_NaN();
    }
    else if (input == "inf") {
        x = std::numeric_limits<double>::infinity();
    }
    else if (input == "-inf") {
        x = -std::numeric_limits<double>::infinity();
    }
	else {
		std::stringstream ss;
		ss << input;
		ss >> x;
	}
	printChar(x);
	printInt(x);
	printFloat(x);
	printDouble(x);
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