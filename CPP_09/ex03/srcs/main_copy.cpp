# include <vector>
# include <deque>
# include "../includes/PmergeMe.hpp"

void sortMaxima(std::vector<int> &vector) {
    // Un seul element ou aucun
    if (vector.size() <= 1) {
        return;
    }

    std::deque <std::pair <int, int> > pairs;
    for (size_t i = 0; i < vector.size(); i+=2) {
        if (i + 1 < vector.size()) {
            if (vector[i] < vector[i + 1]) {
                pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
            }
            else {
                pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
            }
        } else {
            pairs.push_back(std::make_pair(vector[i], 0));
        }
    }

    std::vector <int> maxima;
    for (size_t i = 0; i < pairs.size(); i++) {
        maxima.push_back(pairs[i].second);
    }
    sortMaxima(maxima);
    std::vector<int> result = maxima;
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first != 0) { // Ne pas insérer le 0 si ajouté pour équilibrer
            // Trouver la position pour insérer `first` (par recherche dichotomique)
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pairs[i].first);

            // Insérer manuellement à la position trouvée
            result.insert(result.begin() + (pos - result.begin()), pairs[i].first);
        }
    }
    vector = result;
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second; // Trier par le plus grand élément
}

int main() {
    std::string array = "7 30 5 2 80 6 4 12 320 20 0 6 3";
    
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
            if (vec[i] < vec[i + 1]) {
                pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
            }
            else {
                pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
            }
        } else {
            pairs.push_back(std::make_pair(vec[i], 0));
        }
    }

    std::vector<int> maxima;
    std::vector<int> minima;
    std::cout << "Pairs:\n";
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")\n";
            maxima.push_back(pairs[i].second);
            minima.push_back(pairs[i].first);
    }

    sortMaxima(maxima);

    std::cout << "Maxima:\n";
    for (size_t i = 0; i < maxima.size(); i++) {
        std::cout << maxima[i] << " ";
    }
    std::cout << std::endl;

    size_t index = 0;
    std::cout << "minima : " << minima[0] << std::endl;
    while (index < minima.size()) {
        int target = minima[index];  // Élément à insérer

        // Utiliser std::lower_bound pour trouver la position d'insertion
        std::vector<int>::iterator pos = std::lower_bound(maxima.begin(), maxima.end(), target);

        // Insérer l'élément à la position trouvée
        maxima.insert(pos, target);

        index++;
    }


    // Afficher les éléments du deque après insertion
    for (size_t i = 0; i < maxima.size(); i++) {
        std::cout << maxima[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}