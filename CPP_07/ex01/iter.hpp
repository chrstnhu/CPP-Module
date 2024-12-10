/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:38 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/10 12:46:29 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

# define YELLOW "\033[0;33m"
# define DEF "\033[0;39m"

template <typename T>
void iter(T *array, size_t size, void (*func) (T const &)) {
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}

#endif