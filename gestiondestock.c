#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


int main() {

    const int MAX = 100;

    char titre[MAX][100];
    char auteur[MAX][100];
    float prix[MAX];
    int quantite[MAX];
    int total = 0;
    int choice;
    char search[100];
    int i,new;

    do{
        printf("\n\033[1;34m ***** MENU ***** \033[0m\n");
        printf("\033[1;36m1.Ajouter un livre au stock.\n");
        printf("2.Afficher tous les livres disponibles.\n");
        printf("3.Rechercher un livre par son titre.\n");
        printf("4.Mettre a jour la quantite d'un livre.\n");
        printf("5.Supprimer un livre du stock.\n");
        printf("6.Afficher le nombre total de livres en stock.\033[0m\n");
        printf("\033[1;31m7.Quitter.\n\033[0m");
        printf("\033[1;33mEntrer un nombre: \033[0m");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n\033[1;31mEntrée invalide. \033[0m\n");
            sleep(1);
            while (getchar() != '\n');
            continue;}

        switch (choice){
            case 1: //ajouter un stock
                if (total < MAX){
                    getchar();

                    printf("\ntitre de livre: ");
                    fgets(titre[total], 100, stdin);
                    titre[total][strcspn(titre[total], "\n")] = '\0';
                    
                    printf("\nauteur de livre: ");
                    fgets(auteur[total], 100, stdin);
                    auteur[total][strcspn(auteur[total], "\n")] = '\0';

                    printf("\nprix de livre: ");
                    while (scanf("%f", &prix[total]) != 1) {
                        printf("\n\033[1;31mEntree invalide. entrer un prix valide: \033[0m");
                        while (getchar() != '\n');
                    }
                    printf("\nquantite de livre: ");
                    while (scanf("%d", &quantite[total]) != 1) {
                        printf("\n\033[1;31mEntree invalide. entrer un quntite valide: \033[0m");
                        while (getchar() != '\n');
                    }

                    printf("\n\033[1;32mCette operation est un succes. \n\033[0m");

                    total++;sleep(2);}
                else {
                    printf("\n\033[1;31mLe stock maximum est atteint. \n\033[0m");sleep(2);}break;
            case 2: //afficher le stock
                for (int i = 0; i < total; i++){
                    printf("\n\033[1;33m%d.Titre: %s , Auteur: %s , Prix: %.2f DH, Quantite: %d\n\033[0m", i+1,
                    titre[i], auteur[i], prix[i], quantite[i]);
                }sleep(3); break;
            case 3: // search for stock
                getchar();

                printf("\nEntrez le titre du livre a rechercher: ");
                fgets(search, 100, stdin);
                search[strcspn(search, "\n")] = '\0';

                for (i = 0; i < total; i++) {
                  if (strcmp(titre[i], search) == 0) {
                    printf("\n\033[1;33mLivre trouve - Titre: %s, Auteur: %s, Prix: %.2f, Quantite: %d\n\033[0m", titre[i], auteur[i], prix[i], quantite[i]);
                    sleep(2);
                    break;
                    }
                }
                if (i == total) {
                    printf("\n\033[1;33mle livre nexiste pas.\n\033[0m");
                    sleep(1);
                    break;}
            case 4: //update stock
                printf("Entrez le titre du livre a mettre a jour: ");
                fgets(search, 100, stdin);
                search[strcspn(search, "\n")] = '\0';

                for (i = 0; i < total; i++) {
                    if (strcmp(titre[i], search) == 0) {
                        printf("Entrez la nouvelle quantite: ");
                        scanf("%d", &new);
                        getchar();
                        quantite[i] = new;
                        printf("Quantite mise a jour.\n");
                        break;
                    }
                }
                if (i == total) {
                        printf("\n\033[1;33mle livre nexiste pas.\n\033[0m");
                        sleep(1);}break;
        default:
            break;
        }

    } while (choice !=7);
    
    return 0;
}
