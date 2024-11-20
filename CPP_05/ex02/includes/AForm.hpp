/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/20 17:07:57 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

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
		~AForm();

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
		virtual void beSigned(Bureaucrat &Bureaucrat) = 0;
		virtual void execute(Bureaucrat const &executor) = 0;
		
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

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Form is not signed";
				}
		};
};

std::ostream &operator <<(std::ostream &oss, AForm const &form);

#endif