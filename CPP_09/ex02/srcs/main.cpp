/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:30 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/05 17:26:28 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <deque>
# include "../includes/PmergeMe.hpp"

// Check if the deque/vector is sorted
void isSorted(PMergeMe &pairs, int status) {
    if (status == DEQUE) {
        std::deque<int> pairsDeque = pairs.getMainDeque();
        for(size_t i = 0; i < (pairsDeque.size() - 1); i++) {
            if (pairsDeque[i] > pairsDeque[i + 1]) {
                std::cout << "Pairs[i]: " << pairsDeque[i] << std::endl;
                std::cout << "Pairs[i + 1]: " << pairsDeque[i + 1] << std::endl;
                throw notSorted();
            }
        }
        std::cout << GREEN "Deque is sorted !" DEF << std::endl;
    }
    else if (status == VECTOR) {
        std::vector<int> pairsVec = pairs.getMainVec();
        for (size_t i = 0; i < (pairsVec.size() - 1); i++) {
            if (pairsVec[i] > pairsVec[i + 1]) {
                std::cout << "PairsVec[i]: " << pairsVec[i] << std::endl;
                std::cout << "PairsVec[i + 1]: " << pairsVec[i + 1] << std::endl;
                throw notSorted();
            }
        }
        std::cout << GREEN "Vector is sorted !" DEF << std::endl;
    }
    else if (status == LIST) {
        std::list<int> pairsList = pairs.getMainList();
        std::list<int>::iterator it = pairsList.begin();
        std::list<int>::iterator nextIt = it;
        ++nextIt;
        while (nextIt != pairsList.end()) {
            if (*it > *nextIt) {
                std::cout << "PairsList[i]: " << *it << std::endl;
                std::cout << "PairsList[i + 1]: " << *nextIt << std::endl;
                throw notSorted();
            }
            ++it;
            ++nextIt;
        }
        std::cout << GREEN "List is sorted !" DEF << std::endl;
    }
}

int main(int ac, char **av) {
    if (ac < 3) {
        std::cout << RED "Usage : ./PmergeMe nbr1 nbr2 ... nbrN (positive integer number)" DEF << std::endl;
        return 0;
    }
    
    try {
        PMergeMe pairsDeque(ac, av);
        PMergeMe pairsVec = pairsDeque;
        PMergeMe pairsList = pairsDeque;
        
        // Print before sort
        std::cout << YELLOW "Nbr of args:  "  DEF << ac - 1 << YELLOW " elements" DEF << std::endl;
        std::cout << YELLOW "Before:       " DEF;
        for (int i = 1; i < ac; i++) {
            std::cout << av[i] << " ";
        }
        std::cout << std::endl;


        // Try with std::deque
        pairsDeque.savePairsDeque(ac, av);
        clock_t startDeque = clock();
        pairsDeque.sortFordJohnson(pairsDeque.getPairsDeque());
        clock_t endDeque = clock();


        // Try with std::vector
        pairsVec.savePairsVec(ac, av);
        clock_t startVector = clock();
        pairsVec.sortFordJohnson(pairsVec.getPairsVec());
        clock_t endVector = clock();


        // Try with std::list
        pairsList.savePairsList(ac, av);
        clock_t startList = clock();
        pairsList.sortFordJohnson(pairsList.getPairsList());
        clock_t endList = clock();

        
        // Print after sort and check if it's sorted
        std::cout << YELLOW "After deque : " DEF << pairsDeque << std::endl;
        isSorted(pairsDeque, DEQUE);
        std::cout << YELLOW "After vector: " DEF << pairsVec << std::endl;
        isSorted(pairsVec, VECTOR);


        std::cout << YELLOW "After list: " DEF << pairsList << std::endl;
        isSorted(pairsList, LIST);
        std::cout << std::endl;


        // Print time deque
        double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;    
        std::cout << YELLOW "Time to process a rang of " BOLDDEF << pairsDeque.getMainDeque().size() 
            << YELLOW " elements with std::deque : " DEF << durationDeque << " µs" << std::endl;
    
        // Print time vector
        double durationVector = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;    
        std::cout << YELLOW "Time to process a rang of " BOLDDEF << pairsVec.getMainVec().size() 
            << YELLOW " elements with std::vector : " DEF << durationVector << " µs" << std::endl;
    
        double durationList = 1000000.0 * (endList - startList) / CLOCKS_PER_SEC;    
        std::cout << YELLOW "Time to process a rang of " BOLDDEF << pairsList.getMainList().size() 
            << YELLOW " elements with std::list : " DEF << durationList << " µs" << std::endl;
    
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << DEF << std::endl;
    }
    return 0;
}

