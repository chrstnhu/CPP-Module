/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:37 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 15:26:51 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Default constructor
template <typename T>
MutantStack<T>::MutantStack() {
    std::cout << GREEN << "MutantStack default constructor" << DEF << std::endl;
}

// Copy constructor
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) {
    std::cout << GREEN << "MutantStack copy constructor" << DEF << std::endl;
    if (this != &other) {
        this = other;
    }
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << GREEN << "MutantStack destructor" << DEF << std::endl;

}

// Copy assignment operator        
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) {
    std::cout << GREEN << "MutantStack copy assignement operator" << DEF << std::endl;
    if (this != &other) {
        this = other;
    }
    return *this;
}

