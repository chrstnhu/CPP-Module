/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/29 14:07:41 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"


// // INT_MIN and INT_MAX are the minimum and maximum values of an int
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
		
void ScalarConverter::convertInt(const std::string &input) {
	std::stringstream ss;
	ss << input;

	int x = 0;
	ss >> x;

	if (x >= CHAR_MIN && x <= CHAR_MAX) {
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
	if (ss.fail() || !ss.eof() || x < INT_MIN || x > INT_MAX) {
		printColor("int: impossible", RED, 0);
    }
	else {
		std::cout << "int: " << x << std::endl;
	}

	// Print float
	float f = static_cast<float>(x);
	if (f < -FLT_MAX || f > FLT_MAX) {
		printColor("float: impossible", RED, 0);
	}
	else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	
	// Print double
	double d = static_cast<double>(x);
	if (d < -DBL_MAX && d > DBL_MAX) {
		printColor("double: impossible", RED, 0);
    }
	else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}

/* int main() {
	printColor("==============TEST INT=============\n", RED, 1);

    // Test cases for convertInt
	printColor("Test case 1: '42'", YELLOW, 1);
    ScalarConverter::convertInt("42");  // A valid int input
    std::cout << std::endl;

	printColor("Test case 2: '-21474836493'", YELLOW, 1);
    ScalarConverter::convertInt("-21474836493");  // Out of int range (too small)
    std::cout << std::endl;

	printColor("Test case 3: 'a'", YELLOW, 1);
    ScalarConverter::convertInt("a");  // Invalid input (non-integer)
    std::cout << std::endl;
	
	printColor("Test case 4: 'nan'", YELLOW, 1);
    ScalarConverter::convertInt("nan");  // Invalid input for int
    std::cout << std::endl;

	printColor("Test case 5: '127'", YELLOW, 1);
    ScalarConverter::convertInt("127");  // Valid input within char range
    std::cout << std::endl;

	printColor("Test case 6: '-21474836'", YELLOW, 1);
    ScalarConverter::convertInt("-21474836");  // Valid input but out of char range
    std::cout << std::endl;

	return 0;
} */