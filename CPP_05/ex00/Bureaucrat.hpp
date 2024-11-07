/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/07 15:24:59 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
		void GradeTooHighException();
		void GradeTooLowException();
}

#endif