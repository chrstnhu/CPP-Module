/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/19 17:15:37 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class Bureaucrat;

class SchrubberyCreationForm : public Form {
	private:
		std::string const _name;
		int _signed;
		const int _grade;
		const int _executeGrade;
	
	public :
		SchrubberyCreationForm();
		SchrubberyCreationForm(std::string const name, int grade, int executeGrade);
		SchrubberyCreationForm(SchrubberyCreationForm const &other);
		virtual ~SchrubberyCreationForm();

		// Copy assignement operator
		SchrubberyCreationForm &operator=(SchrubberyCreationForm const &other);

		// Functions
		virtual void beSigned(Bureaucrat &Bureaucrat);
};

std::ostream &operator <<(std::ostream &oss, Form const &form);

#endif