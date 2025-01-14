/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:23:04 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 12:43:33 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

void 

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
    std::string date;
    std::string value;
    
    while (std::getline(input, line)) {
        if (line.empty()) {
            std::cout << "Error: Empty file" << std::endl;
            break;
        }
        if (line.compare("date | value") == 0) {
            continue;
        }
        
        try {
            date = line.substr(0, line.find("|"));
            value = line.substr(line.find("|") + 2);
            BitCoinExchange btc(line, date, value);

            std::cout << line << std::endl;
        }
        catch (std::exception &e) {
            std::cout << RED << e.what() << DEF << std::endl;
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