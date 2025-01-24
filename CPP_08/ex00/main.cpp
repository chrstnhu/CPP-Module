/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:00:38 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 11:50:05 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#
int main() {
    std::vector<int> vec;

    // Test on a empty vector
    std::cout << YELLOW << "===  Empty vector === " << DEF << std::endl;
    try {
        std::cout << "-> Try find element in a empty vector" << std::endl;
        easyfind(vec, 1);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << DEF << std::endl;
    }

    // Test on a vector with elements
    std::cout << std::endl << YELLOW << "===  Add bloc to vector === " << DEF << std::endl;
    vec.push_back(102);
    vec.push_back(42);
    vec.push_back(2);
    vec.push_back(-26);
    vec.push_back(5);

    try {
        std::cout << "-> Try to find value 102" << std::endl;
        easyfind(vec, 102);
        std::cout << "-> Try to find value -26" << std::endl;
        easyfind(vec, -26);
         std::cout << "-> Try to find value 5" << std::endl;
        easyfind(vec, 5);
        std::cout << "-> Try to find value 6" << std::endl;
        easyfind(vec, 6);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << DEF << std::endl;
    }

    
    // Remove last element
    std::cout << std::endl << YELLOW << "===  Rm vector last bloc === " << DEF << std::endl;
    vec.pop_back();
    try {
        std::cout << "-> Try to find value 5" << std::endl;
        easyfind(vec, 5);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << DEF << std::endl;
    }


    // Test with char list
    std::cout << std::endl << YELLOW << "===  Test with char list === " << DEF << std::endl;
    std::list<char> list;
    
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('d');
    list.push_back('e');

    try {
        std::cout << "-> Try accessing elements 'c'" << std::endl;
        easyfind(list, 'c');
        std::cout << "-> Try accessing elements 'a'" << std::endl;
        easyfind(list, 'a');
        std::cout << "-> Try accessing elements 'z'" << std::endl;
        easyfind(list, 'z');
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << DEF << std::endl;
    }    
    return 0;
}