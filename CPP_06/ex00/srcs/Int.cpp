/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/27 16:58:16 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// INT_MIN and INT_MAX are the minimum and maximum values of an int
bool ScalarConverter::isInt(const std::string &input) {
	if (input.empty())
		return false;
		
	int i = 0;
	bool hasSign = input[0] == '+' || input[0] == '-';
	if (hasSign) {
		i++;
	}
	while (i++ < input.length()) {
		if (!std::isdigit(input[i])) {
			return false;
		}
	}
	if (i > 10 || (i > 11 && hasSign))
		return false;
	return true;
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
			printColor("char: Non displayable", RED);
		}
	} else {
		printColor("char: impossible", RED);
	}
	
	std::cout << "int: " << x << std::endl;

	float f = static_cast<float>(x);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	
	double d = static_cast<double>(x);
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

int main() {
    // Test cases for convertInt
    std::cout << "Test case 1: '42'" << std::endl;
    ScalarConverter::convertInt("42");  // A valid int input
    std::cout << std::endl;

    std::cout << "Test case 2: '-21474836493'" << std::endl;
    ScalarConverter::convertInt("-21474836493");  // Out of int range (too small)
    std::cout << std::endl;

    std::cout << "Test case 3: 'a'" << std::endl;
    ScalarConverter::convertInt("a");  // Invalid input (non-integer)
    std::cout << std::endl;

    std::cout << "Test case 4: 'nan'" << std::endl;
    ScalarConverter::convertInt("nan");  // Invalid input for int
    std::cout << std::endl;

    std::cout << "Test case 5: '127'" << std::endl;
    ScalarConverter::convertInt("127");  // Valid input within char range
    std::cout << std::endl;

    std::cout << "Test case 6: '128'" << std::endl;
    ScalarConverter::convertInt("128");  // Valid input but out of char range
    std::cout << std::endl;

    return 0;
}