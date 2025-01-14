/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:38 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/14 18:28:02 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

# define YELLOW "\033[0;33m"
# define DEF "\033[0;39m"

template <typename T>
void iter(T *array, size_t size, void (*func) (T &)) {
	if (array == NULL || func == NULL) {
		return ;
	}
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}

template <typename T>
void iter(T *array, size_t size, void (*func) (T const &)) {
	if (array == NULL || func == NULL) {
		return ;
	}
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}

#endif