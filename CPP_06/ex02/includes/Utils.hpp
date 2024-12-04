/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:03:53 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 16:29:38 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

// Libraries
# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>

// Headers
# include "Colors.hpp"
# include "Base.hpp"

void printColor(const std::string &msg, const std::string &color, int needEndl);
void separatorLine(int size);

#endif