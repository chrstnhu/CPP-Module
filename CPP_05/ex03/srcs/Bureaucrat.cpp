/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/05 15:46:08 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Utils.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Bureaucrat default constructor" << DEF << std::endl;
	if (this->_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Constructor with parameters
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade){
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Bureaucrat constructor with parameters" 
		<< " | Grade: " << grade << DEF << std::endl;
	if (this->_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Bureaucrat copy constructor" << DEF << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Bureaucrat Destructor" << DEF << std::endl;
}

// Copy assignement operator
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	std::cout << ITALICGREEN << "'" << _name << "'"
		<< ", Bureaucrat copy assignement operator" << DEF << std::endl;
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
	std::cout << "Original grade: " << YELLOW << this->_grade << DEF;
	this->_grade--;
	if (this->_grade < 1) {
		std::cout << std::endl;
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << " | After Increment++: " << YELLOW << this->_grade << DEF << std::endl;
}

// Grade 150 is the lowest one
void Bureaucrat::decrementGrade() {
	std::cout << "Original grade: " << YELLOW << this->_grade << DEF;
	this->_grade++;
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << " | After Decrement--: " << YELLOW << this->_grade << DEF << std::endl;
}

void Bureaucrat::signForm(Bureaucrat &bureaucrat, AForm &form) {
	try {
        form.beSigned(bureaucrat); 
    	std::cout << UNDERDEF << "-> " 
                << bureaucrat.getName() << " signed "
                << form.getName() << DEF << std::endl << std::endl;
    }
    catch (const std::exception &e) {
		std::cout << UNDERRED << "-> "
				<< bureaucrat.getName() << " couldn't sign " 
				<< form.getName() << " because " << e.what() << DEF << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch (const std::exception &e) {
		std::cout << RED << "Exception caught in executeForm: "
			<< e.what() << DEF << std::endl << std::endl;
	}
}

// Overload << operator
std::ostream &operator<<(std::ostream &oss, Bureaucrat const &bureaucrat) {
    oss << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade();
    return oss;
}
