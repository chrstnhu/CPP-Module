/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:58 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/29 14:35:44 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Save Pairs Deque
void PMergeMe::savePairsDeque(int ac, char **av) {
    for (int i = 1; i < ac; i += 2) {
        char* end;
        int first = std::strtol(av[i], &end, 10);
        if (i + 1 < ac) {
            int second = std::strtol(av[i + 1], &end, 10);
            if (first < second) {
                _pairsDeque.push_back(std::make_pair(first, second));
            }
            else {
                _pairsDeque.push_back(std::make_pair(second, first));
            }
        } else {
            _impairNbrDeque.push_back(first);
        }
    }
}

// Recursive Sort Maxima
void PMergeMe::recursiveSortMaxima(std::deque<std::pair<int, int> >& pairsDeque) {
    if (pairsDeque.size() <= 1) {
        return;
    }

    size_t mid = pairsDeque.size() / 2;
    std::deque<std::pair<int, int> > left(pairsDeque.begin(), pairsDeque.begin() + mid);
    std::deque<std::pair<int, int> > right(pairsDeque.begin() + mid, pairsDeque.end());
    
    // Recursive calls
    recursiveSortMaxima(left);
    recursiveSortMaxima(right);

    std::deque<std::pair<int, int> > result;
    size_t leftIndex = 0;
    size_t rightIndex = 0;

    // Merge elements
    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex].second < right[rightIndex].second) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex++;
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
    
    pairsDeque = result;
}

// Insert Minima with Binary Search
void PMergeMe::insertMinimaBinarySearch(std::deque<std::pair<int, int> >& pairsDeque) {

    // Fill the maxima and minima deque
    for (size_t index = 0; index < pairsDeque.size(); ++index) {
        if (pairsDeque[index].second != 0) {
            _maximaDeque.push_back(pairsDeque[index].second);
        }
        _minimaDeque.push_back(pairsDeque[index].first);
    }
    
    // If impair number, insert it in the minima vector
    if (!_impairNbrDeque.empty()) {
        _minimaDeque.push_back(_impairNbrDeque[0]);
    }
    
    // Insert the first minima in the maxima vector
    _maximaDeque.push_front(_minimaDeque[0]);

    // Insert the minima in the maxima deque
    for (size_t index = 1; index < _minimaDeque.size(); ++index) {
        int target = _minimaDeque[index];

        std::deque<int>::iterator pos = std::lower_bound(_maximaDeque.begin(), _maximaDeque.end(), target);
        _maximaDeque.insert(pos, target);
    }
}
