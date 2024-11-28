/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/28 16:17:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"


// INT_MIN and INT_MAX are the minimum and maximum values of an int
bool ScalarConverter::isInt(const std::string &input) {
	if (input.empty())
		return false;
		
	int i = 0;
	int len = input.length();
	bool hasSign = input[0] == '+' || input[0] == '-';
	if (hasSign) {
		i++;
	}
	for (; i < len; i++) {
		if (!std::isdigit(input[i])) {
			return false;
		}
	}
	return (i <= 10 || (i == 11 && hasSign));
}

void ScalarConverter::convertInt(const std::string &input) {
	std::stringstream ss;
	ss << input;

	int x = 0;
	ss >> x;

	if (x >= std::numeric_limits<char>::min() && x <= std::numeric_limits<char>::max()) {
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
	
	if (ss.fail() || !ss.eof() || x < INT_MIN_VAL || x > INT_MAX_VAL) {
		printColor("int: impossible", RED, 0);
    }
	else {
		std::cout << "int: " << x << std::endl;
	}
	float f = static_cast<float>(x);
	if (f < FLOAT_MIN_VAL || f > FLOAT_MAX_VAL) {
		printColor("float: impossible", RED, 0);
	}
	else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	
	double d = static_cast<double>(x);
	if (d < DOUBLE_MIN_VAL || d > DOUBLE_MAX_VAL) {
		printColor("double: impossible", RED, 0);
    }
	else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}

}

int main() {
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


	std::cout << PURPLE << std::fixed << std::setprecision(308) << DOUBLE_MIN_VAL << DEF << std::endl;

	return 0;
}