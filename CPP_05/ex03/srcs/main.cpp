/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 14:09:52 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

void testOutOfGrade();
void testForm();
void testInternForm();

int main () {
	printColor("=== TEST BUREAUCRAT ===", YELLOW);

	Bureaucrat bureaucrat1 = Bureaucrat("Bob", 3);
	try {
		std::cout << bureaucrat1 << std::endl;
		for (int i = 0; i < 3; i++) {
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
	separatorLine();
	printColor("=== TEST OUT OF GRADE ===", YELLOW);
	
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
	
	separatorLine();
	printColor("=== TEST FORM === ", YELLOW);
	
	printColor("-- Test SchrubberyCreationForm", ITALICYELLOW);
	SchrubberyCreationForm SchrubberyForm("Target1");
	Bureaucrat bob = Bureaucrat("Bob", 146); // Max (sign 145 | execute 137)
	std::cout << SchrubberyForm << std::endl
			<< bob << std::endl;	
	bob.signForm(bob, SchrubberyForm);
    bob.executeForm(SchrubberyForm);

	printColor("-- Test RobotomyRequestForm", ITALICYELLOW);
	RobotomyRequestForm RobotomyForm("Target2");
	Bureaucrat Alice("Alice", 80);  // Max (sign 72 | execute 45)
	std::cout << RobotomyForm << std::endl
			<< Alice << std::endl;
	Alice.signForm(Alice, RobotomyForm);
	Alice.executeForm(RobotomyForm);
	
	printColor("-- Test PresidentialPardonForm", ITALICYELLOW);
	PresidentialPardonForm PresidentialForm("Target3"); 
	Bureaucrat bunny = Bureaucrat("Bunny", 25); // Max sign (25 | execute 5)
	std::cout << PresidentialForm << std::endl
			<< bunny << std::endl;
	bunny.signForm(bunny, PresidentialForm);
	bunny.executeForm(PresidentialForm);
}

void testInternForm() {
	separatorLine();
	printColor("== TEST INTERN FORM ==", YELLOW);

	// Subject test
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	delete rrf;
	
	// My test
	Intern intern;
	AForm *form1 = intern.makeForm("schrubbery creation", "Target1");
	AForm *form2 = intern.makeForm("robotomy", "Target2");
	AForm *form3 = intern.makeForm("presidential pardon", "Target3");

	// Test the forms with bureaucrat
	Bureaucrat bureaucrat("Bureaucrat", 25);
	try {
		printColor("-- Try to sign and execute form1 ", ITALICYELLOW);
		if (!form1) {
			throw std::exception();
		}
		bureaucrat.signForm(bureaucrat, *form1);
		bureaucrat.executeForm(*form1);
		printColor("-- Try to sign and execute form3", ITALICYELLOW);
		if (!form3) {
			throw std::exception();
		}
		bureaucrat.signForm(bureaucrat, *form3);
		bureaucrat.executeForm(*form3);
		printColor("-- Try to sign and execute form2", ITALICYELLOW);
		if (!form2) {
			throw std::exception();
		}
		bureaucrat.signForm(bureaucrat, *form2);
		bureaucrat.executeForm(*form2);
		

	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception caught in testInternForm" << DEF << std::endl;
	}
	
	delete form1;
	delete form2;
	delete form3;
}
