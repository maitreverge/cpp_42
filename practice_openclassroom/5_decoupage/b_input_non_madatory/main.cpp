
#include <iostream>

using namespace std;

/*
! Dans cet exemple, nous devons renseigner OBLIGATOIREMENT les heures, les minutes, et les
! secondes car c'est ainsi que le prototypage des fonctions est utilise
*/
int nombreDeSecondes(int heures, int minutes = 0, int secondes = 0);
// int nombreDeSecondes(int heures, int minutes, int secondes);

// Main
int main()
{
    cout << nombreDeSecondes(1) << endl;

    return 0;
}

// Définition de la fonction
int nombreDeSecondes(int heures, int minutes, int secondes)
{
    int total = 0;

    total = heures * 60 * 60;
    total += minutes * 60;
    total += secondes;

    return total;
}

///////////////////////////////////////////////////////////////////////////////



// ! Ce prototypage inclus que des valeurs peuvent etre renseignees par default
// ! si ces dernieres ne sont pas renseignees
// int nombreDeSecondes(int heures, int minutes = 0, int secondes = 0);

//!  Important : les parametres facultatifs seront toujours places a la fin, jamais au debut 