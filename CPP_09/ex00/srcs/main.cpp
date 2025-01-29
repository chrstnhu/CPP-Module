/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:23:04 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/29 15:36:31 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include "../includes/Data.hpp"

void keyCompare(BitCoinExchange &btc, Data &data) {
    std::map<std::string, float>::const_iterator itStart = btc.getLineToExchange().begin();

    for (; itStart != btc.getLineToExchange().end(); ++itStart) {

        std::string startline_date = itStart->first;
        std::map<std::string, float>::const_iterator itData = data.getData().find(startline_date);

        if (itData != data.getData().end()) {
            btc.setClosestKey(itStart->first);
            btc.setClosestValue(itData->second);
        } 
        else {
            std::map<std::string, float>::const_iterator closest = data.getData().lower_bound(startline_date);
            if (closest != data.getData().begin()) {
                --closest;
                if (btc.getClosestKey() != closest->first) {
                    btc.setClosestKey(closest->first);
                    btc.setClosestValue(closest->second);
                }
            } 
            else {
                throw std::invalid_argument("Error: no match found or earlier date available => " + startline_date);
            }
        }
    }
}

void processInputFile(std::fstream &input, Data &data) {
    std::string line;
    
    while (std::getline(input, line)) {
        if (line.empty()) {
            std::cout << "Error: empty file" << std::endl;
            break;
        }
        if (line.compare("date | value") == 0) {
            continue;
        }
        
        try {
            std::string date = line.substr(0, line.find("|") - 1);
            std::string value = line.substr(line.find("|") + 2);
            if (value.empty()) {
                throw std::invalid_argument("Error: empty value => " + line);
            }
            std::stringstream ss(value);
            float value2;
            ss >> value2;
            
            BitCoinExchange btc(line, date, value2);
            
            keyCompare(btc, data);

            // std::cout << YELLOW << "value: " << value2 << 
                    // ", bitcoin exchange: " << btc.getClosestValue() <<
                    // " from the closest date: " << btc.getClosestKey() << DEF << std::endl;
            std::cout << date << " => " << value2 << " = " << value2 * btc.getClosestValue() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << RED << e.what() << DEF << std::endl;
        }
    }
}


int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << RED << "USAGE : ./btc [file] " << DEF << std::endl;
    }

    try {
        std::fstream input;
        input.open(av[1], std::ios::in);
        
        if (!input.is_open()) {
            throw std::invalid_argument("Error: file not found");
        }
        
        Data data("data.csv");

        processInputFile(input, data);
        
        input.close();
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << DEF << std::endl;
    }
    
    return 0;
}