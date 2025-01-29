/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:58 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/29 14:10:58 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Default constructor
PMergeMe::PMergeMe(): 
    _pairsDeque(), _maximaDeque(), _minimaDeque(), _impairNbrDeque(), 
    _pairsVec(), _maximaVec(), _minimaVec(), _impairNbrVec() {
    // std::cout << ITALICGREEN "PMergeMe default constructor called" DEF << std::endl;
    throw std::invalid_argument("Error: Need parameter PmergeMe(int ac, char **av)");
}

// Copy constructor
PMergeMe::PMergeMe(PMergeMe const &other) {
    // std::cout << ITALICGREEN "PMergeMe Copy Constructor called" DEF << std::endl;
    if (this != &other) {
        _pairsDeque = other._pairsDeque;
        _maximaDeque = other._maximaDeque;
        _minimaDeque = other._minimaDeque;
        _impairNbrDeque = other._impairNbrDeque;

        _pairsVec = other._pairsVec;
        _maximaVec = other._maximaVec;
        _minimaDeque = other._minimaDeque;
        _impairNbrVec = other._impairNbrVec;
    }
}

// Constructor with parameter
PMergeMe::PMergeMe(int ac, char **av): 
    _pairsDeque(), _maximaDeque(), _minimaDeque(), _impairNbrDeque(), 
    _pairsVec(), _maximaVec(), _minimaVec(), _impairNbrVec() {
    // std::cout << ITALICGREEN "PMergeMe Constructor with parameter called" DEF << std::endl;
    checkArgs(ac, av);
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
        _maximaDeque = other._maximaDeque;
        _minimaDeque = other._minimaDeque;
        _impairNbrDeque = other._impairNbrDeque;
        
        _pairsVec = other._pairsVec;
        _maximaVec = other._maximaVec;
        _minimaDeque = other._minimaDeque;
        _impairNbrVec = other._impairNbrVec;
    }
    return *this;
}

// METHODS
void PMergeMe::checkArgs(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        char* end;
        if (std::strtol(av[i], &end, 10) < 0) {
            throw std::invalid_argument("is not a positif number");
        }
        if (!std::isdigit(av[i][0])) {
            throw std::invalid_argument("is not a number");
        }
    }
}

// GETTERS

// Deque
std::deque<std::pair<int, int> > &PMergeMe::getPairsDeque() {
    return _pairsDeque;
}

std::deque<int> &PMergeMe::getMaximaDeque() {
    return _maximaDeque;
}

// Vector
std::vector<std::pair<int, int> > &PMergeMe::getPairsVec() {
    return _pairsVec;
}

std::vector<int>&PMergeMe::getMaximaVec() {
    return _maximaVec;
}

// Overload operator<<
std::ostream & operator<<(std::ostream &os, PMergeMe &rhs) {
    for (std::deque<int >::iterator it = rhs.getMaximaDeque().begin(); it != rhs.getMaximaDeque().end(); ++it) {
        os << *it << " ";
    }
    for (std::vector<int >::iterator it = rhs.getMaximaVec().begin(); it != rhs.getMaximaVec().end(); ++it) {
        os << *it << " ";
    }
    return os;
}
