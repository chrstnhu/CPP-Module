/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:23:04 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/04 13:43:22 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include "../includes/Data.hpp"

// Compare key of the two maps
void keyCompare(BitCoinExchange &btc, Data &data) {
    std::map<std::string, float> line = btc.getLineToExchange();
    std::map<std::string, float>::const_iterator itLine = line.begin();

    // Iterate over the input file and compare line to the data
    for (; itLine != line.end(); ++itLine) {

        std::string lineKey = itLine->first;
        std::map<std::string, float>::const_iterator itData = data.getData().find(lineKey);

        if (itData != data.getData().end()) {
            btc.setClosestKey(itData->first);
            btc.setClosestValue(itData->second);
        } 
        else {
            std::map<std::string, float>::const_iterator closestDataKey = data.getData().lower_bound(lineKey);
            
            if (closestDataKey != data.getData().begin()) {
                --closestDataKey;
                btc.setClosestKey(closestDataKey->first);
                btc.setClosestValue(closestDataKey->second);
            } 
            else {
                throw std::invalid_argument("Error: no match found or earlier date available => " + lineKey);
            }
        }
    }
}

// Process the input file
void processInputFile(std::fstream &input, Data &data) {
    std::string line;
    
    std::getline(input, line);
    // Check if the file is empty
    if (line.empty()) {
        throw std::invalid_argument("Error: empty file");
    }
    
    // Check the validity of the line and calcul the value
    while (std::getline(input, line)) {
        if (line.empty() || line.compare("date | value") == 0) {
            continue;
        }

        try {
            std::string date = line.substr(0, line.find("|") - 1);
            std::string strValue = line.substr(line.find("|") + 2);
            if (strValue.empty()) {
                throw std::invalid_argument("Error: empty value => " + line);
            }
            std::stringstream ss(strValue);
            float value;
            ss >> value;
            
            // Create the line to compare with data
            BitCoinExchange btc(line, date, value);
            
            keyCompare(btc, data);

            // std::cout << YELLOW << "value: " << value2 << 
                    // ", bitcoin exchange: " << btc.getClosestValue() <<
                    // " from the closest date: " << btc.getClosestKey() << DEF << std::endl;
            std::cout << date << " => " << value << " = " << value * btc.getClosestValue() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << RED << e.what() << DEF << std::endl;
        }
    }
}


int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << RED << "USAGE : ./btc [input_file.txt] " << DEF << std::endl;
        return 0;
    }

    try {
        // Open the input file
        std::fstream input;
        input.open(av[1], std::ios::in);
        
        if (!input.is_open()) {
            throw std::invalid_argument("Error: file not found");
        }
        
        // Load the data from the file
        Data data("data.csv");

        processInputFile(input, data);
        
        input.close();
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << DEF << std::endl;
    }
    
    return 0;
}