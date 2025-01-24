/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:58 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/24 16:34:09 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Default constructor
PMergeMe::PMergeMe(): _pairsDeque(), _maxima(), _minima() {
    // std::cout << ITALICGREEN "PMergeMe default constructor called" DEF << std::endl;
}

// Copy constructor
PMergeMe::PMergeMe(PMergeMe const &other) {
    // std::cout << ITALICGREEN "PMergeMe Copy Constructor called" DEF << std::endl;
    if (this != &other) {
        _pairsDeque = other._pairsDeque;
        _maxima = other._maxima;
        _minima = other._minima;
    }
}

PMergeMe::PMergeMe(int ac, char **av) {
    // std::cout << ITALICGREEN "PMergeMe Constructor with parameter called" DEF << std::endl;
    for (int i = 0; i < ac; i++) {
        char* end;
        if (std::strtol(av[i], &end, 10) < 0) {
            throw std::invalid_argument("Error: negative number or not a number");
        }
    }
}

// Destructor
PMergeMe::~PMergeMe() {
    // std::cout << ITALICGREEN "PMergeMe Destructor called" DEF << std::endl;

}

// Copy assignement
PMergeMe &PMergeMe::operator=(PMergeMe const &other) {
    // std::cout << ITALICGREEN "PMergeMe Copy assignement called" DEF << std::endl;
    if (this != &other) {
        _pairsDeque = other._pairsDeque;
        _maxima = other._maxima;
        _minima = other._minima;
    }
    return *this;
}
