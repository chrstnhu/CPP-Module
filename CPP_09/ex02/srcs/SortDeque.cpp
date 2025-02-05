/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:58 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/05 17:21:12 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Recursive Sort Maxima
void PMergeMe::recursiveSortMaxima(std::deque<std::pair<int, int> >& pairsDeque) {
    if (pairsDeque.size() <= 1) {
        return;
    }

    // Split deque into two parts (left and right)
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

// Jacobsthal 
std::deque<int> PMergeMe::jacobsthal(std::deque<std::pair<int, int> > &pairs) {
    // Fill main and pending deque
    for (size_t index = 0; index < pairs.size(); ++index) {
        if (pairs[index].second != 0) {
            _mainDeque.push_back(pairs[index].second);
        }
        _pendingDeque.push_back(pairs[index].first);
    }

    // Insert first pending deque
    _mainDeque.push_front(_pendingDeque[0]);

    std::deque<int> jacobsthalDeque;
    // Calculate Jacobsthal distance and add to deque
    for (int i = 3; i < 15; ++i) {
        jacobsthalDeque.push_back(jacobsthalDistance(i));
    }
    return jacobsthalDeque;
}

// Insert Pending with Binary Search
void PMergeMe::insertMinimaBinarySearch(std::deque<int> jacobsthalDeque) {
    size_t end = 0;
    size_t start = 0;

    for (size_t i = 0; i < jacobsthalDeque.size() && ! _pendingDeque.empty(); i++) {
        end = end + jacobsthalDeque[i];
        start = end - jacobsthalDeque[i] + 1;

		if (end >= _pendingDeque.size()) {
			end = _pendingDeque.size() - 1;
        }

        // Insert pending deque to main deque        
        for (size_t j = end; j >= start; j--) {
            size_t subDeque = _mainDeque.size() - (_pendingDeque.size() - (end + 1));
            int target = _pendingDeque[j];
            
            int left = 0;
            int right = subDeque;
            
            // Binary search
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (_mainDeque[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            _mainDeque.insert(_mainDeque.begin() + left, target);
        }
    }
}

// Sort Ford Johnson
void PMergeMe::sortFordJohnson(std::deque<std::pair<int, int> > &pairsDeque){
    recursiveSortMaxima(pairsDeque);
    
    // Insert if is impair
    if (!_impairNbrDeque.empty()) {
        pairsDeque.push_back(_impairNbrDeque[0]);
    }

    insertMinimaBinarySearch(jacobsthal(pairsDeque));
}
