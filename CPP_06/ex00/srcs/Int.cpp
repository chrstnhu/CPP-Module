/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 17:36:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/Utils.hpp"

// INT_MIN and INT_MAX are the minimum and maximum values of an int
static bool isInt(const std::string &input) {
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
