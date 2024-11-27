/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/27 16:59:18 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

// Libraries
# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype> // Character handling
# include <climits> // Integer number handling
# include <cfloat> // Float number handling
# include <cstring>
#include <iomanip>
#include <limits> 
#include <sstream> //convert string of digit to int, float, double

// Headers
# include "Colors.hpp"
# include "ScalarConverter.hpp"

void printColor(const std::string &msg, const std::string &color);
void separatorLine();

#endif