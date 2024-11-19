/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/19 18:03:26 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SchrubberyCreationForm.hpp"

// Default constructor
SchrubberyCreationForm::SchrubberyCreationForm() : Form(), _name("default"), _signed(false),  _grade(150), _executeGrade(150) {
	std::cout << GREEN << "SchrubberyCreationForm default constructor" << DEF << std::endl;
}

// Constructor with parameters
SchrubberyCreationForm::SchrubberyCreationForm(std::string const name, int grade, int executeGrade) :
	Form(name, grade, executeGrade), _name(name), _signed(false),  _grade(grade), _executeGrade(executeGrade) {
	std::cout << GREEN << name 
		<< ", SchrubberyCreationForm constructor with parameters"
		<< " | Grade: " << grade 
		<< " | Execute grade: " << executeGrade << DEF << std::endl;
	
}

// Copy constructor
SchrubberyCreationForm::SchrubberyCreationForm(SchrubberyCreationForm const &other) : 
	_name(other._name), _signed(other._signed), 
	_grade(other._grade), _executeGrade(other._executeGrade) {
	std::cout << GREEN << _name 
		<< ", SchrubberyCreationForm copy constructor" << DEF << std::endl;
}

// Destructor
SchrubberyCreationForm::~SchrubberyCreationForm() {
	std::cout << GREEN << _name
		<< ", SchrubberyCreationForm Destructor" << DEF << std::endl;
}

// Copy assignement operator
SchrubberyCreationForm &SchrubberyCreationForm::operator=(SchrubberyCreationForm const &other) {
	std::cout << GREEN << _name
		<< ", SchrubberyCreationForm copy assignement operator" << DEF << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}


// Functions
void SchrubberyCreationForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_grade) {
		this->_signed = true;
	}
}


// Overload << operator
std::ostream &operator<<(std::ostream &oss, SchrubberyCreationForm const &SchrubberyCreationForm) {
	oss << "SchrubberyCreationForm: " << SchrubberyCreationForm.getName () <<
		" | Signed: " << SchrubberyCreationForm.getSigned() <<
		" | Grade: " << SchrubberyCreationForm.getGrade() <<
		" | Execute grade: " << SchrubberyCreationForm.getExecuteGrade();
	return oss;
}