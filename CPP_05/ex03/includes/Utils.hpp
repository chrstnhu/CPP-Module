/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 14:04:34 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

// Libraries
# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream> // std::ofstream file

// Headers
# include "Colors.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "SchrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

void printColor(const std::string &msg, const std::string &color);
void separatorLine();

#endif