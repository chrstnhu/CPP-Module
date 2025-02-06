/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:58 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/06 15:01:08 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Default constructor
PMergeMe::PMergeMe(): 
    _pairsDeque(), _impairNbrDeque(), _mainDeque(), _pendingDeque(),  
    _pairsVec(), _impairNbrVec(), _mainVec(), _pendingVec() {
    // std::cout << ITALICGREEN "PMergeMe default constructor called" DEF << std::endl;
    throw std::invalid_argument("Error: Need parameter PmergeMe(int ac, char **av)");
}

// Copy constructor
PMergeMe::PMergeMe(PMergeMe const &other) {
    // std::cout << ITALICGREEN "PMergeMe Copy Constructor called" DEF << std::endl;
    if (this != &other) {
        _pairsDeque = other._pairsDeque;
        _impairNbrDeque = other._impairNbrDeque;
        _mainDeque = other._mainDeque;
        _pendingDeque = other._pendingDeque;

        _pairsVec = other._pairsVec;
        _impairNbrVec = other._impairNbrVec;
        _mainVec = other._mainVec;
        _pendingVec = other._pendingVec;
    }
}

// Constructor with parameter
PMergeMe::PMergeMe(int ac, char **av): 
    _pairsDeque(),_impairNbrDeque(),  _mainDeque(), _pendingDeque(),
    _pairsVec(), _impairNbrVec(), _mainVec(), _pendingVec()  {
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
        _impairNbrDeque = other._impairNbrDeque;
        _mainDeque = other._mainDeque;
        _pendingDeque = other._pendingDeque;
        
        _pairsVec = other._pairsVec;
        _impairNbrVec = other._impairNbrVec;
        _mainVec = other._mainVec;
        _pendingVec = other._pendingVec;
    }
    return *this;
}

// METHODS
void PMergeMe::checkArgs(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        char* end;
        if (std::strtol(av[i], &end, 10) < 0) {
            throw PMergeMe::NumberIsNotPositif();
        }
        if (!std::isdigit(av[i][0])) {
            throw PMergeMe::IsNotANumber();
        }
    }
}

// GETTERS

// Deque
std::deque<std::pair<int, int> > &PMergeMe::getPairsDeque() {
    return _pairsDeque;
}

std::deque<int> &PMergeMe::getMainDeque() {
    return _mainDeque;
}

// Vector
std::vector<std::pair<int, int> > &PMergeMe::getPairsVec() {
    return _pairsVec;
}

std::vector<int>&PMergeMe::getMainVec() {
    return _mainVec;
}

// // List
// std::list<std::pair<int, int> > &PMergeMe::getPairsList() {
//     return _pairsList;
// }

// std::list<int>&PMergeMe::getMainList() {
//     return _mainList;
// }

// METHODS
// Save pairs and swap the biggest number to the right
void PMergeMe::savePairsDeque(int ac, char **av) {
    for (int i = 1; i < ac; i += 2) {
        char* end;
        int first = std::strtol(av[i], &end, 10);
        if (i + 1 < ac) {
            int second = std::strtol(av[i + 1], &end, 10);
            if (first < second) {
                _pairsDeque.push_back(std::make_pair(first, second));
            }
            else {
                _pairsDeque.push_back(std::make_pair(second, first));
            }
        } 
        else {
            _impairNbrDeque.push_back(std::make_pair(first, 0));
        }
    }
}

// Save Pairs Vector
void PMergeMe::savePairsVec(int ac, char **av) {
    for (int i = 1; i < ac; i += 2) {
        char* end;
        int first = std::strtol(av[i], &end, 10);
        if (i + 1 < ac) {
            int second = std::strtol(av[i + 1], &end, 10);
            if (first < second) {
                _pairsVec.push_back(std::make_pair(first, second));
            }
            else {
                _pairsVec.push_back(std::make_pair(second, first));
            }
        } else {
            _impairNbrVec.push_back(std::make_pair(first, 0));
        }
    }
}


// void PMergeMe::savePairsList(int ac, char **av) {
//     for (int i = 1; i < ac; i += 2) {
//         char* end;
//         int first = std::strtol(av[i], &end, 10);
//         if (i + 1 < ac) {
//             int second = std::strtol(av[i + 1], &end, 10);
//             if (first < second) {
//                 _pairsList.push_back(std::make_pair(first, second));
//             }
//             else {
//                 _pairsList.push_back(std::make_pair(second, first));
//             }
//         } else {
//             _impairNbrList.push_back(std::make_pair(first, 0));
//         }
//     }
// }


// Jacobsthal number
int PMergeMe::jacobsthalNumber(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

int PMergeMe::jacobsthalDistance(int n) {
    // Traitement spécial pour les indices faibles
    if (n <= 0) {
        return 0;  // Si n <= 0, la distance est 0
    }
    
    int jacobsthal_n = jacobsthalNumber(n);
    int jacobsthal_n_minus_1 = jacobsthalNumber(n - 1);
    return jacobsthal_n - jacobsthal_n_minus_1;
}


// Overload operator<<
std::ostream & operator<<(std::ostream &os, PMergeMe &rhs) {
    int count = 0;
    for (std::deque<int >::iterator it = rhs.getMainDeque().begin(); it != rhs.getMainDeque().end(); ++it) {
        if (count < MAXNBR) {
            os << *it << " ";
            count++;
        }
        else {
            os << "[...] ";
            break;
        }
    }
    for (std::vector<int >::iterator it = rhs.getMainVec().begin(); it != rhs.getMainVec().end(); ++it) {
        if (count < MAXNBR) {
            os << *it << " ";
            count++;
        }
        else {
            os << "[...] ";
            break;
        }
    }
    // for (std::list<int>::iterator it = rhs.getMainList().begin(); it != rhs.getMainList().end(); ++it) {
    //     if (count < MAXNBR) {
    //         os << *it << " ";
    //         count++;
    //     }
    //     else {
    //         os << "[...] ";
    //         break;
    //     }
    // }
    return os;
}