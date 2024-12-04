/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/03 19:30:04 by chrhu            ###   ########.fr       */
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
# include <iomanip>
# include <limits> 

// Headers
# include "Colors.hpp"
# include "ScalarConverter.hpp"

void printColor(const std::string &msg, const std::string &color, int needEndl);
void separatorLine();

#endif