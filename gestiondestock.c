#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

//varibales de color
#define WHT "\e[0;37m"
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;95m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define BWH "\e[4;37m"
#define CR "\e[0m"


int main() {
    const int MAX = 500; //maximum de livres

    char titre[MAX][500]; //pour titre
    char auteur[MAX][500]; // pour auteur
    float prix[MAX]; // pour prix
    int quantite[MAX]; // pour quntite
    int total = 0; // le total de stock 
    int choice; // le choix de menu
    char search[500]; // le variable de recherche
    int i, j, new, stock = 0; // varibales de les boucles et le mettre a jour et total de stock

    do{ //menu
        printf(BMAG"\n\t***** MENU *****\n"CR);
        printf(BWHT"1.Ajouter un livre au stock.\n");
        printf("2.Afficher tous les livres disponibles.\n");
        printf("3.Rechercher un livre par son titre.\n");
        printf("4.Mettre a jour la quantite d'un livre.\n");
        printf("5.Supprimer un livre du stock.\n");
        printf("6.Afficher le nombre total de livres en stock.\n");
        printf(BRED"7.Quitter.\n");
        printf(BWH"Entrer un nombre: "CR);
        
        if (scanf("%d", &choice) != 1) {
            printf(BRED"\nEntree invalide.\n");
            sleep(1);
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice){
            case 1: //ajouter un stock
                if (total < MAX){

                    printf(BYEL"\nTitre de livre: ");
                    fgets(titre[total], sizeof(titre[total]), stdin);
                    titre[total][strcspn(titre[total], "\n")] = '\0';
                    
                    printf(BYEL"\nAuteur de livre: ");
                    fgets(auteur[total], sizeof(auteur[total]), stdin);
                    auteur[total][strcspn(auteur[total], "\n")] = '\0';

                    printf(BYEL"\nPrix de livre: ");
                    while (scanf("%f", &prix[total]) != 1) {
                        printf(BRED"\nEntree invalide." BYEL" Entrer un prix valide: ");
                        while (getchar() != '\n');}
                    printf(BYEL"\nQuantite de livre: ");
                    while (scanf("%d", &quantite[total]) != 1) {
                        printf(BRED"\nEntree invalide." BYEL" Entrer un prix valide: ");
                        while (getchar() != '\n');}

                    printf(BGRN"\nCette operation est un succes. \n");

                    total++;sleep(2);break;}
                else {
                    printf(BRED"\nLe stock maximum est atteint. \n");sleep(2);break;}

            case 2: //afficher le stock
                for (i = 0; i < total; i++){
                    printf(BYEL"\n%d.Titre: %s , Auteur: %s "BWHT"|| "BGRN"Prix: %.2f DH, Quantite: %d", i+1,
                    titre[i], auteur[i], prix[i], quantite[i]);}
                if (total == 0){
                    printf(BRED"Il n y a pas de stock");}sleep(2);break;

            case 3: // search for stock
                printf(BYEL"\nEntrez le titre du livre a rechercher: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';

                for (i = 0; i < total; i++) {
                  if (strcmp(titre[i], search) == 0) {
                    printf(BGRN"\nLe livre existe " BYEL ": Titre: %s, Auteur: %s "BWHT"|| "BGRN"Prix: %.2f, Quantite: %d\n", titre[i], auteur[i], prix[i], quantite[i]);
                    sleep(2);
                    break;}}

                if (i == total) {
                    printf(BRED"\nLe livre nexiste pas.\n");
                    sleep(1);
                    break;}break;

            case 4: //update stock
                printf(BYEL"Entrez le titre du livre a mettre a jour: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';

                for (i = 0; i < total; i++) {
                    if (strcmp(titre[i], search) == 0) {
                        printf(BYEL"Entrez la nouvelle quantite: ");
                        scanf("%d", &new);
                        getchar();
                        quantite[i] = new;
                        printf(BGRN"Quantite mise a jour.\n");
                        sleep(1);break;}}
                    
                if (i == total) {
                    printf(BRED"\nLe livre nexiste pas.\n");
                    sleep(1);}break;

            case 5: //delete
                printf(BYEL"Entrez le titre du livre a supprimer: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';

                for (i = 0; i < total; i++) {
                    if (strcmp(titre[i], search) == 0) {
                        for (j = i; j < total - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];}
                        total--;
                        printf(BRED"Livre supprime.\n");}}

                if (i == total) {
                    printf(BRED"Le livre nexiste pas.\n");}sleep(1);break;

            case 6://show stock
                for (i = 0; i < total; i++) {
                    stock += quantite[i];}

                printf(BYEL"Nombre total de livres en stock: %d\n"BCYN, stock);
                printf(BYEL"Les quantites de tous les livres: %d\n"BCYN, total);sleep(2);break;
        default:
            break;}} while (choice !=7);

    printf(BMAG"\nPasse une bonne journee!"WHT);
    
    return 0;
}
