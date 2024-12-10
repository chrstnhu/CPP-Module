/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:52:21 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/10 17:20:52 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {
	std::cout << GREEN << "Array Constructor" << DEF << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
	std::cout << GREEN << "Array Constructor with parameter" <<  DEF << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other) {
	std::cout << GREEN << "Array Copy Constructor" <<  DEF << std::endl;
	this->_size = other._size;
	this->_array = new T(other._size);
    for (unsigned int i = 0; i < this->_size; ++i) {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>::~Array() {
	std::cout << GREEN << "Array destructor" <<  DEF << std::endl;
	delete[] this->_array;
}

// Copy assignement
template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	std::cout << GREEN << "Array Copy assignement" <<  DEF << std::endl;
	if (this != &other) {
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T(other._size);	
	    for (unsigned int i = 0; i < this->_size; ++i) {
        	_array[i] = other._array[i];
	    }
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= this->_size) {
        throw InvalidIndexException();
    }
    return this->_array[index];
}

template <typename T>
size_t Array<T>::size() const {
	return this->_size;
}

# endif