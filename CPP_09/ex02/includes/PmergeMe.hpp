/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:01:00 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/29 14:35:22 by chrhu            ###   ########.fr       */
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
        std::deque<int> _maximaDeque;
        std::deque<int> _minimaDeque;
        std::deque<int> _impairNbrDeque;

        std::vector <std::pair<int, int> > _pairsVec;
        std::vector <int> _maximaVec;
        std::vector <int> _minimaVec;
        std::vector <int> _impairNbrVec;
        
    public:
        PMergeMe();
        PMergeMe(int ac, char **av);
        PMergeMe(PMergeMe const &other);
        ~PMergeMe();

        PMergeMe & operator=(PMergeMe const &other);

        // Getters
        std::deque<std::pair<int, int> > &getPairsDeque();
        std::deque<int> &getMaximaDeque();
        
        std::vector<std::pair<int, int> > &getPairsVec();
        std::vector<int> &getMaximaVec();

        // Methods
        void checkArgs(int ac, char **av);

        // Deque
        void savePairsDeque(int ac, char **av);
        void recursiveSortMaxima(std::deque<std::pair<int, int> > &pairs);
        void insertMinimaBinarySearch(std::deque<std::pair<int, int> >& pairs);
        
        // Vector
        void savePairsVec(int ac, char **av);
        void recursiveSortMaxima(std::vector<std::pair<int, int> > &pairsVec);
        void insertMinimaBinarySearch(std::vector<std::pair<int, int> > &pairsVec);

        

};

std::ostream & operator<<(std::ostream &os, PMergeMe &rhs);

# endif