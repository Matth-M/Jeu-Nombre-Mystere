#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int jeuPlusOuMoins
()
{
    int continuerPartie = 1;
    while(continuerPartie)
    {
        printf("\n\n=== Nouvelle partie ===\n\n");
        int niveauDifficulte = 0;
        while(niveauDifficulte<1 || niveauDifficulte>4)
        {
            printf("Choisissez le niveau de difficulté\n1. Facile\n2. Moyen\n3. Difficile\n4. Impossible (t'y es fou)\n");
            scanf("%d", &niveauDifficulte);
        }

        //Choix des limites
        int min = 1, max = 100; //limites par default
        switch(niveauDifficulte)
        {
            case 1:
                max = 10;
                break;
            case 2:
                max = 100;
                break;
            case 3:
                max = 10000;
                break;
            case 4:
                max = 10000000000000;
            default:
                break;
        }

        //génération nombre mystere
        srand(time(NULL));
        int nombreMystere = (rand() % (max - min + 1)) + min;
        printf("Nombre mystere compris entre %d et %d\n", min, max);

        int nbDevine = 0;
        unsigned int compteur = 0;

        do //Recherche du nombre
        {
            printf("Quel est le nombre mystere ? ");
            scanf("%d", &nbDevine);
            if(nbDevine<nombreMystere)
                printf("C'est plus !\n");
            else if(nbDevine > nombreMystere)
                printf("C'est moins !\n");
            compteur ++;

        } while (nbDevine != nombreMystere);

        //fin de partie
        if(compteur >1 && compteur < 5)
            printf("\nBravo vous avez trouve le nombre mystere en %d coups ! Belle perf !\n\nVoulez faire une autre partie ?\n1. Oui !\n0. Non...\n", compteur);
        else if(compteur == 1)
            printf("\nBravo vous avez trouve le nombre mystere en %d coup ! Savez-vous lire dans les pensees d'un ordi ?\n\nVoulez faire une autre partie ?\n1. Oui !\n0. Non...\n", compteur);
        else if(compteur >= 5)
            printf("\nBravo vous avez trouve le nombre mystere en %d coups ! Vous ferez mieux la prochaine fois ;)\n\nVoulez faire une autre partie ?\n1. Oui !\n0. Non...\n", compteur);
        // rejouer partie ?
        scanf("%d", &continuerPartie);
    }
    return 0;
}


