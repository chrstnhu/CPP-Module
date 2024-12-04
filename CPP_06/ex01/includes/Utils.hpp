/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 13:45:50 by chrhu            ###   ########.fr       */
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
# include <stdint.h> // serializer

// Headers
# include "Colors.hpp"
# include "Data.hpp"
# include "Serializer.hpp"

void printColor(const std::string &msg, const std::string &color, int needEndl);
void separatorLine(int size);

#endif