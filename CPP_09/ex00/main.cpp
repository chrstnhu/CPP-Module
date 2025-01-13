/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:23:04 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/13 20:04:20 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

// Check if is leap year
bool isLeapYear(int year) {
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
bool isValidDate(const std::string &date) {
    int year, month, day;

    std::stringstream ss(date);
    
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-') {
        return false;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31) {
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

bool isValidValue(const std::string &value) {
    std::stringstream ss(value);
    double val;
    ss >> val;
    if (ss.fail()) {
        return false;
    }
    if (val > 1000) {
        return false;
    }
    return true;
}

bool isPositifValue(const std::string &value) {
    std::stringstream ss(value);
    double val;
    ss >> val;
    if (ss.fail()) {
        return false;
    }
    if (val < 0) {
        return false;
    }
    return true;
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << RED << "USAGE : ./btc [file] " << DEF << std::endl;
    }

    std::fstream input;
    input.open(av[1], std::ios::in);
    
    // Check if the file is open
    if (!input.is_open()) {
        std::cout << RED << "Error: File not found" << DEF << std::endl;
        return 1;
    }
    // Read the file
    std::string line;
    while (std::getline(input, line)) {
        if (line.empty()) {
            std::cout << RED << "Error: Empty file" << DEF << std::endl;
            break ;
        }
        if (line.find("|") == std::string::npos) {
            std::cout << RED << "Error: bad input => " << line << DEF << std::endl;
        }
        else if (!isValidDate(line.substr(0, line.find("|")))) {
            std::cout << RED << "Error: bad date => " << line.substr(0, line.find("|")) << DEF << std::endl;
        }
        else if (!isPositifValue(line.substr(line.find("|") + 2))) {
            std::cout << RED << "Error: not a positive number." << DEF << std::endl;
        }
        else if (!isValidValue(line.substr(line.find("|") + 2))) {
            std::cout << RED << "Error: too large a number." << DEF << std::endl;
        }
        else {
            std::cout << line << std::endl;
        }
    }
    
    
    // Open the file Bitcoin
    std::fstream file;
    file.open("data.csv", std::ios::in);
    
    // Check if the file is open
    if (!file.is_open()) {
        std::cout << RED << "Error: File not found" << DEF << std::endl;
        return 1;
    }
    return 0;
}