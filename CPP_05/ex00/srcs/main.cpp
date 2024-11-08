/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 17:05:20 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main () {
	Bureaucrat bureaucrat1 = Bureaucrat("Bureaucrat", 1);
	try {
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.incrementGrade();
		std::cout << bureaucrat1 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exception caught : " << RED << e.what() << DEF << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Exception caught : " << RED << e.what() << DEF << std::endl;
	}


	Bureaucrat *bureaucrat2 = new Bureaucrat("Bureaucrat", 148);
	try {
		std::cout << *bureaucrat2 << std::endl;
		bureaucrat2->decrementGrade();
		std::cout << *bureaucrat2 << std::endl;
		bureaucrat2->decrementGrade();
		std::cout << *bureaucrat2 << std::endl;
		bureaucrat2->decrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exception caught : " << RED << e.what() << DEF << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Exception caught : " << RED << e.what() << DEF << std::endl;
	}
	delete bureaucrat2;
}