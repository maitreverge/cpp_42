#include <iostream>
using namespace std;

// ! IMPORTANT : les tableaux sont TOUJOURS passes par reference
// ! Il faut egalement passer la taille du tableau
void fonction(double tableau[], int tailleTableau)
{
    //…
}

int main()
{
   int meilleurScore[5];       //Déclare un tableau de 5 int 

   double anglesTriangle[3];   //Déclare un tableau de 3 double

	// ! IMPORTANT : il est VIVEMENT CONSEILLE d'utliser des constantes
	// ! dans la taille d'un tableau 
	int const tailleTableau(20);   //La taille du tableau
	double anglesIcosagone[tailleTableau];
   return 0;
}