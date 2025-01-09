/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:38 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/11 16:17:35 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>

# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define DEF "\033[0;39m"
# define GREEN "\033[0;32;3m"

template <typename T>
class Array {
	private :
		T *_array;
		unsigned int _size;
		unsigned int _currentSize;

	public :
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();

		// Copy assignement
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		T const &operator[](unsigned int index) const;

		// Setter
		unsigned int size() const;
		void add(const T &element, unsigned int index);
};
	
# include "Array.tpp"

#endif