/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:30 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/29 14:54:36 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Save Pairs Vector
void PMergeMe::savePairsVec(int ac, char **av) {
    for (int i = 1; i < ac; i += 2) {
        char* end;
        int first = std::strtol(av[i], &end, 10);
        if (i + 1 < ac) {
            int second = std::strtol(av[i + 1], &end, 10);
            if (first < second) {
                _pairsVec.push_back(std::make_pair(first, second));
            }
            else {
                _pairsVec.push_back(std::make_pair(second, first));
            }
        } else {
            _impairNbrVec.push_back(std::make_pair(first, 0));
        }
    }
}

// Recursive Sort Maxima
void PMergeMe::recursiveSortMaxima(std::vector<std::pair<int, int> > &pairsVec) {
    if (pairsVec.size() <= 1) {
        return;
    }

    size_t mid = pairsVec.size() / 2;
    std::vector<std::pair<int, int> > left(pairsVec.begin(), pairsVec.begin() + mid);
    std::vector<std::pair<int, int> > right(pairsVec.begin() + mid, pairsVec.end());
    
    // Recursive calls
    recursiveSortMaxima(left);
    recursiveSortMaxima(right);

    std::vector<std::pair<int, int> > result;
    size_t leftIndex = 0;
    size_t rightIndex = 0;

    // Merge elements
    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex].second < right[rightIndex].second) {
            result.push_back(left[leftIndex]);
            leftIndex ++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex ++;
        }
    }

    // Insert remaining elements
    while (leftIndex < left.size()) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }
    while (rightIndex < right.size()) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    pairsVec = result;
}


// Insert Minima with Binary Search
void PMergeMe::insertMinimaBinarySearch(std::vector<std::pair<int, int> > &pairsVec) {
    // Fill the maxima and minima vectors
    for (size_t index = 0; index < pairsVec.size(); ++index) {
        if (pairsVec[index].second != 0) {
            _maximaVec.push_back(pairsVec[index].second);
        }
        _minimaVec.push_back(pairsVec[index].first);
    }
    
    // Insert the first minima in the maxima vector
    _maximaVec.insert(_maximaVec.begin(), _minimaVec[0]);

    // Insert the minima in the maxima vector
    for (size_t index = 1; index < _minimaVec.size(); ++index) {
        int target = _minimaVec[index];

        std::vector<int>::iterator pos = std::lower_bound(_maximaVec.begin(), _maximaVec.end(), target);
        _maximaVec.insert(pos, target);
    }
}

void PMergeMe::sortFordJohnson(std::vector<std::pair<int, int> > &pairsVec){
    recursiveSortMaxima(pairsVec);
    
    if (!_impairNbrVec.empty()) {
        pairsVec.push_back(_impairNbrVec[0]);
    }
    
    insertMinimaBinarySearch(pairsVec);
}