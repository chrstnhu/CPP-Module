/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/02 15:57:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

void testOutOfGrade();
void testForm();
void testInternForm();

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
	catch (const std::exception &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl;
	}

	// Test bureaucrat decrement ===========================================
	printColor("-- Test Bureaucrat decrement", ITALICYELLOW);
	Bureaucrat *bureaucrat3 = new Bureaucrat("Foo", 148);
	try {
		std::cout << *bureaucrat3 << std::endl;
		bureaucrat3->decrementGrade();
		std::cout << *bureaucrat3 << std::endl;
		bureaucrat3->decrementGrade();
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl;
	}
	delete bureaucrat3;

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
	catch (const std::exception &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl;
	}

	// Test less than grade 1 ====================================================
	printColor("-- Test Bureaucrat less than grade 1", ITALICYELLOW);
	try {
		Bureaucrat bureaucratLess("Less", -5);
		std::cout << bureaucratLess << std::endl;
		bureaucratLess.incrementGrade();
		std::cout << bureaucratLess << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl;
	}
}

void testForm () {
	srand(time(0));

	// Schrubbery Creation Form ================================================================
	separatorLine();
	printColor("=== TEST FORM === ", YELLOW);
	
	printColor("-- Test SchrubberyCreationForm", ITALICYELLOW);

	AForm *form1 = new SchrubberyCreationForm("Garden");
	try {
		Bureaucrat bob = Bureaucrat("Bob", 145); // Max (sign 145 | execute 137)
		std::cout << bob << std::endl;
		
		printColor("The form need to be signed and executed by the bureaucrat", ITALICYELLOW);
		form1->beSigned(bob);
		form1->execute(bob);
		
		printColor("Bureaucrat bob try to signform and executeForm", ITALICYELLOW);
		bob.signForm(bob, *form1);
		bob.executeForm(*form1);
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception caught in main : " << e.what() << DEF << std::endl;
	}


	// Robotomy Request Form================================================================
	separatorLine();
	printColor("-- Test RobotomyRequestForm", ITALICYELLOW);

	AForm *form2 = new RobotomyRequestForm("Deathlok");

	try {
		Bureaucrat Alice = Bureaucrat("Alice", 80);  // Max (sign 72 | execute 45)
		std::cout << Alice << std::endl;
		
		printColor("Alice try to sign and execute form1", ITALICYELLOW);
		Alice.signForm(Alice, *form1);
		Alice.executeForm(*form1);
		
		printColor("Alice try to sign and execute form2", ITALICYELLOW);
		Alice.signForm(Alice, *form2);
		Alice.executeForm(*form2);
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception caught in main : " << e.what() << DEF << std::endl;
	}


	// Presidential Pardon Form ================================================================
	separatorLine();
	printColor("-- Test PresidentialPardonForm", ITALICYELLOW);

	AForm *form3 = new PresidentialPardonForm("Ford Prefect");
	try {
		Bureaucrat bunny = Bureaucrat("Bunny", 25); // Max sign (25 | execute 5)
		std::cout << bunny << std::endl;
		
		printColor("Bunny try to execute form1", ITALICYELLOW);
		bunny.executeForm(*form3);

		printColor("Bunny try to sign and execute form1", ITALICYELLOW);
		bunny.signForm(bunny, *form3);
		bunny.executeForm(*form3);
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception caught in main : " << e.what() << DEF << std::endl;
	}

	delete form1;
	delete form2;
	delete form3;
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
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl;
	}
	
	delete form1;
	delete form2;
	delete form3;
}
