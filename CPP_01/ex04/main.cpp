/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:02:23 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/23 18:21:10 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int ac, char **av) {
    std::string line;

    if (ac == 2) {
        std::ifstream myfile(av[1]);
        if (myfile.is_open()) {
            while (std::getline(myfile, line)) {
                std::cout << line << '\n';
            }
            myfile.close(); 
        } else
            std::cout << RED << "Can't read this file" << DEF << std::endl;
    } else
        std::cout << RED << "Usage: " << av[0] << " <filename>" << DEF << std::endl;
    return (0);
}
