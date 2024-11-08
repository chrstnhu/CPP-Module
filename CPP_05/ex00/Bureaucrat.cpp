/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/07 17:36:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150) {
		std::cout << "Bureaucrat default constructor" << std::endl;
}

// Constructor with parameters
Bureaucrat::Bureaucrat(std::string const name, int grade)
	: _name(name), _grade(grade){
		std::cout << "Bureaucrat constructor with parameters" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

// Destructor
Bureaucrat::Bureaucrat() {
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
	if (this->_grade == 1) {
		Bureaucrat::GradeTooHighException();
	}
	else
		this->_grade--;
}

// Grade 150 is the lowest one
void Bureaucrat::decrementGrade() {
	if (this->_grade == 150) {
		Bureaucrat::GradeTooLowException();
	}
	else
		this->_grade++;
}

void Bureaucrat::GradeTooHighException() {
	std::cout << "Grade is too high, can't exceed 1" << std::endl;
}

void Bureaucrat::GradeTooLowException() {
	std::cout << "Grade is too low, can't down 150" << std::endl;
}
