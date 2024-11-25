/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/25 15:15:27 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Utils.hpp"

class AForm;

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
		void signForm(Bureaucrat &bureaucrat, AForm &form);
		void executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low";
				}
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Form is not signed";
				}
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif