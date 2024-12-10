/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:38 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/10 17:12:46 by chrhu            ###   ########.fr       */
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

	public :
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();

		// Copy assignement
		Array &operator=(const Array &other);
		T &operator[](size_t index);

		size_t size() const;
};

class InvalidIndexException : public std::exception {
	public :
		virtual const char *what() const throw() {
			return "Invalid index";
		}
};
	
# include "Array.tpp"

#endif