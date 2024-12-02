/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/02 13:58:13 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

// Default constructor
AForm::AForm() : _name("default"), _target("default_target"), _isSigned(false),  _gradeToSign(150), _gradeToExecute(150) {
	std::cout << ITALICGREEN << "Form default constructor" << DEF << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Constructor with parameters
AForm::AForm(std::string const name, int grade, int gradeToExecute) :
	_name(name), _target("target"), _isSigned(false), _gradeToSign(grade), _gradeToExecute(gradeToExecute) {
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Form constructor with parameters"
		<< " | Grade: " << grade 
		<< " | Execute grade: " << gradeToExecute << DEF << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

AForm::AForm(std::string const name, int grade, int gradeToExecute, std::string const target) :
	_name(name), _target(target), _isSigned(false), _gradeToSign(grade), _gradeToExecute(gradeToExecute) {
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Form constructor with parameters"
		<< " | Grade: " << grade 
		<< " | Execute grade: " << gradeToExecute << DEF << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Copy constructor
AForm::AForm(AForm const &other) :
	_name(other._name), _target(other._target), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Form copy constructor" << DEF << std::endl;
}

// Destructor
AForm::~AForm() {
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Form Destructor" << DEF << std::endl;
}

// Copy assignement operator
AForm &AForm::operator=(AForm const &other) {
	std::cout << ITALICGREEN << _name
		<< ", Form copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}


// Getters and setters
std::string const AForm::getName() const {
	return this->_name;	
}

std::string const AForm::getTarget() const {
	return this->_target;	
}

bool AForm::getSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::setSigned(bool isSigned) {
	this->_isSigned = isSigned;
}

// Functions

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}


// Overload << operator
std::ostream &operator<<(std::ostream &oss, AForm const &form) {
	oss << "Form: " << form.getName () <<
		" | Signed: " << form.getSigned() <<
		" | Grade: " << form.getGradeToSign() <<
		" | Execute grade: " << form.getGradeToExecute();
	return oss;
}