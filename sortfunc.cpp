#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Fonction de comparaison utilisée pour trier les mots dans l'ordre croissant
bool compareWordsAscending(const string& a, const string& b) {
    return a < b;
}

// Fonction de comparaison utilisée pour trier les mots dans l'ordre décroissant
bool compareWordsDescending(const string& a, const string& b) {
    return a > b;
}

int main(int argc, char** argv) {
    // Vérifie qu'un argument a été passé en ligne de commande
    if (argc < 2) {
        cerr << "Utilisation : " << argv[0] << " [asc|desc] [remove_duplicates]" << endl;
        return 1;
    }

    // Détermine l'ordre de tri à partir de l'argument passé en ligne de commande
    bool (*compareFunction)(const string&, const string&);
    if (string(argv[1]) == "asc") {
        compareFunction = &compareWordsAscending;
    }
    else if (string(argv[1]) == "desc") {
        compareFunction = &compareWordsDescending;
    }
    else {
        cerr << "Utilisation : " << argv[0] << " [asc|desc] [remove_duplicates]" << endl;
        return 1;
    }

    // Lit les mots à partir de l'entrée standard
    vector<string> words;
    string word;
    while (cin >> word) {
        words.push_back(word);
    }

    // Trie les mots
    sort(words.begin(), words.end(), compareFunction);

    // Supprime les doublons, si demandé
    if (argc > 2 && string(argv[2]) == "remove_duplicates") {
        words.erase(unique(words.begin(), words.end()), words.end());
    }

    // Affiche les mots triés
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
