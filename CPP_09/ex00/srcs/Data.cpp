/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:58:56 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/04 13:43:04 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Data.hpp"

// Default constructor
Data::Data() {
    // std::cout << "Data Constructor called" << std::endl;
    loadDataFromFile("data.csv");
}

// Constructor with parameter
Data::Data(std::string filename) {
    // std::cout << "Data Constructor with parameter called" << std::endl;
    loadDataFromFile(filename.c_str());
}

// Copy constructor
Data::Data(const Data &other) {
    // std::cout << "Data Copy constructor called" << std::endl;
    if (this != &other) {
        _data = other._data;
    }
}

// Destructor
Data::~Data() {
    // std::cout << "Data Destructor called" << std::endl;
}

// Copy assignement
Data &Data::operator=(const Data &other) {
    // std::cout << "Data Copy assignement called" << std::endl;
    if (this != &other) {   
        _data = other._data;
    }
    return *this;
}


// Getter 
const std::map<std::string, float> &Data::getData() const {
    return _data;
}


// METHODS

// Load data from file
void Data::loadDataFromFile(std::string filename) {
    std::fstream file;
    file.open(filename.c_str(), std::ios::in);
    
    // Check if the file is open
    if (!file.is_open()) {
        throw std::invalid_argument("Error: data file not found");
    }
    
    // Save key and value in map<key,value> data
    std::string line_data;
    
    while (std::getline(file, line_data)) {
        
        if (line_data == "date,exchange_rate") {
            continue;
        }
        
        std::string date_data = line_data.substr(0, line_data.find(","));
        std::string value_data = line_data.substr(line_data.find(",") + 1);

        std::stringstream ss(value_data);
        float value1;
        ss >> value1;
        
        _data[date_data] = value1;
    }
}