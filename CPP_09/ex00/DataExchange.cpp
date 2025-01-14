/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataExchange.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:58:56 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 16:27:22 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/BitcoinExchange.hpp"

/*
// Default constructor
DataExchange::DataExchange() : _line("2009-01-02 | 0"), _date("2009-01-02"), _value("0"), _closestKey("") {
    // std::cout << "DataExchange Constructor called" << std::endl;
    
    std::stringstream ss(_value);
    double value1;
    ss >> value1;
    _data[_date] = value1;
    
}

// Constructor with parameter
DataExchange::DataExchange(std::string &line, std::string &date, std::string &value) 
    : _line(line), _date(date), _value(value), _closestKey("") {
    // std::cout << "DataExchange Constructor parameter called" << std::endl;

    std::stringstream ss(_value);
    double value1;
    ss >> value1;
    _data[_date] = value1;
    
}

// Copy constructor
DataExchange::DataExchange(const DataExchange &other) {
    // std::cout << "DataExchange Copy constructor called" << std::endl;
    if (this != &other) {
        _date = other._date;
        _value = other._value;
        
        std::stringstream ss(_value);
        double value;
        ss >> value;
        _data[_date] = value;
    }
}

// Destructor
DataExchange::~DataExchange() {
    // std::cout << "DataExchange Destructor called" << std::endl;
}

// Copy assignement
DataExchange &DataExchange::operator=(const DataExchange &other) {
    // std::cout << "DataExchange Copy assignement called" << std::endl;
    if (this != &other) {
        _date = other._date;
        _value = other._value;
        
        std::stringstream ss(_value);
        double value;
        ss >> value;
        _data[_date] = value;
    }
    return *this;
}

// Setter 
void DataExchange::setClosestKey(std::string key) {
    _closestKey = key;    
}

std::string DataExchange::getClosestKey() {
    return _closestKey;
}

*/

// Default constructor
DataExchange::DataExchange(){
    // std::cout << "DataExchange Constructor called" << std::endl;
    
}

// Copy constructor
DataExchange::DataExchange(const DataExchange &other) {
    // std::cout << "DataExchange Copy constructor called" << std::endl;
    if (this != &other) {
    }
}

// Destructor
DataExchange::~DataExchange() {
    // std::cout << "DataExchange Destructor called" << std::endl;
}

// Copy assignement
DataExchange &DataExchange::operator=(const DataExchange &other) {
    // std::cout << "DataExchange Copy assignement called" << std::endl;
    if (this != &other) {        
    }
    return *this;
}

