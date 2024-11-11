/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:07:31 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/11 12:48:04 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 
# define MAX_IDEAS 100
#include <iostream>
#include <string>

class Brain {
	public:
		std::string ideas[MAX_IDEAS];
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);
};

#endif