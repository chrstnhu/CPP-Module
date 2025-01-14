/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:23:04 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 20:02:49 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

void keyCompare(BitCoinExchange &btc, DataExchange &data) {
    std::map<std::string, double>::iterator itStart = btc._startline.begin();

    for (; itStart != btc._startline.end(); ++itStart) {

        std::string startline_date = itStart->first;
        std::map<std::string, double>::iterator itData = data._data.find(startline_date);

        if (itData != data._data.end()) {
            std::cout << "Exact match for " << startline_date << ": " << itData->second << std::endl;
            
            btc.setClosestKey(itStart->first);
            btc.setClosestValue(itData->second);
        } else {

            std::map<std::string, double>::iterator closest = data._data.lower_bound(startline_date);
            if (closest != data._data.begin()) {
                --closest;
                std::cout << "No exact match for " << startline_date << " . Using closest earlier date: "
                          << closest->first << " => " << closest->second << std::endl;

                if (btc.getClosestKey() != closest->first) {
                    btc.setClosestKey(closest->first);
                    btc.setClosestValue(closest->second);
                }
            } else {
                throw std::invalid_argument("Error: No match found or earlier date available => " + startline_date);
            }
        }
    }
}



int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << RED << "USAGE : ./btc [file] " << DEF << std::endl;
    }

    // ============ READ INPUT FILE ============
    std::fstream input;
    input.open(av[1], std::ios::in);
    
    // Check if the file is open
    if (!input.is_open()) {
        std::cout << RED << "Error: File not found" << DEF << std::endl;
        return 1;
    }
    
    // ============ READ DATA FILE ============
    std::fstream file;
    file.open("data.csv", std::ios::in);
            
    // Check if the file is open
    if (!file.is_open()) {
        std::cout << RED << "Error: File not found" << DEF << std::endl;
        return 1;
    }
     
    // ============= SAVE DATA FILE ============
    std::string line_data;
       
    DataExchange data;
    while (std::getline(file, line_data)) {
        if (line_data == "date,exchange_rate") {
            continue;
        }
        std::string date_data = line_data.substr(0, line_data.find(","));
        std::string value_data = line_data.substr(line_data.find(",") + 1);
        std::stringstream ss(value_data);
        double value1;
        ss >> value1;
        data._data[date_data] = value1;
        // std::cout << "Data: " << date_data << std::endl;
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
            date = line.substr(0, line.find("|") - 1);
            value = line.substr(line.find("|") + 2);
            BitCoinExchange btc(line, date, value);
            
            std::stringstream ss(value);
            double value2;
            ss >> value2;
            
            keyCompare(btc, data);

            std::cout << YELLOW << "value: " << value2 << 
                    ", taux exchange: " << btc.getClosestValue() <<
                    " de date: " << btc.getClosestKey() << DEF << std::endl;
            std::cout << date << " => " << value2 << " = " << value2 * btc.getClosestValue() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << RED << e.what() << DEF << std::endl;
        }
    }
    file.close();
    input.close();
    
    return 0;
}