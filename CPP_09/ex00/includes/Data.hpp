/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:39 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/15 11:54:01 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include "BitcoinExchange.hpp"

class Data {
    private :
        std::map <std::string, float> _data;
    
    public :
        
        Data();
        Data(std::string filename);
        Data(std::string &line, std::string &date, std::string &value);
        Data(const Data &other);
        ~Data();

        // Copy assignement
        Data &operator=(const Data &other);
        
        // Getter
        const std::map<std::string, float> &getData() const;

        // Function
        void loadDataFromFile(std::string filename);
};

#endif