/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:30 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/05 16:31:17 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

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

// Jacobsthal
std::vector<int> PMergeMe::jacobsthal(std::vector<std::pair<int, int> > &pairs) {
    // Fill main and pending deque
    for (size_t index = 0; index < pairs.size(); ++index) {
        if (pairs[index].second != 0) {
            _mainVec.push_back(pairs[index].second);
        }
        _pendingVec.push_back(pairs[index].first);
    }

    // Insert first pending deque
    _mainVec.insert(_mainVec.begin(), _pendingVec[0]);

    // Calculate Jacobsthal distance and add to deque
    std::vector<int> jacobsthalVec;
    for (int i = 3; i < 15; ++i) {
        jacobsthalVec.push_back(jacobsthalDistance(i));
    }
    return jacobsthalVec;
}

// Insert pending with Binary Search
void PMergeMe::insertMinimaBinarySearch(std::vector<int> jacobsthalVec) {
    size_t end = 0;
    size_t start = 0;

    for (size_t i = 0; i < jacobsthalVec.size() && ! _pendingVec.empty(); i++) {
        end = end + jacobsthalVec[i];
        start = end - jacobsthalVec[i] + 1;

		if (end >= _pendingVec.size()) {
			end = _pendingVec.size() - 1;
        }

        // Insert pending deque to main deque        
        for (size_t j = end; j >= start; j--) {
            size_t subDeque = _mainVec.size() - (_pendingVec.size() - (end + 1));
            int target = _pendingVec[j];
            
            int left = 0;
            int right = subDeque;
            
            // Binary search
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (_mainVec[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            _mainVec.insert(_mainVec.begin() + left, target);
        }
    }
}

// Sort Ford Johnson
void PMergeMe::sortFordJohnson(std::vector<std::pair<int, int> > &pairsVec){
    recursiveSortMaxima(pairsVec);
    
    // Insert if is impair
    if (!_impairNbrVec.empty()) {
        pairsVec.push_back(_impairNbrVec[0]);
    }
    
    insertMinimaBinarySearch(jacobsthal(pairsVec));
}