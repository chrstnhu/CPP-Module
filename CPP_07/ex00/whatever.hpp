/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:38 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/11 12:42:06 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
T min(const T &x, const T &y)
{
	if (a < b) {
		return a;
	}
	else {
		return b;
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
void swap(const S &x, const S &y) {
	S tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

#endif