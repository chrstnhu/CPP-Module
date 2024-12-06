/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/06 14:42:39 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Utils.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	
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
		int getGradeToSign() const;
		int getGradeToExecute() const;

		// Functions
		void beSigned(Bureaucrat &Bureaucrat);
		
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
};

std::ostream &operator <<(std::ostream &oss, Form const &form);

#endif