/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_deque.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:30 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/24 17:22:02 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <deque>
# include "../includes/PmergeMe.hpp"

void recursiveSortMaxima(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) {
        return;
    }

    size_t mid = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    recursiveSortMaxima(left);
    recursiveSortMaxima(right);

    std::deque<std::pair<int, int> > result;
    size_t leftIndex = 0;
    size_t rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex].second < right[rightIndex].second) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            if (right[rightIndex].second != 0) {
                result.push_back(right[rightIndex]);
            }
            rightIndex++;
        }
    }

    while (leftIndex < left.size()) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }
    while (rightIndex < right.size()) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    pairs = result;
}

// Insert Minima with Binary Search
void insertMinimaBinarySearch(std::vector<int>& maxima, std::vector<int>& minima) {

    // Insert the first minima at the front
    maxima.insert(maxima.begin(), minima[0]);

    // Find the position of minima in the maxima vector
    for (size_t index = 1; index < minima.size(); ++index) {
        int target = minima[index];

        std::vector<int>::iterator pos = std::lower_bound(maxima.begin(), maxima.end(), target);

        maxima.insert(pos, target);
    }
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << RED "Usage : ./PmergeMe (positif) number1 number2 number3 ... numberN" DEF << std::endl;
    }
    
    try {
        PMergeMe pairsDeque(ac, av);
        pairsDeque.savePairsDeque(ac, av);
        
        // Print before sort
        std::cout << YELLOW "Before:  " DEF;
        for (int i = 1; i < ac; i++) {
            std::cout << av[i] << " ";
        }
        std::cout << std::endl;


        // Try with std::deque
        clock_t start = clock();
        pairsDeque.recursiveSortMaxima(pairsDeque.getPairsDeque());
        pairsDeque.insertMinimaBinarySearch(pairsDeque.getPairsDeque());
        clock_t end = clock();

        // Print after sort
        std::cout << YELLOW "After:   " DEF;
        pairsDeque.printPairsDeque();
        
        
        double durationDeque = 1000000.0 * (end - start) / CLOCKS_PER_SEC;    
        std::cout << YELLOW "Time to process a rang of " BOLDDEF << pairsDeque.getMaxima().size() 
            << YELLOW " elements with std::deque : " DEF << durationDeque << " µs" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED "Error" << std::endl;
        std::cerr << RED "Exception catch: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

