/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/25 17:24:41 by chrhu            ###   ########.fr       */
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
		__always_inline = other._formTarget;
	}
	return *this;
}

// Functions 
AForm* Intern::makeForm(std::string const &formName, std::string const &formTarget) {
	// To be modified
	if (formName.empty() || formTarget.empty()) {
		std::cout << ITALICRED << "Error: formName or formTarget is empty" << DEF << std::endl;
		return NULL;
	}
	std::cout << ITALICGREEN << "Intern creates" << formName << DEF << std::endl;
	return // to be modified
}