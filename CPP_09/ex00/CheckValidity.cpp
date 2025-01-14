/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckValidity.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:41 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 12:37:01 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

// Check the validity of the date and value
void BitCoinExchange::checkValidity() {
    if (_date.empty() || _value.empty()) {
        throw std::invalid_argument("Error: Empty date or value");
    }
    if (_line.find("|") == std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + _line);
    }
    if (!isValidDate(_date)) {
        throw std::invalid_argument("Error: bad date => " + _date);
    }
    if (!isValidValue(_value)) {
        throw std::invalid_argument("Error: too large a number.");
    }
    if (!isPositifValue(_value)) {
        throw std::out_of_range("Error: not a positive number.");
    }
}


// Check if is leap year
static bool isLeapYear(int year) {
    bool divibleBy4 = year % 4 == 0;

    bool divibleBy100 = year % 100 == 0;

    bool divibleBy400 = year % 400 == 0;

    if (divibleBy4) {
        if (divibleBy100) {
            if (divibleBy400) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

// Check if the date is valid
bool BitCoinExchange::isValidDate(const std::string &date) {
    int year, month, day;

    std::stringstream ss(date);
    
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-' ||
        month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day > 31) {
                return false;
            }
            break;
        
        case 4: case 6: case 9: case 11:
            if (day > 30) {
                return false;
            }
            break;
    
        case 2:
            if (!isLeapYear(year)) {
                return false;
            }
            break;
    }
    return true;
}

// Check if the value is valid
bool BitCoinExchange::isValidValue(const std::string &value) {
    std::stringstream ss(value);
    double val;
    ss >> val;
    if (ss.fail() || val > 1000) {
        return false;
    }
    return true;
}

// Check if the value is positive
bool BitCoinExchange::isPositifValue(const std::string &value) {
    std::stringstream ss(value);
    double val;
    ss >> val;
    if (ss.fail() || val < 0) {
        return false;
    }
    return true;
}