/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:30:38 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/16 17:57:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RPN.hpp"

// Default constructor
RPN::RPN() {
    std::cout << GREEN << "RNP default constructor called" << DEF << std::endl;
}

// Copy constructor
RPN::RPN(const RPN &other) {
    std::cout << GREEN << "RNP copy constructor called" << DEF << std::endl;
    if (this != &other) {
        *this = other;
    }
}

// Destructor
RPN::~RPN() {
    std::cout << GREEN << "RNP destructor called" << DEF << std::endl;
}

// Copy assignement
RPN &RPN::operator=(const RPN &other) {
    std::cout << GREEN << "RNP copy assignement called" << DEF << std::endl;
    if (this != &other) {
        *this = other;
    }
    return *this;
}

// Functions
void RPN::checkValidity(const std::string str) {
    
    for(size_t i = 0; i < str.size(); ++i) {
        if (isdigit(str[i]) && !isdigit(str[i + 1])) {
            continue;
        }
        else if (str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            continue;
        }
        else {
            throw std::invalid_argument("Error");
        }
    }
}

bool isOperand(char token) {
    return (token == '-' || token == '+' || token == '*' || token == '/');
}

int calculateResult(int nbr1, int nbr2, char token) {
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

int RPN::evalRPN(std::string str) {
    checkValidity(str);
    
    std::stack<int> stack;
    
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            continue;
        }
        else if (isdigit(str[i])) {
            stack.push(str[i] - '0');
        }
        else {
            int nbr2 = stack.top();
            stack.pop();
            
            int nbr1 = stack.top();
            stack.pop();
            
            int result = calculateResult(nbr1, nbr2, str[i]);
            stack.push(result);
        }
    }
    int finalResult = stack.top();
    stack.pop();
    
    return finalResult;
}