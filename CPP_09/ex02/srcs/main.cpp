/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:30 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/28 16:14:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <deque>
# include "../includes/PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 3) {
        std::cout << RED "Usage : ./PmergeMe nbr1 nbr2 ... nbrN (positive integer number)" DEF << std::endl;
        return 0;
    }
    
    try {
        PMergeMe pairsDeque(ac, av);
        PMergeMe pairsVec = pairsDeque;
        
        // Print before sort
        std::cout << YELLOW "Before:       " DEF;
        for (int i = 1; i < ac; i++) {
            std::cout << av[i] << " ";
        }
        std::cout << std::endl;

        // Try with std::deque
        pairsDeque.savePairsDeque(ac, av);
        
        clock_t startDeque = clock();
        pairsDeque.recursiveSortMaxima(pairsDeque.getPairsDeque());
        pairsDeque.insertMinimaBinarySearch(pairsDeque.getPairsDeque());
        clock_t endDeque = clock();

        // Try with std::vector
        pairsVec.savePairsVec(ac, av);
        
        clock_t startVector = clock();
        pairsVec.recursiveSortMaxima(pairsVec.getPairsVec());
        pairsVec.insertMinimaBinarySearch(pairsVec.getPairsVec());
        clock_t endVector = clock();
        
        // Print after sort
        std::cout << YELLOW "After deque : " DEF << pairsDeque << std::endl;
        std::cout << YELLOW "After vector: " DEF << pairsVec << std::endl << std::endl;
        
        // Print time deque
        double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;    
        std::cout << YELLOW "Time to process a rang of " BOLDDEF << pairsDeque.getMaximaDeque().size() 
            << YELLOW " elements with std::deque : " DEF << durationDeque << " µs" << std::endl;
    
        // Print time vector
        double durationVector = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;    
        std::cout << YELLOW "Time to process a rang of " BOLDDEF << pairsVec.getMaximaVec().size() 
            << YELLOW " elements with std::vector : " DEF << durationVector << " µs" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED "Error" << std::endl;
        std::cerr << RED "Exception catch: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

