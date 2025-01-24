# include <vector>
# include <deque>
# include "../includes/PmergeMe.hpp"

int main() {
    std::string array = "7 30 5 2 80 6 4 12 1 320";
    
    std::vector<int> vec;
    
    std::string tmp = "";
    for(size_t i = 0; i < array.size(); i++) {
        if (std::isdigit(array[i])) {
            tmp += array[i];
        }
        else if (!tmp.empty()) {
            std::stringstream ss(tmp);
            int number = 0;
            ss >> number;
            std::cout << number << ", ";
            vec.push_back(number);
            tmp = "";
        }
    }
    if (!tmp.empty()) {
        std::stringstream ss(tmp);
        int number = 0;
        ss >> number;
        std::cout << number << ", ";
        vec.push_back(number);
    }
    std::cout << std::endl;

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        } else {
            pairs.push_back(std::make_pair(vec[i], 0));
        }
    }
    std::vector<int> vec_max;
    std::vector<int> vec_min;
    std::cout << "Pairs:\n";
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")\n";
        if ((pairs.size() % 2 == 0) && (i == pairs.size() - 1)) {
            vec_min.push_back(pairs[i].first);
            break ;
        }
        if (pairs[i].first < pairs[i].second) {
            vec_max.push_back(pairs[i].second);
            vec_min.push_back(pairs[i].first);
        }
        else {
            vec_max.push_back(pairs[i].first);
            vec_min.push_back(pairs[i].second);
        }
    }
    std::sort(vec_max.begin(), vec_max.end());
    std::sort(vec_min.begin(), vec_min.end());

    for (size_t i = 0; i < vec_max.size(); i++) {
        std::cout << vec_max[i] << " ";
    }
    std::cout << std::endl;

/*
    std::deque<int> deq;
    for (size_t i = 0; i < vec_max.size(); i++) {
        deq.push_back(vec_max[i]);
    }

    deq.push_front(vec_min[0]);
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << "deq: " << deq[i] << ", ";
        std::cout << "vec: " << vec_min[i] << std::endl;
    }


    size_t index = 1;

    while (index < vec_min.size()) {
    int target = vec_min[index];  // Élément à insérer
    int left = 0;                 // Limite gauche
    int right = deq.size() - 1;   // Limite droite
    int middle = 0;

    // Recherche dichotomique pour trouver la position d'insertion
    while (left <= right) {
        middle = (left + right) / 2;

        if (target == deq[middle]) {
            // Insertion à la position exacte
            deq.insert(deq.begin() + middle, target);
            std::cout << "Insert: " << target << std::endl;
            break;
        } else if (target < deq[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    // Si l'élément n'a pas été inséré, insérer à la bonne position
    if (left > right) {
        deq.insert(deq.begin() + left, target);
        std::cout << "Insert: " << target << std::endl;
    }

    index++;
}

// Afficher les éléments du deque après insertion
for (size_t i = 0; i < deq.size(); i++) {
    std::cout << deq[i] << " ";
}
std::cout << std::endl;
*/


    vec_max.insert(vec_max.begin(), vec_min[0]);
    for (size_t i = 0; i < vec_min.size(); i++) {
        std::cout << "vec: " << vec_min[i] << std::endl;
    }

    size_t index = 1;

    while (index < vec_min.size()) {
    int target = vec_min[index];  // Élément à insérer
    int left = 0;                 // Limite gauche
    int right = vec_max.size() - 1;   // Limite droite
    int middle = 0;

    // Recherche dichotomique pour trouver la position d'insertion
    while (left <= right) {
        middle = (left + right) / 2;

        if (target == vec_max[middle]) {
            // Insertion à la position exacte
            vec_max.insert(vec_max.begin() + middle, target);
            std::cout << "Insert: " << target << std::endl;
            break;
        } else if (target < vec_max[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    // Si l'élément n'a pas été inséré, insérer à la bonne position
    if (left > right) {
        vec_max.insert(vec_max.begin() + left, target);
        std::cout << "Insert: " << target << std::endl;
    }

    index++;
}

    // Afficher les éléments du deque après insertion
    for (size_t i = 0; i < vec_max.size(); i++) {
        std::cout << vec_max[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}