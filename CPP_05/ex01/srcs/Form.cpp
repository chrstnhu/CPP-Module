/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/05 15:38:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// Default constructor
Form::Form() : _name("default"), _isSigned(false),  _gradeToSign(150), _gradeToExecute(150) {
	std::cout << ITALICGREEN << "Form default constructor" << DEF << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Constructor with parameters
Form::Form(std::string const name, int grade, int executeGrade) :
	_name(name), _isSigned(false), _gradeToSign(grade), _gradeToExecute(executeGrade) {
	std::cout << ITALICGREEN << name 
		<< ", Form constructor with parameters"
		<< " | Grade: " << grade 
		<< " | Execute grade: " << executeGrade << DEF << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Copy constructor
Form::Form(Form const &other) : 
	_name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << ITALICGREEN << _name 
		<< ", Form copy constructor" << DEF << std::endl;
}

// Destructor
Form::~Form() {
	std::cout << ITALICGREEN << _name
		<< ", Form Destructor" << DEF << std::endl;
}

// Copy assignement operator
Form &Form::operator=(Form const &other) {
	std::cout << ITALICGREEN << _name
		<< ", Form copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}


// Getters
std::string const Form::getName() const {
	return this->_name;	
}

bool Form::getSigned() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}


// Functions
void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}


// Overload << operator
std::ostream &operator<<(std::ostream &oss, Form const &form) {
	oss << "Form: " << form.getName () <<
		" | Signed: " << form.getSigned() <<
		" | Grade: " << form.getGradeToSign() <<
		" | Execute grade: " << form.getGradeToExecute();
	return oss;
}