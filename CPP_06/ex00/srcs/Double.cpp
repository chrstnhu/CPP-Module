/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/27 12:00:56 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

bool ScalarConverter::isDouble(const std::string &input) {
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
}