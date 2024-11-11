/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/11 19:16:25 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

// Default constructor
Form::Form() : _name("default"), _signed(false),  _grade(150), _executeGrade(150) {
	std::cout << GREEN << "Form default constructor" << DEF << std::endl;
}

// Constructor with parameters
Form::Form(std::string const name, int grade, int executeGrade) :
	_name(name), _signed(false), _grade(grade), _executeGrade(executeGrade) {
	std::cout << GREEN << name 
		<< ", Form constructor with parameters" << DEF
		<< " | Grade: " << grade 
		<< " | Execute grade: " << executeGrade << std::endl;
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