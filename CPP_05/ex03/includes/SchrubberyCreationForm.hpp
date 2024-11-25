/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/25 15:15:34 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Utils.hpp"

class Bureaucrat;

class SchrubberyCreationForm : public AForm {
	public :
		SchrubberyCreationForm();
		SchrubberyCreationForm(std::string const target);
		SchrubberyCreationForm(SchrubberyCreationForm const &other);
		virtual ~SchrubberyCreationForm();

		// Copy assignement operator
		SchrubberyCreationForm &operator=(SchrubberyCreationForm const &other);

		// Functions
		virtual void execute(Bureaucrat const &executor) const;
};

#endif