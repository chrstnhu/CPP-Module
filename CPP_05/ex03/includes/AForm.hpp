/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/05 16:22:09 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Utils.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		std::string const _target;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	
	public :
		AForm();
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(std::string const name, int gradeToSign, int gradeToExecute, std::string const target);
		AForm(AForm const &other);
		virtual ~AForm();

		// Copy assignement operator
		AForm &operator=(AForm const &other);

		// Getter and setters
		std::string const getName() const;
		std::string const getTarget() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void setSigned(bool isSigned);

		// Functions
		void beSigned(Bureaucrat &Bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void performAction() const = 0;
		
		class GradeTooHightException : public std::exception {
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

std::ostream &operator <<(std::ostream &oss, AForm const &form);

#endif