/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 14:08:31 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

// Default constructor
Intern::Intern() : _formName("default_form"), _formTarget("default_target") {
	std::cout << ITALICGREEN << "Intern default constructor" << DEF << std::endl;
}

// Constructor with parameters
Intern::Intern(std::string const &formName, std::string const &formTarget)
	: _formName(formName), _formTarget(formTarget) {
	std::cout << ITALICGREEN << "Intern constructor with parameters" << DEF << std::endl;
}

// Copy constructor
Intern::Intern(Intern const &other) {
	std::cout << ITALICGREEN << "Intern copy constructor" << DEF << std::endl;
	_formName = other._formName;
	_formTarget = other._formTarget;
}

// Destructor
Intern::~Intern() {
	std::cout << ITALICGREEN << "Intern Destructor" << DEF << std::endl;
}

// Copy assignement operator
Intern &Intern::operator=(Intern const &other) {
	std::cout << ITALICGREEN << "Intern copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		_formName = other._formName;
		_formTarget = other._formTarget;
	}
	return *this;
}


// Create form functions
AForm* Intern::createShrubberyForm(std::string const &formTarget) {
	return new SchrubberyCreationForm(formTarget);
}

AForm* Intern::createRobotomyForm(std::string const &formTarget) {
	return new RobotomyRequestForm(formTarget);
}

AForm* Intern::createPresidentialForm(std::string const &formTarget) {
	return new PresidentialPardonForm(formTarget);
}

// Function
AForm* Intern::makeForm(std::string const &formName, std::string const &formTarget) {
	if (formName.empty() || formTarget.empty()) {
		std::cout << RED << "Error: formName or formTarget is empty" << DEF << std::endl;
		return NULL;
	}

	const std::string name[4] = {"schrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*actions[3])(std::string const&) ={
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};
	
	for (int i = 0; i < 3; i++) {
		if (formName == name[i]) {
			std::cout << "Intern creates " << formName << DEF << std::endl;
			return (this->*actions[i])(formTarget);
		}
	}
	
	std::cout << RED << "Error: formName is not valid" << DEF << std::endl;
	return (NULL);
}