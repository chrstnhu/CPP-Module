/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:00:59 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/28 16:07:20 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

void printColor(const std::string &msg, const std::string &color, int needEndl) {
	if (needEndl == 1) {
	    std::cout << std::endl << color << msg << DEF << std::endl;
	} else {
		std::cout << color << msg << DEF << std::endl;
	}
}

void separatorLine() {
	std::cout << std::endl << "==============================================================================================" << std::endl;
}