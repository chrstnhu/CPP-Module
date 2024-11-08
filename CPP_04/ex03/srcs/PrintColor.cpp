/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintColor.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:43:49 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 12:13:46 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

void printColor(const std::string &msg, const std::string &color) {
    std::cout << std::endl << color << msg << DEF << std::endl;
}

void printOneBloc(const std::string &msg1, int i, const std::string &color) {
    std::cout << msg1 << color << i << DEF << std::endl;
}

void printTwoBlocs(const std::string &msg1, const std::string &msg2, const std::string &msg3, int &i, const std::string &color) {
    std::cout << msg1 << color << msg2 << DEF << msg3 << color << i << DEF << std::endl;
}
