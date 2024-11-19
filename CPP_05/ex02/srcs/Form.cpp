/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/19 16:28:17 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

// Default constructor
Form::Form() : _name("default"), _signed(false),  _grade(150), _executeGrade(150) {
	std::cout << GREEN << "Form default constructor" << DEF << std::endl;
	if (this->_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Constructor with parameters
Form::Form(std::string const name, int grade, int executeGrade) :
	_name(name), _signed(false), _grade(grade), _executeGrade(executeGrade) {
	std::cout << GREEN << name 
		<< ", Form constructor with parameters"
		<< " | Grade: " << grade 
		<< " | Execute grade: " << executeGrade << DEF << std::endl;
	if (this->_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Copy constructor
Form::Form(Form const &other) : 
	_name(other._name), _signed(other._signed), 
	_grade(other._grade), _executeGrade(other._executeGrade) {
	std::cout << GREEN << _name 
		<< ", Form copy constructor" << DEF << std::endl;
}

// Destructor
Form::~Form() {
	std::cout << GREEN << _name
		<< ", Form Destructor" << DEF << std::endl;
}

// Copy assignement operator
Form &Form::operator=(Form const &other) {
	std::cout << GREEN << _name
		<< ", Form copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}


// Getters
std::string const Form::getName() const {
	return this->_name;	
}

bool Form::getSigned() const {
	return this->_signed;
}

int Form::getGrade() const {
	return this->_grade;
}

int Form::getExecuteGrade() const {
	return this->_executeGrade;
}


// Functions
void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_grade) {
		this->_signed = true;
	}
}


// Overload << operator
std::ostream &operator<<(std::ostream &oss, Form const &form) {
	oss << "Form: " << form.getName () <<
		" | Signed: " << form.getSigned() <<
		" | Grade: " << form.getGrade() <<
		" | Execute grade: " << form.getExecuteGrade();
	return oss;
}