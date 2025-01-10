/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:00:40 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 11:47:42 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32;3m"

# include <iostream>
# include <algorithm>
# include <vector>
# include <sstream>

template <typename T>
void easyfind(T &container, int n);

#include "easyfind.tpp"

# endif