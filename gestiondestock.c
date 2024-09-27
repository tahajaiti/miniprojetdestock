#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


int main() {

    const int MAX = 100;

    char titre[MAX][50];
    char auteur[MAX][50];
    float prix[MAX];
    int quantite[MAX];
    int total = 0;
    int choice;
    char search;

    do{
        printf("\n\033[1;34m ***** MENU ***** \033[0m\n");
        printf("\033[1;36m1.Ajouter un livre au stock.\n");
        printf("2.Afficher tous les livres disponibles.\n");
        printf("3.Rechercher un livre par son titre.\n");
        printf("4.Mettre a jour la quantite d'un livre.\n");
        printf("5.Supprimer un livre du stock.\n");
        printf("6.Afficher le nombre total de livres en stock.\033[0m\n");
        printf("\033[1;31m7.Quitter.\n\033[0m");
        scanf("%d", &choice);
        
        printf("hi");

        switch (choice){
            case 1:
                if (total < MAX){
                    printf("\ntitre de livre: ");
                    scanf("%49s", &titre[total]);
                    printf("\nauteur de livre: ");
                    scanf("%49s", &auteur[total]);
                    printf("\nprix de livre: ");
                    scanf("%f", &prix[total]);
                    printf("\nquantite de livre: ");
                    scanf("%d", &quantite[total]);

                    printf("\n\033[1;32mCette operation est un succes. \n\033[0m");

                    total++;sleep(2);}
                else {
                    printf("\n\033[1;31mLe stock maximum est atteint. \n\033[0m");sleep(2);}break;
            case 2:
                for (int i = 0; i < total; i++){
                    printf("\n%d.Titre: %s , Auteur: %s , Prix: %.2f, Quantite: %d\n", i+1,
                    titre[i], auteur[i], prix[i], quantite[i]);
                }sleep(3); break;
            case 3:
                printf("Entrez le titre du livre a rechercher: ");
                scanf("%s", &titre);

        default:
            printf("\n\033[1;31mChoix invalide. Veuillez essayer à nouveau.\033[0m\n");
            sleep(1);
            break;
        }

    } while (choice !=7);
    
    return 0;
}
