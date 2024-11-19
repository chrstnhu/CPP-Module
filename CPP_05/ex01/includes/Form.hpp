/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/19 14:19:04 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _signed;
		const int _grade;
		const int _executeGrade;
	
	public :
		Form();
		Form(std::string const name, int grade, int executeGrade);
		Form(Form const &other);
		~Form();

		// Copy assignement operator
		Form &operator=(Form const &other);

		// Getter
		std::string const getName() const;
		bool getSigned() const;
		int getGrade() const;
		int getExecuteGrade() const;

		// Functions
		void beSigned(Bureaucrat &Bureaucrat);
		
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