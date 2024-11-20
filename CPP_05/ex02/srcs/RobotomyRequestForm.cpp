/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:47:41 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/20 16:42:39 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45, "default_target") {
	std::cout << GREEN << "RobotomyRequestForm default constructor" << DEF << std::endl;
}

// Constructor with parameters
RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
	: AForm("Robotomy Request", 72, 45, target) {
	std::cout << GREEN << getName() 
		<< ", RobotomyRequestForm constructor with parameters" << DEF << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other){
	std::cout << GREEN << getName() 
		<< ", RobotomyRequestForm copy constructor" << DEF << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << GREEN << getName()
		<< ", RobotomyRequestForm Destructor" << DEF << std::endl;
}

// Copy assignement operator
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	std::cout << GREEN << getName()
		<< ", RobotomyRequestForm copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}


// Functions
void RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToExecute()) {
		this->setSigned(true);
	}
	else {
		throw GradeTooLowException();
	}
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	std::cout << "Drilling noises : Vrrrrrrrrr..." << std::endl;
	if (!this->getSigned()) {
		throw FormNotSignedException();
	}
	if (this->getGradeToExecute() < executor.getGrade()) {
		throw GradeTooLowException();
	}

	int value = rand() % 2;
	if (value == 0) {
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	}
	else {
		std::cout << this->getTarget() << "failed to be robotomized" << std::endl;
	}
}
