/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/28 13:45:48 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

void testOutOfGrade();
void testForm();

int main () {
	printColor("=== TEST BUREAUCRAT ===", YELLOW);

	// Test bureaucrat increment ===========================================
	printColor("-- Test Bureaucrat increment", ITALICYELLOW);
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

	// Test bureaucrat decrement ===========================================
	printColor("-- Test Bureaucrat decrement", ITALICYELLOW);
	Bureaucrat *bureaucrat2 = new Bureaucrat("Foo", 148);
	try {
		std::cout << *bureaucrat2 << std::endl;
		bureaucrat2->decrementGrade();
		std::cout << *bureaucrat2 << std::endl;
		bureaucrat2->decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << "High : " << e.what() << DEF << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << "Low : " << e.what() << DEF << std::endl << std::endl;
	}
	delete bureaucrat2;

	testOutOfGrade();
	testForm();
}

void testOutOfGrade() {
	separatorLine();
	printColor("=== TEST OUT OF GRADE ===", YELLOW);


	// Test more than grade 150 ====================================================
	printColor("-- Test Bureaucrat more than grade 150", ITALICYELLOW);
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

	// Test less than grade 1 ====================================================
	printColor("-- Test Bureaucrat less than grade 1", ITALICYELLOW);
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

void testForm () {
	separatorLine();
	printColor("=== TEST FORM === ", YELLOW);
	
	// Test Form 1 in grade ========================================================
	printColor("-- Test Form 1", ITALICYELLOW);
	try {
		Form form1 = Form("Form1", 5, 10);
		Bureaucrat bureaucrat1 = Bureaucrat("Bob", 4);

		std::cout << form1 << std::endl;
		std::cout << bureaucrat1 << std::endl;	
		form1.beSigned(bureaucrat1);
		bureaucrat1.signForm(bureaucrat1, form1);
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl << std::endl;
	}

	// Test Form 2 out of grade ========================================================
	printColor("-- Test Form 2", ITALICYELLOW);
	try {
		Form form2 = Form("Form2", 155, 10);
		Bureaucrat bureaucrat2 = Bureaucrat("Alice", 10);

		std::cout << form2 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		form2.beSigned(bureaucrat2);
		bureaucrat2.signForm(bureaucrat2, form2);
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl;
	}
}