/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:01:00 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/05 16:53:07 by chrhu            ###   ########.fr       */
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

# include <list>

# define BEFORE 0
# define AFTER 1
# define DEQUE 2
# define VECTOR 3
# define LIST 4

# include "Colors.hpp"
# include "ExceptionError.hpp"

class PMergeMe : public ExceptionError{
    protected:
        std::deque<std::pair<int, int> > _pairsDeque;
        std::deque<std::pair<int, int> > _impairNbrDeque;
        std::deque<int> _mainDeque;
        std::deque<int> _pendingDeque;

        std::vector <std::pair<int, int> > _pairsVec;
        std::vector <std::pair<int, int> > _impairNbrVec;
        std::vector <int> _mainVec;
        std::vector <int> _pendingVec;        

        std::list <std::pair<int, int> > _pairsList;
        std::list <std::pair<int, int> > _impairNbrList;
        std::list <int> _mainList;
        std::list <int> _pendingList;        
        
    public:
        PMergeMe();
        PMergeMe(int ac, char **av);
        PMergeMe(PMergeMe const &other);
        ~PMergeMe();

        // Copy assignement
        PMergeMe & operator=(PMergeMe const &other);

        // Getters
        std::deque<std::pair<int, int> > &getPairsDeque();
        std::deque<int> &getMainDeque();
        
        std::vector<std::pair<int, int> > &getPairsVec();
        std::vector<int> &getMainVec();

        std::list<std::pair<int, int> > &getPairsList();
        std::list<int> &getMainList();

        // Methods
        void checkArgs(int ac, char **av);
        int jacobsthalNumber(int n);
        int jacobsthalDistance(int n);

        // Deque
        void savePairsDeque(int ac, char **av);
        void sortFordJohnson(std::deque<std::pair<int, int> > &pairsDeque);
        void recursiveSortMaxima(std::deque<std::pair<int, int> > &pairsDeque);
        std::deque<int> jacobsthal(std::deque<std::pair<int, int> > &pairsDeque);
        void insertMinimaBinarySearch(std::deque<int> jacobsthalDist);
        
        // Vector
        void savePairsVec(int ac, char **av);
        void sortFordJohnson(std::vector<std::pair<int, int> > &pairsVec);
        void recursiveSortMaxima(std::vector<std::pair<int, int> > &pairsVec);
        std::vector<int> jacobsthal(std::vector<std::pair<int, int> > &pairsDeque);
        void insertMinimaBinarySearch(std::vector<int> jacobsthalDist);

        // List
        void savePairsList(int ac, char **av);
        void sortFordJohnson(std::list<std::pair<int, int> > &pairsVec);
        void recursiveSortMaxima(std::list<std::pair<int, int> > &pairsVec);
        std::list<int> jacobsthal(std::list<std::pair<int, int> > &pairsDeque);
        void insertMinimaBinarySearch(std::list<int> jacobsthalDist);

};

std::ostream & operator<<(std::ostream &os, PMergeMe &rhs);

# endif