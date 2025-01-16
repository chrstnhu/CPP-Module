/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:51:04 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/16 16:20:05 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() : _N(0), _vec(), _currentVec(0), _nextVec(0), 
    _biggestNumber(std::numeric_limits<int>::max()), _smallestNumber(std::numeric_limits<int>::min()) {
    std::cout << GREEN << "Span default constructor" << DEF << std::endl;
}

// Constructor with parameter
Span::Span(unsigned int n): _N(n), _vec(), _currentVec(0), _nextVec(0), 
    _biggestNumber(std::numeric_limits<int>::max()), _smallestNumber(std::numeric_limits<int>::min()) {
    std::cout << GREEN << "Span constructor with parameter" << DEF << std::endl;
}

// Copy constructor
Span::Span(Span const &other) {
    std::cout << GREEN << "Span copy constructor" << DEF << std::endl;
    if (this != &other) {
        _N = other._N;
        _vec = other._vec;
        _currentVec = other._currentVec;
        _nextVec = other._nextVec;
        _biggestNumber = other._biggestNumber;
        _smallestNumber = other._smallestNumber;
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
        _N = other._N;
        _vec = other._vec;
        _currentVec = other._currentVec;
        _nextVec = other._nextVec;
        _biggestNumber = other._biggestNumber;
        _smallestNumber = other._smallestNumber;
    }
    return *this;
}

// Getter
unsigned int Span::getN() const {
    return _N;
}

std::vector<int> Span::getVec() const {
    return _vec;
}

int Span::getCurrentVec() const {
    return _currentVec;
}

int Span::getNextVec() const {
    return _nextVec;
}

int Span::getSmallestNumber() {
    return _smallestNumber;
}

int Span::getBiggestNumber() {
    return _biggestNumber;
}


// METHODS

// Add number to vector
void Span::addNumber(int n) {
    if (_vec.size() >= _N) {
        throw std::invalid_argument("Vector is full");
    }
    _vec.push_back(n);
}

// Add number to vector with insert
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_vec.size() + std::distance(begin, end) > _N) {
        throw std::invalid_argument("Vector is full");
    }
    _vec.insert(_vec.end(), begin, end);
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
            _currentVec = _vec[i];
            _nextVec = _vec[i + 1];
        }
    }
    
    return (shortest);
}

// Find the longest span
unsigned int Span::longestSpan() {
    if (_vec.size() <= 0) {
        throw std::invalid_argument("Vector is empty or negative size");
    }
    if (_vec.size() == 1) {
        throw std::invalid_argument("Vector has only one element");
    }

    std::sort(_vec.begin(), _vec.end());
    
    _biggestNumber = _vec[_vec.size() - 1];
    _smallestNumber = _vec[0];
    
    return (_biggestNumber - _smallestNumber);
}

// Print vector
void Span::printVector() const{
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << ", ";
    }
    std::cout << std::endl;
}