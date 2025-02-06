/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:30:38 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/04 15:24:02 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RPN.hpp"

// Default constructor
RPN::RPN() {
    // std::cout << GREEN << "RNP default constructor called" << DEF << std::endl;
}

// Copy constructor
RPN::RPN(const RPN &other) {
    // std::cout << GREEN << "RNP copy constructor called" << DEF << std::endl;
    if (this != &other) {
        *this = other;
    }
}

// Destructor
RPN::~RPN() {
    // std::cout << GREEN << "RNP destructor called" << DEF << std::endl;
}

// Copy assignement
RPN &RPN::operator=(const RPN &other) {
    // std::cout << GREEN << "RNP copy assignement called" << DEF << std::endl;
    if (this != &other) {
        *this = other;
    }
    return *this;
}


// METHODS

// Check if the string is a valid RPN
void RPN::checkValidity(const std::string str) {
    int nbrOperand = 0;
    int nbrOperator = 0;
    
    for(size_t i = 0; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            nbrOperand++;
            continue;
        }
        else if (str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (str[i] != ' ') {
                nbrOperator++;
            }
            continue;
        }
        else {
            throw RPN::isInvalid();
        }
    }

    // Check if the number of operands and operators is correct
    if (nbrOperand < (nbrOperator + 1)) {
        throw RPN::notEnoughOperand();
    }
    else if (nbrOperand > (nbrOperator + 1)) {
        throw RPN::notEnoughOperator();
    }
}

// Check if the token is an operand
bool isOperand(char token) {
    return (token == '-' || token == '+' || token == '*' || token == '/');
}

// Calculate the result of the operation
double calculateResult(double nbr1, double nbr2, char token) {
    switch (token) {
        case '+':
            return nbr1 + nbr2;
        case '-':
            return nbr1 - nbr2;
        case '*':
            return nbr1 * nbr2;
        case '/':
            return nbr1 / nbr2;
    }
    return 0;
}

// Evaluation of the Reverse Polish Notation
double RPN::evalRPN(std::string str) {
    checkValidity(str);
    
    std::stack<double> stack;
    
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            continue;
        }
        else if (isdigit(str[i])) {
            stack.push(str[i] - '0');
        }
        else {
            if (stack.size() < 2) {
                throw RPN::invalidSize();
            }

            double nbr2 = stack.top();
            stack.pop();
            
            double nbr1 = stack.top();
            stack.pop();
            
            double result = calculateResult(nbr1, nbr2, str[i]);
            stack.push(result);
        }
    }
    double finalResult = stack.top();
    stack.pop();
    
    return finalResult;
}