/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/19 16:52:58 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _signed;
		const int _grade;
		const int _executeGrade;
	
	public :
		AForm();
		AForm(std::string const name, int grade, int executeGrade);
		AForm(Form const &other);
		~AForm();

		// Copy assignement operator
		AForm &operator=(Form const &other);

		// Getter
		std::string const getName() const;
		bool getSigned() const;
		int getGrade() const;
		int getExecuteGrade() const;

		// Functions
		virtual void beSigned(Bureaucrat &Bureaucrat) = 0;
		
		class GradeTooHightException : public std::exception {
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

std::ostream &operator <<(std::ostream &oss, Form const &form);

#endif