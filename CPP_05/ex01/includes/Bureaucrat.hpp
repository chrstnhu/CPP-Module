/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/25 17:00:57 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		// Copy assignement operator
		Bureaucrat &operator=(Bureaucrat const &other);
		
		// Getters
		std::string getName() const;
		int			getGrade() const;

		// Functions
		void incrementGrade();
		void decrementGrade();
		void signForm(Bureaucrat &bureaucrat, Form &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high, can't exceed 1";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low, can't exceed 150";
				}
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif