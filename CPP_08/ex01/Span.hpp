/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:51:06 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/16 13:20:04 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define DEF "\033[0;39m"
# define ITALICDEF "\033[0;39;3m"
# define BOLDDEF "\033[0;39;1m"

# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32;3m"
# define BOLDGREEN "\033[0;32;1m"

# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
#include <limits>

class Span {
    private :
        unsigned int _N;
        
        
    protected:
        std::vector<int> _vec;
        int _currentVec;
        int _nextVec;
        int _biggestNumber;
        int _smallestNumber;

    public :
        Span();
        Span(unsigned int n);
        Span(Span const &other);
        ~Span();

        // Copy assignment operator
        Span &operator=(Span const &other);
        
        // Getter
        unsigned int getN() const;
        std::vector<int> getVec() const;
        int getCurrentVec() const;
        int getNextVec() const;
        
        // Methods
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        int getSmallestNumber();
        int getBiggestNumber();

        void printVector() const;
};

#endif