/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:01:00 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/04 17:22:39 by chrhu            ###   ########.fr       */
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
# define DEQUE 2
# define VECTOR 3

# include "Colors.hpp"

class PMergeMe {
    protected:
        std::deque<std::pair<int, int> > _pairsDeque;
        std::deque<std::pair<int, int> > _impairNbrDeque;
        std::deque<int> _mainDeque;
        std::deque<int> _pendingDeque;
        

        std::vector <std::pair<int, int> > _pairsVec;
        std::vector <std::pair<int, int> > _impairNbrVec;
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
        std::deque<int> &getMaximaDeque();
        
        std::vector<std::pair<int, int> > &getPairsVec();
        std::vector<int> &getMaximaVec();

        // Methods
        void checkArgs(int ac, char **av);
        int jacobsthalNumber(int n);
        int jacobsthalDistance(int n);

        // Deque
        void savePairsDeque(int ac, char **av);
        void sortFordJohnson(std::deque<std::pair<int, int> > &pairsDeque);
        void recursiveSortMaxima(std::deque<std::pair<int, int> > &pairsDeque);
        void jacobsthal(std::deque<std::pair<int, int> > &pairsDeque);
        
        void insertMinimaBinarySearch();
        
        
        // Vector
        void savePairsVec(int ac, char **av);
        void sortFordJohnson(std::vector<std::pair<int, int> > &pairsVec);
        void recursiveSortMaxima(std::vector<std::pair<int, int> > &pairsVec);
        void insertMinimaBinarySearch(std::vector<std::pair<int, int> > &pairsVec);

        #include <iostream>

        class NumberIsNotPositif : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return 
                        "\n*********************************\n"
                        "*                               *\n"
                        "*      ERROR: Number is not     *\n"
                        "*           POSITIVE !          *\n"
                        "*                               *\n"
                        "*********************************\n";
                }
        };

        class IsNotANumber: public std::exception {
            public:
                virtual const char* what() const throw() {
                    return 
                        "\n*********************************\n"
                        "*                               *\n"
                        "*      ERROR: Args is not       *\n"
                        "*           A NUMBER !          *\n"
                        "*                               *\n"
                        "*********************************\n";
                }
        };
};

class notSorted: public std::exception {
    public:
        virtual const char* what() const throw() {
            return 
                "\n*********************************\n"
                "*                               *\n"
                "*      ERROR: Not sorted        *\n"
                "*                               *\n"
                "*********************************\n";
        }
};
        
std::ostream & operator<<(std::ostream &os, PMergeMe &rhs);



# endif