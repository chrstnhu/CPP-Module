/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:19 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/16 15:33:27 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

void testReverseVector() {
    std::vector<int> vector;
    vector.push_back(5);
    vector.push_back(17);

    std::cout << "size of the vector: " << vector.size() 
            << " | top(last in) of the vector: " << vector.back() << std::endl;
    vector.pop_back();
    std::cout << "-> size of the list (after remove): " << vector.size() << std::endl << std::endl ;
    
    vector.push_back(3);
    vector.push_back(5);
    vector.push_back(737);
    vector.push_back(0);

    std::cout << DEFITALIC "==== Reverse iterating through the vector ====" DEF << std::endl;

    for (std::vector<int>::reverse_iterator it = vector.rbegin() ; it != vector.rend(); ++it) {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
    }
}

void testList() {
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "size of the list: " << lst.size() 
            << " | top(last in) of the list: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "-> size of the list (after remove): " << lst.size() << std::endl << std::endl ;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << DEFITALIC "==== Iterating through the list ====" DEF << std::endl;

    for (std::list<int>::iterator it = lst.begin() ; it != lst.end(); ++it) {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
    }
}

int main()
{
    // Main test
    std::cout << YELLOW "==== MutantStack ====" DEF << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "size of the stack: " << mstack.size() 
        << " | top(last in) of the stack: " << mstack.top() << std::endl;
    mstack.pop();
    
    std::cout << "-> size of the stack (after remove): " << mstack.size() << std::endl << std::endl ;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << DEFITALIC "==== Iterating through the mutantStack ====" DEF << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
        ++it;
    }


    // Test, compare MutantStack to list
    std::cout << YELLOW "\n==== Test list ====" DEF << std::endl;
    testList();


    // Additional test 
    std::cout << YELLOW "\n==== Copy mutantStack in stack ====" DEF << std::endl;
    std::stack<int> s(mstack);
    
    std::cout << "size of the stack: " << mstack.size() 
        << " | top(last in) of the stack: " << mstack.top() << std::endl;
    
        std::cout << DEFITALIC "\n==== Iterating through the stack ====" DEF << std::endl;

    it = mstack.begin();
    ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
        ++it;
    }
 
    std::cout << YELLOW "\n==== MutantStack reverse iterating ====" DEF << std::endl;

    // Reverse 
     std::cout << "size of the stack: " << mstack.size() 
        << " | top(last in) of the stack: " << mstack.top() << std::endl;
    
        std::cout << DEFITALIC "\n==== Reverse iterating through the stack ====" DEF << std::endl;
        
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *rit << " |" << std::endl;
        ++rit;
    }

    // Test, compare MutantStack to vector
    std::cout << YELLOW "\n==== Test vector ====" DEF << std::endl;
    testReverseVector();

    return 0;
}