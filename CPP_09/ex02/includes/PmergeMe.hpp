/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:01:00 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/24 17:21:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <ctime>
# include <sstream>
# include <cmath>
# include <algorithm>
# include <vector>
# include <deque>
# include <utility>

# define BEFORE 0
# define AFTER 1

# include "Colors.hpp"

class PMergeMe {
    protected:
        std::deque<std::pair<int, int> > _pairsDeque;
        std::deque<int> _maxima;
        std::deque<int> _minima;

        std::vector <int> _pairsVec;
        std::vector <int> _maximaVec;
        std::vector <int> _minimaVec;
        
    public:
        PMergeMe();
        PMergeMe(int ac, char **av);
        PMergeMe(PMergeMe const &other);
        ~PMergeMe();

        PMergeMe & operator=(PMergeMe const &other);

        // Getters
        std::deque<std::pair<int, int> > &getPairsDeque();
        std::deque<int> &getMaxima();
        
        std::vector<int> &getPairsVec();
        std::vector<int> &getMaximaVec();

        // Deque
        void savePairsDeque(int ac, char **av);
        void recursiveSortMaxima(std::deque<std::pair<int, int> > &pairs);
        void insertMinimaBinarySearch(std::deque<std::pair<int, int> >& pairs);
        void printPairsDeque();
        
        // Vector
        void savePairsVec(int ac, char **av);
        void recursiveSortMaxima(std::vector<int> &pairsVec);
        void insertMinimaBinarySearch(std::vector<int> &pairsVec);
        void printPairsVec();

};


# endif