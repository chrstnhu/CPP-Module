/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 13:57:03 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

// Default constructor
SchrubberyCreationForm::SchrubberyCreationForm() : AForm("Schrubbery Creation", 145, 137, "default_target") {
	std::cout << ITALICGREEN << "SchrubberyCreationForm default constructor" << DEF << std::endl;
}

// Constructor with parameters
SchrubberyCreationForm::SchrubberyCreationForm(const std::string target)
	: AForm("Schrubbery Creation", 145, 137, target) {
	std::cout << ITALICGREEN << "'" << getName() << "'"
		<< ", SchrubberyCreationForm constructor with parameters" << DEF << std::endl;
}

// Copy constructor
SchrubberyCreationForm::SchrubberyCreationForm(SchrubberyCreationForm const &other) : AForm(other) {
	std::cout << ITALICGREEN << "'" << getName() << "'"
		<< ", SchrubberyCreationForm copy constructor" << DEF << std::endl;
}

// Destructor
SchrubberyCreationForm::~SchrubberyCreationForm() {
	std::cout << ITALICGREEN << "'" << getName() << "'" 
		<< ", SchrubberyCreationForm Destructor" << DEF << std::endl;
}

// Copy assignement operator
SchrubberyCreationForm &SchrubberyCreationForm::operator=(SchrubberyCreationForm const &other) {
	std::cout << ITALICGREEN << "'" << getName() << "'" 
		<< ", SchrubberyCreationForm copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

// Functions

// Create a file <target>_shrubbery and writes ASCII trees inside it
void SchrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::string fileName = this->getTarget() + "_shrubbery";

	if (!this->getSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::ofstream file;
	
	file.open(fileName.c_str(), std::ios::out);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	
	std::cout << BOLDGREEN << "Created file: " << fileName << std::endl;
	
	file << GREEN << "      ccee88oo" << std::endl
	<< "  C8O8O8Q8PoOb o8oo" << std::endl
	<< " dOB69QO8PdUOpugoO9bD" << std::endl
	<< "CgggbU8OU qOp qOdoUOdcb" << std::endl
	<< "    6OuU  " << BROWN << "/" << GREEN << "p u gcoUodpP" << std::endl
	<< BROWN << "      \\//  /"<< GREEN << "douUP" << std::endl
	<< BROWN << "        \\\\\\////" << std::endl
	<< "         |||/\\ " << std::endl
	<< "         |||\\/ " << std::endl
	<< "         ||||| " << std::endl
	<< GREEN << "   ....." << BROWN << "//||||\\" << GREEN << "..... " << DEF << std::endl;
	file.close();

	std::cout << "Go watch the beautiful ASCII tree art in "
		<< fileName << DEF << std::endl << std::endl;
}

