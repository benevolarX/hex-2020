// hex-2020.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Hex.h"

using namespace std;
using namespace hex;


int main()
{
    auto entier = Digit();
    auto reel = Number();
    auto jean = Regex("^jean$");
    auto minuscule = Lower();
    auto n_ieme_lettre = AtN('A', 1);

    auto sw = HexSwitch<std::string>();
    sw.add_case(&entier); // 0
    sw.add_case(&reel); // 1
    sw.add_case(&jean); // 2
    sw.add_case(&minuscule); // 3
    sw.add_case(&n_ieme_lettre); // 4

    std::string s = "MAman";
    switch (sw(s))
    {
    case 0 :
        cout << "entier entre guillemet";
        break;
    case 1 :
        cout << "reel entre guillemet";
        break;
    case 2 :
        cout << "mot jean";
        break;
    case 3 :
        cout << "pas de majuscule";
        break;
    case 4 :
        cout << "la 2eme lettre est A (majuscule)";
        break;
    default :
        cout << "aucun des autres cas";
        break;
    }

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
