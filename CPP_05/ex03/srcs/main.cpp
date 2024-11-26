/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 12:06:41 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

void testOutOfGrade();
void testForm();
void testInternForm();

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

	testOutOfGrade();
	testForm();
	testInternForm();
}

void testOutOfGrade() {
	std::cout << std::endl << YELLOW
		<< "=== Test out of grade ===" << DEF << std::endl;
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
}

void testForm () {
	srand(time(0));
	
	std::cout << std::endl << YELLOW
		<< "=== Test Form ===" << DEF << std::endl;
	
	std::cout << std::endl << YELLOW << "SchrubberyCreationForm" << DEF << std::endl;
	
	SchrubberyCreationForm SchrubberyForm("Target1");
	Bureaucrat bob = Bureaucrat("Bob", 146); // Max (sign 145 | execute 137)
	std::cout << SchrubberyForm << std::endl
			<< bob << std::endl;	
	bob.signForm(bob, SchrubberyForm);
    bob.executeForm(SchrubberyForm);

	std::cout << std::endl << YELLOW << "RobotomyRequestForm" << DEF << std::endl;

	RobotomyRequestForm RobotomyForm("Target2");
	Bureaucrat Alice = Bureaucrat("Alice", 80);  // Max (sign 72 | execute 45)
	std::cout << RobotomyForm << std::endl
			<< Alice << std::endl;
	Alice.signForm(Alice, RobotomyForm);
	Alice.executeForm(RobotomyForm);
	Alice.executeForm(RobotomyForm);
	
	
	std::cout << std::endl << YELLOW << "PresidentialPardonForm" << DEF << std::endl;

	PresidentialPardonForm PresidentialForm("Target3"); 
	Bureaucrat bunny = Bureaucrat("Bunny", 25); // Max sign (25 | execute 5)
	std::cout << PresidentialForm << std::endl
			<< bunny << std::endl;
	bunny.signForm(bunny, PresidentialForm);
	bunny.executeForm(PresidentialForm);
}

void testInternForm() {
	std::cout << std::endl << YELLOW
		<< "=== Test Intern ===" << DEF << std::endl;

	Intern intern;

	AForm *form1 = intern.makeForm("Schrubbery", "Target1");
	AForm *form2 = intern.makeForm("Robotomy", "Target2");
	AForm *form3 = intern.makeForm("Presidential", "Target3");

	std::cout << &form1 << std::endl
			<< &form2 << std::endl
			<< &form3 << std::endl;

	delete form1;
	delete form2;
	delete form3;
}