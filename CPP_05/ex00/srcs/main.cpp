/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/11 17:59:27 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void testOutOfGrade();

int main () {
	std::cout << YELLOW << "=== Test Bureaucrat ===" << DEF << std::endl;
	Bureaucrat bureaucrat1 = Bureaucrat("Bob", 5);
	try {
		std::cout << bureaucrat1 << std::endl;
		for (int i = 0; i < 5; i++) {
			bureaucrat1.incrementGrade();
			std::cout << bureaucrat1 << std::endl;
		}
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}

	Bureaucrat *bureaucrat3 = new Bureaucrat("Foo", 148);
	try {
		std::cout << *bureaucrat3 << std::endl;
		bureaucrat3->decrementGrade();
		std::cout << *bureaucrat3 << std::endl;
		bureaucrat3->decrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	delete bureaucrat3;

	testOutOfGrade();
}

void testOutOfGrade() {
	std::cout << std::endl
		<< YELLOW << "=== Test out of grade ===" << DEF << std::endl;
	try {
		Bureaucrat bureaucratMore("More", 200);
		std::cout << bureaucratMore << std::endl;
		bureaucratMore.incrementGrade();
		std::cout << bureaucratMore << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}

	try {
		Bureaucrat bureaucratLess("Less", -5);
		std::cout << bureaucratLess << std::endl;
		bureaucratLess.incrementGrade();
		std::cout << bureaucratLess << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
}