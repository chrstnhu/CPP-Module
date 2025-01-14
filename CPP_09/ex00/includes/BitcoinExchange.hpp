/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:39 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 17:11:21 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <ctime>
# include <sstream>
# include <cmath>
# include <map>
# include <algorithm>

# include "Colors.hpp"

class BitCoinExchange {
    protected :
        // std::map <std::string, double> _startline;
        std::string _line;
        std::string _date;
        std::string _value;
        std::string _closestKey;
        double _closestValue;
        
    public :
        std::map <std::string, double> _startline;
    
        BitCoinExchange();
        BitCoinExchange(std::string &line, std::string &date, std::string &value);
        BitCoinExchange(const BitCoinExchange &other);
        ~BitCoinExchange();

        // Copy assignement
        BitCoinExchange &operator=(const BitCoinExchange &other);

        // Functions
        void checkValidity();
        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value);
        bool isPositifValue(const std::string &value);

        std::string getClosestKey();
        
        void setClosestKey(std::string key);
};

class DataExchange {
    // protected :
        // std::map <std::string, double> _data;
        // std::string _date;
        // std::string _value;
        // std::string _closestKey;
    
    public :
        std::map <std::string, double> _data;

        DataExchange();
        DataExchange(std::string &line, std::string &date, std::string &value);
        DataExchange(const DataExchange &other);
        ~DataExchange();

        // Copy assignement
        DataExchange &operator=(const DataExchange &other);

        // Setter
        // std::string getClosestKey();
        // void setClosestKey(std::string key);
        // void setClosestValue(double value);
};

# endif