/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/20 17:09:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SchrubberyCreationForm.hpp"

// Default constructor
SchrubberyCreationForm::SchrubberyCreationForm() : AForm("Schrubbery Creation", 145, 137, "default_target") {
	std::cout << GREEN << "SchrubberyCreationForm default constructor" << DEF << std::endl;
}

// Constructor with parameters
SchrubberyCreationForm::SchrubberyCreationForm(const std::string target)
	: AForm("Schrubbery Creation", 145, 137, target) {
	std::cout << GREEN << getName() 
		<< ", SchrubberyCreationForm constructor with parameters" << DEF << std::endl;
}

// Copy constructor
SchrubberyCreationForm::SchrubberyCreationForm(SchrubberyCreationForm const &other) : AForm(other) {
	std::cout << GREEN << getName() 
		<< ", SchrubberyCreationForm copy constructor" << DEF << std::endl;
}

// Destructor
SchrubberyCreationForm::~SchrubberyCreationForm() {
	std::cout << GREEN << getName()
		<< ", SchrubberyCreationForm Destructor" << DEF << std::endl;
}

// Copy assignement operator
SchrubberyCreationForm &SchrubberyCreationForm::operator=(SchrubberyCreationForm const &other) {
	std::cout << GREEN << getName()
		<< ", SchrubberyCreationForm copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}


// Functions
void SchrubberyCreationForm::beSigned(Bureaucrat &bureaucrat) {
	std::cout << "Bureaucrat " << bureaucrat.getGrade() << std::endl << std::endl;
	std::cout << "Current grade" << this->getGradeToSign() << std::endl << std::endl;
	if (bureaucrat.getGrade() <= this->getGradeToSign()) {
		this->setSigned(true);
	}
	else {
		throw GradeTooLowException();
	}
}

// Create a file <target>_shrubbery and writes ASCII trees inside it
void SchrubberyCreationForm::execute(Bureaucrat const &executor) {
	std::string fileName = this->getTarget() + "_shrubbery";

	if (!this->getSigned()) {
		throw FormNotSignedException();
	}
	if (this->getGradeToExecute() < executor.getGrade()) {
		throw GradeTooLowException();
	}

	std::ofstream file;
	
	file.open(fileName.c_str(), std::ios::out);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	
	file << "      ccee88oo" << std::endl
	<< "  C8O8O8Q8PoOb o8oo" << std::endl
	<< " dOB69QO8PdUOpugoO9bD" << std::endl
	<< "CgggbU8OU qOp qOdoUOdcb" << std::endl
	<< "    6OuU  /p u gcoUodpP" << std::endl
	<< "      \\//  /douUP" << std::endl
	<< "        \\\\\\////" << std::endl
	<< "         |||/\\ " << std::endl
	<< "         |||\\/ " << std::endl
	<< "         ||||| " << std::endl
	<< "   .....//||||\\..... " << std::endl;
	file.close();
}

