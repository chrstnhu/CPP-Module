#include <iostream>
# include <cstring>
# include <string>

static bool validateExponentPart(const std::string& input, int& i, size_t ePos, size_t length) {
    bool hasDotBeforeE = false;

    // La partie avant 'e' doit être un nombre valide avec un point
    for (int j = i; j < ePos; j++) {
        if (input[j] == '.') {
            if (hasDotBeforeE) {
                return false;  // Il ne doit y avoir qu'un seul point avant 'e'
            }
            hasDotBeforeE = true;
        } else if (!std::isdigit(input[j])) {
            return false;  // Un caractère autre qu'un chiffre ou un point est invalide
        }
    }

    // Après 'e', il doit y avoir un exposant valide (optionnellement précédé d'un signe)
    i = ePos + 1;
    if (input[i] == '+' || input[i] == '-') {
        i++;  // Ignorer le signe de l'exposant
    }

    // Vérifier que l'exposant est constitué uniquement de chiffres
    if (i == length) {
        return false;  // Il n'y a rien après 'e'
    }

    for (; i < length; i++) {
        if (!std::isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

static bool isFloat(const std::string &input) {
    if (input.empty()) {
        return false;
    }

    int i = 0;
    bool hasSign = false;
    bool hasDot = false;

    // Vérifier si le premier caractère est un signe (+ ou -)
    if (input[0] == '+' || input[0] == '-') {
        hasSign = true;
        i++;
    }

    size_t length = input.length();
	if (input[length - 1] == 'f' || input[length - 1] == 'F') {
		length--;
	}

    // Recherche de 'e' ou 'E' pour la notation exponentielle
    bool hasExponent = false;
	size_t ePos = input.find_first_of("eE", i);  // Chercher la position de 'e' ou 'E'
    
    if (ePos != std::string::npos) {
        if (!validateExponentPart(input, i, ePos, length)) {
			return false;
		}
		hasExponent = true;
    } 
	else {
        // Si 'e' n'est pas présent, il faut simplement vérifier que la partie avant est un nombre flottant valide
        for (int j = i; j < length; j++) {
            if (input[j] == '.') {
                if (hasDot) {
                    return false;  // Il ne doit y avoir qu'un seul point dans la mantisse
                }
                hasDot = true;
            } else if (!std::isdigit(input[j])) {
                return false;  // Un caractère invalide
            }
        }
    }
    return hasDot || hasExponent;
}

int main () {
    // Cas pour float et double
    std::string inputs[] = {
        "-.3f",        // Float valide avec un point
        "3.3E-2f",     // Float valide avec exponentielle
        "0.3F",        // Float avec suffixe F
        "3.0f",        // Float avec point mais sans exponentielle
        "+3.14f",      // Float positif
        "-3.14f",      // Float négatif
        "3.14E2f",     // Float avec exponentielle
        "1e10f",       // Float avec exponentielle sans point
        "0f",          // Float simple, juste un 0
        "0.0f",        // Float simple, 0 avec un point
        "1.23e+10f",   // Float avec exponentielle et signe
        "1.23e-10F",   // Float avec exponentielle et signe négatif
        "1.23f",       // Float normal sans exponentielle
        "1e+10",       // Double valide sans suffixe 'f'
        "1e-10",       // Double valide sans suffixe 'f'
        "3.14E2",      // Double valide avec exponentielle
        "3.14159",     // Double sans suffixe, juste un nombre
		"3E2f",        // Valide
        "abc",         // Invalide, chaîne non numérique
        "3.14abc",     // Invalide, contient des lettres
        "3.14e2abc",   // Invalide, contient des lettres après l'exposant
        "3.14.2",      // Invalide, deux points
        "3..14",       // Invalide, deux points
        "e3.14",       // Invalide, 'e' placé au début
        "3.14E",       // Invalide, exponentielle mal formée
        "3.14fE3",     // Invalide, 'E' après le 'f'
    };

    for (const std::string& input : inputs) {
        std::cout << "Testing input: " << input << std::endl;
        if (isFloat(input)) {
            std::cout << "The input is a float" << std::endl;
        } else {
            std::cout << "XX The input is not a float" << std::endl;
        }
        std::cout << "=======================================" << std::endl;
    // }

	float x = 3E2f;
	std::cout << x << std::endl;
    return 0;
}