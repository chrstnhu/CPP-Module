/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:46 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 16:26:40 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define DEF "\033[0m"
# define DEFITALIC "\033[1;3m"

# include <iostream>
# include <stack>
# include <string>
# include <list>
# include <vector>

template <typename T>
class MutantStack : public std::stack<T> {
    public :
        MutantStack<T>();
        MutantStack<T>(MutantStack const &other);
        virtual ~MutantStack<T>();

        // Copy assignment operator        
        MutantStack<T> &operator=(MutantStack const &other);
        
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
        iterator end();
};

#endif
