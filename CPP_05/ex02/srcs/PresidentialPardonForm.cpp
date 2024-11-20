/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:57 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/20 16:42:35 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5, "default_target") {
	std::cout << GREEN << "PresidentialPardonForm default constructor" << DEF << std::endl;
}

// Constructor with parameters
PresidentialPardonForm::PresidentialPardonForm( std::string const target)
	: AForm("Presidential Pardon", 25, 5, target) {
	std::cout << GREEN << getName() 
		<< ", PresidentialPardonForm constructor with parameters" << DEF << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other){
	std::cout << GREEN << getName() 
		<< ", PresidentialPardonForm copy constructor" << DEF << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << GREEN << getName()
		<< ", PresidentialPardonForm Destructor" << DEF << std::endl;
}

// Copy assignement operator
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	std::cout << GREEN << getName()
		<< ", PresidentialPardonForm copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}


// Functions
void PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToExecute()) {
		this->setSigned(true);
	}
	else {
		throw GradeTooLowException();
	}
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned()) {
		throw FormNotSignedException();
	}
	if (this->getGradeToExecute() < executor.getGrade()) {
		throw GradeTooLowException();
	}
	std::cout << this->getTarget()
		<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
