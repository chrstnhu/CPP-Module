/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/29 14:03:37 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

/* // Limits
# define CHAR_MIN_VAL std::numeric_limits<char>::min()
# define CHAR_MAX_VAL std::numeric_limits<char>::max()

# define INT_MIN_VAL std::numeric_limits<int>::min()
# define INT_MAX_VAL std::numeric_limits<int>::max()

# define FLOAT_MIN_VAL -std::numeric_limits<float>::max()
# define FLOAT_MAX_VAL std::numeric_limits<float>::max()

# define DOUBLE_MIN_VAL -std::numeric_limits<double>::max()
# define DOUBLE_MAX_VAL std::numeric_limits<double>::max()
 */
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

void printColor(const std::string &msg, const std::string &color, int needEndl);
void separatorLine();

#endif