/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:30 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/28 12:59:16 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <deque>
# include "../includes/PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << RED "Usage : ./PmergeMe (positif) number1 number2 number3 ... numberN" DEF << std::endl;
    }
    
    try {
        PMergeMe pairsVec(ac, av);
        pairsVec.savePairsVec(ac, av);
        
        // Print before sort
        std::cout << YELLOW "Before:  " DEF;
        for (int i = 1; i < ac; i++) {
            std::cout << av[i] << " ";
        }
        std::cout << std::endl;


        // Try with std::vector
        clock_t start = clock();
        pairsVec.recursiveSortMaxima(pairsVec.getPairsVec());
        pairsVec.insertMinimaBinarySearch(pairsVec.getPairsVec());
        clock_t end = clock();

        // Print after sort
        std::cout << YELLOW "After:   " DEF;
        pairsVec.printPairsVec();
        
        
        double durationDeque = 1000000.0 * (end - start) / CLOCKS_PER_SEC;    
        std::cout << YELLOW "Time to process a rang of " BOLDDEF << pairsVec.getMaximaVec().size() 
            << YELLOW " elements with std::vector : " DEF << durationDeque << " µs" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED "Error" << std::endl;
        std::cerr << RED "Exception catch: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

