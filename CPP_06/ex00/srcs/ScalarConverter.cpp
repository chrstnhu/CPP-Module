/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 18:15:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/Utils.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << ITALICGREEN << "ScalarConverter Default constructor" << DEF << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << ITALICGREEN << "ScalarConverter Copy constructor" << DEF << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << ITALICGREEN << "ScalarConverter Destructor" << DEF << std::endl;
}

//Copy assignement operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	std::cout << ITALICGREEN << "ScalarConverter Copy assignement operator" << DEF << std::endl;
	if (this == &other) {
		
	}
	return (*this);
}

void ScalarConverter::convert(const std::string &input) {

}
