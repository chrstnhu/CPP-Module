/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:51:02 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 14:45:25 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void testInvalidSpan() {
    // Test on a empty vector
    try {
        Span sp;

        sp.shortestSpan();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << DEF << std::endl << std::endl;
    }
    
    // Test on a vector with 1 element
    try {
        Span sp(-1);
        sp.addNumber(1);

        sp.shortestSpan();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << DEF << std::endl << std::endl;
    }
    
    // Test on a vector full
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);

        sp.shortestSpan();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << DEF << std::endl << std::endl;
    }   
}

int main () {
    srand(time(NULL));
    try {
        Span sp = Span(20000);

        for (int i = 0; i < 10000; i++) {
            int random = rand() % 200001 - 100000;
            sp.addNumber(random);
            std::cout << random << ", " ;
        }

        std::cout << std::endl << YELLOW << "==== Test with 20 000 numbers ====" << DEF << std::endl;
        std::cout << YELLOW << "Smallest number: " << sp.findSmallestNumber()
                << " | " << "Biggest number: " << sp.findBiggestNumber() << DEF << std::endl;
        
        sp.shortestSpan();
        std::cout << std::endl << "Shortest span: " << sp.shortestSpan()  << std::endl;
        
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << DEF << std::endl;
    }

    std::cout << std::endl << YELLOW << "==== Test Invalid Span ====" << DEF << std::endl;
    testInvalidSpan();
    return 0;
}