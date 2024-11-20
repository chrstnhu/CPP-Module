/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/20 17:00:16 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/SchrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

void testOutOfGrade();
void testForm();

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
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}

	Bureaucrat *bureaucrat3 = new Bureaucrat("Foo", 148);
	try {
		std::cout << *bureaucrat3 << std::endl;
		bureaucrat3->decrementGrade();
		std::cout << *bureaucrat3 << std::endl;
		bureaucrat3->decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	delete bureaucrat3;

	testOutOfGrade();
	testForm();
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
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}

	try {
		Bureaucrat bureaucratLess("Less", -5);
		std::cout << bureaucratLess << std::endl;
		bureaucratLess.incrementGrade();
		std::cout << bureaucratLess << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}
}

void testForm () {
	std::cout << std::endl
		<< YELLOW << "=== Test Form ===" << DEF << std::endl;
	
	SchrubberyCreationForm form1("target1");
	Bureaucrat bureaucrat1 = Bureaucrat("Bob", 146);

	std::cout << form1 << std::endl;
	std::cout << bureaucrat1 << std::endl;	
	form1.beSigned(bureaucrat1);
	bureaucrat1.signedForm(bureaucrat1, form1);

	// Bureaucrat bureaucrat2 = Bureaucrat("Alice", 10);
	// RobotomyRequestForm form2("target2");

	// std::cout << form2 << std::endl;
	// std::cout << bureaucrat2 << std::endl;
	// form2.beSigned(bureaucrat2);
	// bureaucrat2.signedForm(bureaucrat2, form2);
}