/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 12:06:20 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

// Default constructor
Intern::Intern() : _form(NULL), _formName("default_form"), _formTarget("default_target") {
	std::cout << ITALICGREEN << "Intern default constructor" << DEF << std::endl;
}

// Constructor with parameters
Intern::Intern(std::string const &formName, std::string const &formTarget)
	: _form(NULL), _formName(formName), _formTarget(formTarget) {
	std::cout << ITALICGREEN << "Intern constructor with parameters" << DEF << std::endl;
}

// Copy constructor
Intern::Intern(Intern const &other) {
	std::cout << ITALICGREEN << "Intern copy constructor" << DEF << std::endl;
	_form = other._form;
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
		_form = other._form;
		_formName = other._formName;
		_formTarget = other._formTarget;
	}
	return *this;
}

FormType getFormName(std::string FormName) {
	if (FormName == "Schrubbery")
		return SCHRUBBERY;
	if (FormName == "Robotomy")
		return ROBOTOMY;
	if (FormName == "Presidential")
		return PRESIDENTIAL;
	return UNKNOWN;
}

// Functions 
AForm* Intern::makeForm(std::string const &formName, std::string const &formTarget) {
	if (formName.empty() || formTarget.empty()) {
		std::cout << ITALICRED << "Error: formName or formTarget is empty" << DEF << std::endl;
		return NULL;
	}
	
	FormType formType = getFormName(formName);
	switch (formType) {
		case SCHRUBBERY:
			std::cout << "Intern creates " << formName << DEF << std::endl;
			return new SchrubberyCreationForm(formTarget);
		case ROBOTOMY:
			std::cout << "Intern creates " << formName << DEF << std::endl;
			return new RobotomyRequestForm(formTarget);
		case PRESIDENTIAL:
			std::cout << "Intern creates " << formName << DEF << std::endl;
			return new PresidentialPardonForm(formTarget);
		case UNKNOWN:
			std::cout << ITALICRED << "Error: unknown form name" << DEF << std::endl;
			return NULL;
	}
}