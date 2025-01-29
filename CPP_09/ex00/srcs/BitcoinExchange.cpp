/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:41 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/29 15:35:31 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

// Default constructor
BitCoinExchange::BitCoinExchange() 
    : _line("2009-01-02 | 0"), _dateKey("2009-01-02"), _value(-1) {
    // std::cout << "BitCoinExchange Constructor called" << std::endl;
    
    _lineToExchange["2009-01-02"] = 0;
    
    checkValidity();
}

// Constructor with parameter
BitCoinExchange::BitCoinExchange(std::string &line, std::string &date, float &value) 
    : _line(line), _dateKey(date), _value(value) {
    // std::cout << "BitCoinExchange Constructor parameter called" << std::endl;

    _lineToExchange[_dateKey] = value;
    
    checkValidity();
}

// Copy constructor
BitCoinExchange::BitCoinExchange(const BitCoinExchange &other) {
    // std::cout << "BitCoinExchange Copy constructor called" << std::endl;
    if (this != &other) {
        _line = other._line;
        _dateKey = other._dateKey;
        _value = other._value;

        _lineToExchange[_dateKey] = _value;
    }
    
    checkValidity();
}

// Destructor
BitCoinExchange::~BitCoinExchange() {
    // std::cout << "BitCoinExchange Destructor called" << std::endl;
}

// Copy assignement
BitCoinExchange &BitCoinExchange::operator=(const BitCoinExchange &other) {
    // std::cout << "BitCoinExchange Copy assignement called" << std::endl;
    if (this != &other) {
        _line = other._line;
        _dateKey = other._dateKey;
        _value = other._value;

        _lineToExchange[_dateKey] = _value;
    }
    
    checkValidity();
    return *this;
}


void BitCoinExchange::setClosestKey(std::string key) {
    _closestKey = key;
}


std::string BitCoinExchange::getClosestKey() {
    return _closestKey;
}


void BitCoinExchange::setClosestValue(float value) {
    _closestValue = value;
}


float BitCoinExchange::getClosestValue() {
    return _closestValue;
}


// Getter 
const std::map<std::string, float> &BitCoinExchange::getLineToExchange() const {
    return _lineToExchange;
}
