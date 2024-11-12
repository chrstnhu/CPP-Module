/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:59:34 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/11 12:48:21 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

# include <iostream>
# include <string>

# define MAX_MATERIA 4

void printColor(const std::string &msg, const std::string &color);
void printOneBloc(const std::string &msg1, int i, const std::string &color);
void printTwoBlocs(const std::string &msg1, const std::string &msg2, const std::string &msg3, int &i , const std::string &color);

#endif