/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 17:02:26 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Bureaucrat default constructor" << std::endl;
}

// Constructor with parameters
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade){
	std::cout << "Bureaucrat constructor with parameters" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor" << std::endl;
}

// Copy assignement operator
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	std::cout << "Bureaucrat copy assignement operator" << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}
		
// Getters
std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

// Functions

// Grade 1 is the highest one
void Bureaucrat::incrementGrade() {
	std::cout << "Original grade: " << YELLOW << this->_grade << DEF << std::endl;
	this->_grade--;
	if (this->_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << "After Increment: " << YELLOW << this->_grade << DEF << std::endl;
}

// Grade 150 is the lowest one
void Bureaucrat::decrementGrade() {
	std::cout << "Original grade: " << YELLOW << this->_grade << DEF << std::endl;
	this->_grade++;
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "After Decrement: " << YELLOW << this->_grade << DEF << std::endl;
}

std::ostream &operator<<(std::ostream &oss, Bureaucrat const &bureaucrat) {
    oss << GREEN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << DEF;
    return oss;
}
