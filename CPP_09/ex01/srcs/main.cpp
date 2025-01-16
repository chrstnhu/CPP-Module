/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:35 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/16 17:44:13 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"



int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << RED << "Usage : ./RPN \"number and operand (type RPN)\" " << DEF << std::endl;
    }

    try {
        RPN rpn;
                
        std::cout << rpn.evalRPN(av[1]) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << DEF << std::endl;
    }
}