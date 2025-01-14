/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:41 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 12:33:08 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

// Default constructor
BitCoinExchange::BitCoinExchange() : _line("2009-01-02 | 0"), _date("2009-01-02"), _value("0") {
    // std::cout << "Constructor called" << std::endl;
    checkValidity();
}

// Constructor with parameter
BitCoinExchange::BitCoinExchange(std::string &line, std::string &date, std::string &value) 
    : _line(line), _date(date), _value(value) {
    // std::cout << "Constructor parameter called" << std::endl;
    checkValidity();
}

// Copy constructor
BitCoinExchange::BitCoinExchange(const BitCoinExchange &other) {
    // std::cout << "Copy constructor called" << std::endl;
    if (this != &other) {
        _date = other._date;
        _value = other._value;
    }
    checkValidity();
}

// Destructor
BitCoinExchange::~BitCoinExchange() {
    // std::cout << "Destructor called" << std::endl;
}

// Copy assignement
BitCoinExchange &BitCoinExchange::operator=(const BitCoinExchange &other) {
    // std::cout << "Copy assignement called" << std::endl;
    if (this != &other) {
        _date = other._date;
        _value = other._value;
    }
    checkValidity();
    return *this;
}