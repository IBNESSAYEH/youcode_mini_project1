#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// The menu of our app
int menu() {
    int choix;
    printf("==================================================\n");
    printf("Menu d'application \n");
    printf("==================================================\n");
    printf("[1] afficher les donnees \n");
    printf("[2] ajouter une donnee\n");
    printf("[3] rechercher sur une donnee\n");
    printf("[4] supprimer une donnee\n");
    printf("[5] supprimer les donnees repetes\n");
    printf("[6] genere le wordlist\n");
    printf("[7] genere le wordlist dans un fichier.txt \n");
    printf("[8] afficher les donnees de type entier \n");
    printf("[] deconnecter \n");
    printf("==================================================\n");
    printf("pour une bonne experience sur notre app \n c'est mieux de donner le max des info sur vous \n cela nous donne plus de flexibilite pour recommender pour vous\n tous ce que vous aimez \n");
    printf("==================================================\n");
    printf("<<<<pour une meilleur experience sur notre application>>>>> \n <<<<< c'est mieux d'ajouter plus du detaille sur vous .>>>>>> \n ");
    printf("entrer votre choix : \n");
    scanf("%d", &choix);
    return choix;
}

// Adding a new data to our victim
void ajouter_donnee(char request_nouveau_info[][60], char response_nouveau_info[][100], int *nombre_de_donnees) {
    char choix_pour_lajout_du_donnee;

    do {
        printf("entrer le %s  : \n ", request_nouveau_info[*nombre_de_donnees]);
        scanf("%s", response_nouveau_info[*nombre_de_donnees]);
        (*nombre_de_donnees)++;
        printf("tapez --y-- si tu veux ajouter une autre info pour une meilleur experience  : \n ");
        scanf(" %c", &choix_pour_lajout_du_donnee);
    } while (choix_pour_lajout_du_donnee == 'y');
}

// Displaying the data
void affichage_donnees(char response_nouveau_info[][100], int nombre_de_donnees) {
    for (int i = 0; i < nombre_de_donnees; i++) {
        puts(response_nouveau_info[i]);
    }
}

//rechercher des donner
void rechercher_donnees(char request_nouveau_info[][60],char response_nouveau_info[][100], int nombre_de_donnees) {
    char find_inf[20];
    bool trouver=false;
    printf("entrer l'info que tu veux trouver");
    scanf("%s",&find_inf);
    for (int i = 0; i < nombre_de_donnees; i++) {
            if(strcmp(response_nouveau_info[i], find_inf) == 0){
                trouver=true;
                printf("%s\n",request_nouveau_info[i]);
                printf("%s\n",response_nouveau_info[i]);
            }

    }
}


//supprimer des donner
void supprimer_donnees(char request_nouveau_info[][60],char response_nouveau_info[][100], int nombre_de_donnees) {
    char find_inf[20];
    bool trouver=false;
    printf("entrer l'info que tu veux supprimer");
    scanf("%s",find_inf);
    for (int i = 0; i < nombre_de_donnees; i++) {
            if(strcmp(response_nouveau_info[i], find_inf) == 0){
                trouver=true;
                int k;
                for (int j = 0; j < nombre_de_donnees-1; j++) {

                    strcpy(request_nouveau_info[j], request_nouveau_info[j+1]);
                strcpy(response_nouveau_info[j], response_nouveau_info[j+1]);

                }
                   strcpy(request_nouveau_info[nombre_de_donnees - 1], "");
            strcpy(response_nouveau_info[nombre_de_donnees - 1], "");
            nombre_de_donnees--;

            }

    }
}


//supprimer plusieur donner
void supprimer_plusieur_donnees(char request_nouveau_info[][60],char response_nouveau_info[][100], int nombre_de_donnees) {
    char find_inf[20];
    bool trouver=false;
    int nbr_sup;
    printf("entrer le nombre de donner que tu veux supprimer");
    scanf("%d",&nbr_sup);
    int k=0;
    while(k<=nbr_sup){
         printf("entrer l'info que tu veux supprimer");
    scanf("%s",find_inf);
    k++;
    for (int i = 0; i < nombre_de_donnees; i++) {
            if(strcmp(response_nouveau_info[i], find_inf) == 0){
                trouver=true;
                int k;
                for (int j = 0; j < nombre_de_donnees-1; j++) {

                    strcpy(request_nouveau_info[j], request_nouveau_info[j+1]);
                strcpy(response_nouveau_info[j], response_nouveau_info[j+1]);


                }
                 printf("il etait supprimer avec succee\n");
                   strcpy(request_nouveau_info[nombre_de_donnees - 1], "");
            strcpy(response_nouveau_info[nombre_de_donnees - 1], "");
            nombre_de_donnees--;

            }

    }
    }

}


//generer le wordlist
void word_list(char response_nouveau_info[][100],int nombre_de_donnees) {
    for (int i = 0; i < nombre_de_donnees; i++) {
         for (int j = 0; j < nombre_de_donnees; j++) {
            printf("%s%s\n",response_nouveau_info[i],response_nouveau_info[j]);
        }
    }
}


int main() {
    int choix;
    char request_nouveau_info[][60] = {"car", "car", "car", "nom", "prenom", "age", "email", "phone", "nom du pere", "nom du mere", "couleur prefere", "metier", "hobies", "ville", "best friend name", "votre meilleur sport"};
    char response_nouveau_info[100][100] = { "&", "#", "@" };
    int nombre_de_donnees = 3;

    do {
        choix = menu();
        switch (choix) {
            case 1:
                affichage_donnees(response_nouveau_info, nombre_de_donnees);
                break;
            case 2:
                ajouter_donnee(request_nouveau_info, response_nouveau_info, &nombre_de_donnees);
                break;
            case 3: rechercher_donnees(request_nouveau_info, response_nouveau_info,  nombre_de_donnees);
                break;
            case 4: supprimer_donnees(request_nouveau_info, response_nouveau_info,  nombre_de_donnees);
                break;
            case 5:supprimer_plusieur_donnees(request_nouveau_info, response_nouveau_info,  nombre_de_donnees);
                break;
            case 6: word_list(response_nouveau_info,nombre_de_donnees);
                break;

        }
    } while (choix <= 6 && choix >= 1);

    return 0;
}
