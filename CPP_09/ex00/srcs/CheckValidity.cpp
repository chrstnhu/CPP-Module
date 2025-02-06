/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckValidity.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:41 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/04 13:42:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

// Check the validity of the date and value
void BitCoinExchange::checkValidity() {
    if (_dateKey.empty()) {
        throw BitCoinExchange::emptyDate();
    }
    if (_line.find("|") == std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + _line);
    }
    if (!isValidDate(_dateKey)) {
        throw std::invalid_argument("Error: bad date => " + _dateKey);
    }
    if (!isValidValue(_value)) {
        throw BitCoinExchange::numberTooLarge();
    }
    if (!isPositifValue(_value)) {
        throw BitCoinExchange::notAPositifNumber();
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
        case 4: case 6: case 9: case 11:
            if (day > 30) {
                return false;
            }
            break;
    
        case 2:
            if (isLeapYear(year)) {
                if (day > 29) {
                    return false;
                }
            }
            else {
                if (day > 28) {
                    return false;
                }
            }
            break;
    }
    return true;
}

// Check if the value is valid (less than 1000)
bool BitCoinExchange::isValidValue(const float &value) {
    if (value > 1000) {
        return false;
    }
    return true;
}

// Check if the value is positive (more than 0)
bool BitCoinExchange::isPositifValue(const float &value) {
    if (value < 0) {
        return false;
    }
    return true;
}