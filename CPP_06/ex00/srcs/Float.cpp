/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/27 14:53:53 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// FLT_MIN and FLT_MAX are the minimum and maximum values of a float
bool ScalarConverter::isFloat(const std::string &input) {
	if (input.empty() || std::strchr(input.c_str(), '.') == NULL) {
		return false;
	}

	int i = 0;
	bool hasSign = false;
	bool hasDot = false;
	if (input[0] == '+' || input[0] == '-') {
		hasSign = true;
		i++;
	}
	
	// Check if the last char is a 'f' or 'F'
	size_t length = input.length();
	if (input[length - 1] != 'f' || input[length - 1] != 'F'){
		return false;
	}
	length--;

	// Check if there is a dot at the beginning
	if (input[i] == '.') {
		hasDot = true;
        i++;
        if (i == length || !std::isdigit(input[i])) {
            return false;
        }
    }

	// Check if is a float
	for (; i < length; i++) {
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

void ScalarConverter::convertFloat(const std::string &input) {
	char c = static_cast<char>(input[0]);

	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

    if (input.compare("nan") == 0) {
		printColor("char: impossible", RED);
	}
	if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
		printColor("char: Non displayable", RED);
    }
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

int main(int ac, char **av) {
	if (ac != 2) {
		printColor("Error: Invalid number of arguments", RED);
		return 1;
	}
	ScalarConverter converter;

	converter.convertFloat(av[1]);
	return 0;
}