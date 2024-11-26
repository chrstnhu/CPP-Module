/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 18:54:53 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/Utils.hpp"

// FLT_MIN and FLT_MAX are the minimum and maximum values of a float
static bool isFloat(const std::string &input) {
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
	
	// Check if the last char is a "f"
	size_t length = input.length();
	if (input[input.length() - 1] == 'f'){
		length--;
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