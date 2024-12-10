/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:38 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/10 12:26:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
T min(const T &a, const T &b)
{
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
};

template <typename U>
U max(const U &a, const U &b)
{
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
};

template <typename S>
void swap( S &a, S &b) {
	S tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

#endif