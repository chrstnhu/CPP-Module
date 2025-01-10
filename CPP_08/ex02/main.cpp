/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:19 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 16:59:08 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

void testVector() {
    std::vector<int> vector;
    vector.push_back(5);
    vector.push_back(17);

     std::cout << "size of the vector: " << vector.size() << std::endl;
    std::cout << "top(last in) of the vector: " << vector.back() << std::endl << std::endl ;
    vector.pop_back();

    std::cout << "size of the vector (after remove): " << vector.size() << std::endl << std::endl ;
    vector.push_back(3);
    vector.push_back(5);
    vector.push_back(737);
    vector.push_back(0);

    std::cout << DEFITALIC << "==== Iterating through the vector ====" << DEF << std::endl;

    std::vector<int>::iterator it = vector.begin();
    std::vector<int>::iterator ite = vector.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
        ++it;
    }
}

void testList() {
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "size of the list: " << lst.size() << std::endl;
    std::cout << "top(last in) of the list: " << lst.back() << std::endl << std::endl ;
    lst.pop_back();

    std::cout << "size of the list (after remove): " << lst.size() << std::endl << std::endl ;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << DEFITALIC << "==== Iterating through the list ====" << DEF << std::endl;

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
        ++it;
    }
}

void additonalTests() {
    std::list<std::string> lst;
    lst.push_back("1.Hello");
    lst.push_back("2.World");
    lst.push_back("3.Bob");

    std::cout << DEFITALIC << "==== Iterating through the list of string ====" << DEF << std::endl;

    std::list<std::string>::iterator it = lst.begin();
    std::list<std::string>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
        ++it;
    }

    lst.push_front("4.Welcome");
    std::cout << std::endl << DEFITALIC << "--> add 'Welcome' at the front" << DEF << std::endl;
    
    it = lst.begin();
    ite = lst.end();
    while (it != ite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
        ++it;
    }
    
    std::cout << std::endl << DEFITALIC << "--> add 'Nothing' before the third element" << DEF << std::endl;
    std::list<std::string>::iterator itInsert = lst.begin();
    std::advance(itInsert, 2); // go to the third element
    lst.insert(itInsert, "5.Nothing"); // insert before
    it = lst.begin();
    ite = lst.end();
    while (it != ite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
        ++it;
    }

    std::cout << std::endl << DEFITALIC << "--> reverse element" << DEF << std::endl;
    lst.reverse();
    
    it = lst.begin();
    ite = lst.end();
    while (it != ite)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "| " << *it << " |" << std::endl;
        ++it;
    }
}

int main()
{
    std::cout << YELLOW << "==== MutantStack ====" << DEF << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "size of the stack: " << mstack.size() << std::endl;
    std::cout << "top(last in) of the stack: " << mstack.top() << std::endl << std::endl;
    mstack.pop();
    
    std::cout << "size of the stack (after remove): " << mstack.size() << std::endl << std::endl ;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << DEFITALIC << "==== Iterating through the stack ====" << DEF << std::endl;

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
    std::stack<int> s(mstack);
    

    std::cout << std::endl << YELLOW << "==== Test Vector ====" << DEF << std::endl;
    testVector();
 
    std::cout << std::endl << YELLOW << "==== Test list ====" << DEF << std::endl;
    testList();

    std::cout << std::endl << YELLOW << "==== Additional Test ====" << DEF << std::endl;
    additonalTests();
    return 0;
}