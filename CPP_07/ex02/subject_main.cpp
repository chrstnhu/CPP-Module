/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/11 14:08:03 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define MAX_VAL 750

void printColor(const std::string &msg, const std::string &color) {
    std::cout << std::endl << color << msg << DEF << std::endl;
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE (test copy constructor)
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // Test a negative index
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << DEF << '\n';
    }
    
    // Test an too high index 
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << DEF << '\n';
    }

    // Test random value
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;

    return 0;
}