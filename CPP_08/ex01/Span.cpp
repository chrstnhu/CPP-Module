/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:51:04 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 15:08:19 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() : _n(0), _vec() {
    std::cout << GREEN << "Span default constructor" << DEF << std::endl;
}

// Constructor with parameter
Span::Span(unsigned int n): _n(n), _vec() {
    std::cout << GREEN << "Span constructor with parameter" << DEF << std::endl;
}

// Copy constructor
Span::Span(Span const &other) {
    std::cout << GREEN << "Span copy constructor" << DEF << std::endl;
    if (this != &other) {
        _n = other._n;
        _vec = other._vec;
    }
}

// Destructor
Span::~Span() {
    std::cout << GREEN << "Span destructor" << DEF << std::endl;
}

// Copy assignment operator
Span &Span::operator=(Span const &other) {
    std::cout << GREEN << "Span copy assignemet constructor" << DEF << std::endl;
    if (this != &other) {
        _n = other._n;
        _vec = other._vec;
    }
    return *this;
}

// Getter
unsigned int Span::getN() const {
    return _n;
}

std::vector<int> Span::getVec() const {
    return _vec;
}


// METHODS

// Add number to vector
void Span::addNumber(int n) {
    if (_vec.size() >= _n) {
        throw std::invalid_argument("Vector is full");
    }
    _vec.push_back(n);
}

// Find the shortest span
unsigned int Span::shortestSpan() {
    if (_vec.size() <= 0) {
        throw std::invalid_argument("Vector is empty or has a negative size");
    }
    if (_vec.size() == 1) {
        throw std::invalid_argument("Vector has only one element");
    }
    
    std::sort(_vec.begin(), _vec.end());

    unsigned int shortest = -1;
    for (unsigned int i = 0; i < _vec.size() - 1; i++) {
        unsigned int diff = _vec[i + 1] - _vec[i];
        if (diff < shortest) {
            shortest = diff;
        }
    }

    return shortest;
}

// Find the longest span
unsigned int Span::longestSpan() {
    if (_vec.size() <= 0) {
        throw std::invalid_argument("Vector is empty or negative size");
    }
    if (_vec.size() == 1) {
        throw std::invalid_argument("Vector has only one element");
    }

    int smallest = _vec[0];
    int largest = _vec[0];
    for (unsigned int i = 0; i < _vec.size(); i++) {
        if (_vec[i] < smallest) {
            smallest = _vec[i];
        }
        if (_vec[i] > largest) {
            largest = _vec[i];
        }
    }
    return largest - smallest;
}

// Find the smallest number
int Span::findSmallestNumber() {
    int smallest = _vec[0];
    for (unsigned int i = 0; i < _vec.size(); i++) {
        if (_vec[i] < smallest) {
            smallest = _vec[i];
        }
    }
    return smallest;
}

// Find the biggest number
int Span::findBiggestNumber() {
    int biggest = _vec[0];
    for (unsigned int i = 0; i < _vec.size(); i++) {
        if (_vec[i] > biggest) {
            biggest = _vec[i];
        }
    }
    return biggest;
}