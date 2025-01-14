/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:39 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 12:31:44 by chrhu            ###   ########.fr       */
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

# include "Colors.hpp"

class BitCoinExchange {
    protected :
        std::string _line;
        std::string _date;
        std::string _value;
        
    public :
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
};
        
# endif