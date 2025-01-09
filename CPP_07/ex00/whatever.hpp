/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:38 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/11 12:46:52 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define YELLOW "\033[0;33m"
# define YELLOWITALIC "\033[0;33;3m"

# define DEF "\033[0;39m"

# include <iostream>
# include <string>

template <typename T>
T min(const T &x, const T &y)
{
	if (x < y) {
		return x;
	}
	else {
		return y;
	}
};

template <typename U>
U max(const U &x, const U &y)
{
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
};

template <typename S>
void swap(S &x, S &y) {
	S tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

#endif