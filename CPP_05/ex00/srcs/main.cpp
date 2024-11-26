/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 14:58:39 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void printColor(const std::string &msg, const std::string &color);
void separatorLine();
void testOutOfGrade();

int main () {
	printColor("=== TEST BUREAUCRAT ===", YELLOW);

	Bureaucrat bureaucrat1 = Bureaucrat("Bob", 5);
	try {
		std::cout << bureaucrat1 << std::endl;
		for (int i = 0; i < 5; i++) {
			bureaucrat1.incrementGrade();
			std::cout << bureaucrat1 << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "High : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Low : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl;
	}

	Bureaucrat *bureaucrat3 = new Bureaucrat("Foo", 148);
	try {
		std::cout << *bureaucrat3 << std::endl;
		bureaucrat3->decrementGrade();
		std::cout << *bureaucrat3 << std::endl;
		bureaucrat3->decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "High : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Low : " << e.what() << DEF << std::endl << std::endl;
	}

	delete bureaucrat3;

	testOutOfGrade();
}

void testOutOfGrade() {
	separatorLine();
	printColor("=== TEST OUT OF GRADE ===", YELLOW);

	try {
		Bureaucrat bureaucratMore("More", 200);
		std::cout << bureaucratMore << std::endl;
		bureaucratMore.incrementGrade();
		std::cout << bureaucratMore << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "High : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Low : " << e.what() << DEF << std::endl << std::endl;
	}

	try {
		Bureaucrat bureaucratLess("Less", -5);
		std::cout << bureaucratLess << std::endl;
		bureaucratLess.incrementGrade();
		std::cout << bureaucratLess << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "High : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Low : " << e.what() << DEF << std::endl << std::endl;
	}
}

void printColor(const std::string &msg, const std::string &color) {
    std::cout << std::endl << color << msg << DEF << std::endl;
}

void separatorLine() {
	std::cout << std::endl << "==============================================================================================" << std::endl;
}