/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:51:02 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/16 13:41:48 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void testInvalidSpan() {
    // Test on a empty vector
    std::cout << ITALICDEF "\n-> Try to test empty vector" DEF << std::endl;
    try {
        Span sp;

        sp.shortestSpan();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED "Exception caught: " << e.what() << DEF << std::endl << std::endl;
    }
    
    // Test on a vector with 1 element
    std::cout << ITALICDEF "\n-> Try to test with 1 element" DEF << std::endl;
    try {
        Span sp(-1);
        sp.addNumber(1);

        sp.shortestSpan();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED "Exception caught: " << e.what() << DEF << std::endl << std::endl;
    }
    
    // Test on a vector full
    std::cout << ITALICDEF "\n-> Try to test full vector" DEF << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);

        sp.shortestSpan();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED "Exception caught: " << e.what() << DEF << std::endl << std::endl;
    }   
}

void testMainSubject() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Largest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED "Exception caught: " << e.what() << DEF << std::endl;
    }
}

int main () {
    srand(time(NULL));
    try {
        int nbr = 10000;
        Span sp(nbr);

        for (int i = 0; i < nbr; i++) {
            int random = rand() % 200000 - 100000;
            sp.addNumber(random);
        }
        sp.printVector();

        std::cout << YELLOW "\n==== Test with " << nbr << " numbers ====" DEF << std::endl;
        
        std::cout << ITALICDEF " -> Shortest Span (shortest distance beetween two number)" DEF<< std::endl;
        std::cout << std::endl << "Shortest span: " << BOLDGREEN << sp.shortestSpan()  << DEF << std::endl;
        std::cout << YELLOW << "Current number: " << sp.getCurrentVec()
                << " | " << "Next number: " << sp.getNextVec() << DEF << std::endl << std::endl;


        std::cout << ITALICDEF "-> Longest Span (Longest distance beetween two number)" DEF << std::endl;  
        std::cout << "Longest span: " << BOLDGREEN << sp.longestSpan() << DEF << std::endl;
        std::cout << YELLOW "Smallest number: " << sp.getSmallestNumber()
                << " | " << "Biggest number: " << sp.getBiggestNumber() << DEF << std::endl;

    }
    catch (std::exception &e) {
        std::cout << RED "Exception caught: " << e.what() << DEF << std::endl;
    }

    std::cout << YELLOW "\n==== Fill Span using a range of iterators ===== " DEF << std::endl;
    try {
        int nbr = 10;
        Span sp(nbr);

        std::vector<int> numbers;
        for (int i = 0; i < nbr; i++) {
            numbers.push_back(i);
        }
        sp.addNumber(numbers.begin(), numbers.end());
        sp.printVector();
    }
    catch (std::exception &e) {
        std::cout << RED "Exception caught: " << e.what() << DEF << std::endl;
    }
    
    std::cout << YELLOW "\n==== Test Invalid Span ====" DEF << std::endl;
    testInvalidSpan();

    
    std::cout << YELLOW "\n==== Test Main Subject ====" DEF << std::endl;
    testMainSubject();
    return 0;
}