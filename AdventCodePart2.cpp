// AdventCode.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

bool isSafe(const std::vector<int>& levels) {
    if (levels.size() < 2) return true;

    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < levels.size(); i++) {
        int diff = levels[i] - levels[i - 1];
        int absDiff = std::abs(diff);

        // je vérifie la valeur de différence absolue
        if (absDiff < 1 || absDiff > 3) {
            return false;
        }

        // mise à jour
        if (diff > 0) decreasing = false;
        if (diff < 0) increasing = false;

        // Les deux sont false
        if (!increasing && !decreasing) {
            return false;
        }
    }

    return increasing || decreasing;
}
bool isSafeWithRemoval(const std::vector<int>& levels) {
	//Si c'est déjà safe, pas besoin de suppression
    if (isSafe(levels)) {
        return true;
    }

    // 1 suppression max
    for (size_t i = 0; i < levels.size(); i++) {
        std::vector<int> levels_modifies;

        for (size_t j = 0; j < levels.size(); j++) {
            if (j != i) {
				levels_modifies.push_back(levels[j]); // je copie tout sauf l'élément à l'index i
            }
        }

        if (isSafe(levels_modifies)) {
            return true;  // Safe avec exactement 1 suppression
        }
    }

    return false;  // Pas safe même avec une suppression
}
int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Ouverture ratee" << std::endl;
        return 1;
    }

    std::string line;
    int safeCount = 0;

    while (std::getline(file, line)) {
        std::vector<int> levels;
        std::stringstream ss(line);
        int num;

        while (ss >> num) {
            levels.push_back(num);
        }

        if (isSafe(levels)) {
            safeCount++;
        }
        
        // Vérification avec une suppression possible
		
        /*if (isSafeWithRemoval(levels)) {
            safeCount++;
		}
        */
        
    }

    std::cout << safeCount << std::endl;
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
