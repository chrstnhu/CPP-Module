/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/25 17:21:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Utils.hpp"

class Form;

class Intern {
	protected :
		std::string _formName;
		std::string _formTarget;
	public :
		Intern();
		Intern(std::string const &formName, std::string const &formTarget);
		Intern(AForm const &other);
		~Intern();

		// Copy assignement operator
		Intern &operator=(Intern const &other);

		// Functions
		AForm* makeForm(std::string const &formName, std::string const &formTarget);
};

#endif