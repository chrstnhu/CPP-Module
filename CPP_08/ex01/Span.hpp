/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:51:06 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 14:38:36 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32;3m"

# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>

class Span {
    private :
        unsigned int _n;
        
    protected:
        std::vector<int> _vec;
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
        
        // Methods
        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        int findSmallestNumber();
        int findBiggestNumber();
};

#endif