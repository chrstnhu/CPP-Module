/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:32 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 14:59:22 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

void testOutOfGrade();
void testForm();

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

	try {
		Bureaucrat bureaucratMore("More", 200);
		std::cout << bureaucratMore << std::endl;
		bureaucratMore.incrementGrade();
		std::cout << bureaucratMore << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception : " << e.what() << DEF << std::endl;
	}

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

	separatorLine();
	printColor("=== TEST FORM === ", YELLOW);
	
	printColor("-- Test SchrubberyCreationForm", ITALICYELLOW);
	SchrubberyCreationForm SchrubberyForm("Target1");
	Bureaucrat bob = Bureaucrat("Bob", 146); // Max (sign 145 | execute 137)
	std::cout << SchrubberyForm << std::endl
			<< bob << std::endl;	
	bob.signForm(bob, SchrubberyForm);
    bob.executeForm(SchrubberyForm);

	Bureaucrat bureaucrat1 = Bureaucrat("Bureaucrat1", 130); // Max (sign 145 | execute 137)
	std::cout << SchrubberyForm << std::endl
			<< bureaucrat1 << std::endl;	
	bureaucrat1.signForm(bureaucrat1, SchrubberyForm);
    bureaucrat1.executeForm(SchrubberyForm);

	separatorLine();
	printColor("-- Test RobotomyRequestForm", ITALICYELLOW);
	RobotomyRequestForm RobotomyForm("Target2");
	Bureaucrat Alice = Bureaucrat("Alice", 80);  // Max (sign 72 | execute 45)
	std::cout << RobotomyForm << std::endl
			<< Alice << std::endl;
	Alice.signForm(Alice, RobotomyForm);
	Alice.executeForm(RobotomyForm);
	Alice.executeForm(RobotomyForm);

	Bureaucrat bureaucrat2 = Bureaucrat("Bureaucrat2", 30);  // Max (sign 72 | execute 45)
	std::cout << RobotomyForm << std::endl
			<< bureaucrat2 << std::endl;
	bureaucrat2.signForm(bureaucrat2, RobotomyForm);
	bureaucrat2.executeForm(RobotomyForm);
	bureaucrat2.executeForm(RobotomyForm);
	
	separatorLine();
	printColor("-- Test PresidentialPardonForm", ITALICYELLOW);
	PresidentialPardonForm PresidentialForm("Target3"); 
	Bureaucrat bunny = Bureaucrat("Bunny", 25); // Max sign (25 | execute 5)
	std::cout << PresidentialForm << std::endl
			<< bunny << std::endl;
	bunny.signForm(bunny, PresidentialForm);
	bunny.executeForm(PresidentialForm);

	Bureaucrat bureaucrat3 = Bureaucrat("Bureaucrat3", 1); // Max sign (25 | execute 5)
	std::cout << PresidentialForm << std::endl
			<< bureaucrat3 << std::endl;
	bureaucrat3.signForm(bureaucrat3, PresidentialForm);
	bureaucrat3.executeForm(PresidentialForm);
}