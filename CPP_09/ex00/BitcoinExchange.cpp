/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:41 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 19:59:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

// Default constructor
BitCoinExchange::BitCoinExchange() : _line("2009-01-02 | 0"), _date("2009-01-02"), _value("0") {
    // std::cout << "BitCoinExchange Constructor called" << std::endl;
    
    std::stringstream ss(_value);
    double value1;
    ss >> value1;
    _startline[_date] = value1;
    
    checkValidity();
}

// Constructor with parameter
BitCoinExchange::BitCoinExchange(std::string &line, std::string &date, std::string &value) 
    : _line(line), _date(date), _value(value) {
    // std::cout << "BitCoinExchange Constructor parameter called" << std::endl;

    std::stringstream ss(_value);
    double value1;
    ss >> value1;
    _startline[_date] = value1;
    
    checkValidity();
}

// Copy constructor
BitCoinExchange::BitCoinExchange(const BitCoinExchange &other) {
    // std::cout << "BitCoinExchange Copy constructor called" << std::endl;
    if (this != &other) {
        _date = other._date;
        _value = other._value;
        
        std::stringstream ss(_value);
        double value;
        ss >> value;
        _startline[_date] = value;
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
        _date = other._date;
        _value = other._value;
        
        std::stringstream ss(_value);
        double value;
        ss >> value;
        _startline[_date] = value;
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


void BitCoinExchange::setClosestValue(double value) {
    _closestValue = value;
}


double BitCoinExchange::getClosestValue() {
    return _closestValue;
}
