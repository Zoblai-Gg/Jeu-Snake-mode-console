//
// Created by zoblaigg on 28/11/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gestion_clavier.h"
#include "snake_affichage.h"
#include "snake_mouve.h"
#define BRIQUE 'x'
#define POMME 'o'
#define SNAKE_HEAD '@'
#define SNAKE_BODY '*'
#define VIDE '1'
#define TRUE 1
#define FALSE 0
#define STARTED 1
#define BESTS_SCORES 2
#define SETTINGS 3
#define ABOUT 4
#define LEAVE 5
#define MAX 10
/*
typedef struct  {
    int x;
    int y;

}Coord ;*/

char ** Fonct_allocation(int ligne, int colone);
void Fonct_Free(char **map,int colone);
void Fonct_Create_Map(char **map, int ligne, int colone, Coord *food);
void FonctionScore(int scoreplayer);



int main (void)
{

    srand(time(NULL));
    const int ligne =25, colone =25, t_body = ligne*colone;
    char ** map = NULL;
    char carac,pullup; int valeur;
    Coord food = { 6,10}, *body;
    FILE *fichier =NULL;

    do {
        Fonct_welcome();
        scanf(" %c",&carac);
        //revoir la partie
    }while(carac != 'A' && carac != 'a');

    system("clear");

    do {

        Fonct_menu();
        scanf(" %d",&valeur);

        if(valeur == STARTED){

            do{
                int my_score =0;
                map = Fonct_allocation(ligne ,colone);
                Fonct_Create_Map(map,ligne,colone,&food);
                Fonct_Snake_Mouve(map,&food,ligne,colone,&my_score);
                printf("\n  vous avez fait un score de : %d Brovo\n",my_score);
                FonctionScore(my_score);
                Fonct_Free(map,colone);
                map =NULL;
                printf("\n Voulez vous reprendre ? o/n\n");
                scanf(" %c",&pullup);

            }while( pullup == 'o' || pullup == 'O' );

            carac = 'a';
        }
        else if( valeur == BESTS_SCORES){

            int score[3];
            char joueur1[MAX],joueur2[MAX],joueur3[MAX];
            do {
                fichier = fopen("score.txt", "r+");
                if( fichier != NULL)
                {
                    fscanf(fichier, "%s %d %s %d %s %d", joueur1, &score[0], joueur2, &score[1], joueur3, &score[2]);

                    printf("%s score :%d\n", joueur1, score[0]);
                    printf("%s score :%d\n", joueur2, score[1]);
                    printf("%s score :%d\n", joueur3, score[2]);

                    fclose(fichier);
                }

                printf("\n Appuyez sur o pour allez au menu \n");
                scanf(" %c",&pullup);
            }while( pullup != 'o' && pullup != 'O' );
        }
        else if( valeur == SETTINGS){
            do{
                printf("\nCe parametre n'est pas disponible pour le moment \n");
                printf("\n Appuyez sur o pour allez au menu \n");
                scanf(" %c",&pullup);
            }while( pullup != 'o' && pullup != 'O' );
        }
        else if( valeur == ABOUT){
            carac = 'p';
        }
        else if( valeur == LEAVE){
            carac = 'p';
        }

    }while( carac != 'p');

    return 0;
}


void Fonct_Free(char **map,int colone)
{
    int i;
    for(i = 0 ;i < colone; i++){

       free(map[i]);
    }

    free(map);

    return;
}





char ** Fonct_allocation(int ligne, int colone)
{
    char ** map  =NULL;
    int i;
    map =(char **)malloc(ligne*sizeof(char*));
    if(map == NULL){
        printf("Erreur malloc Fonct_allocation \n");
        exit(EXIT_FAILURE);
    }

    for(i = 0 ;i < colone; i++){

        map[i] =(char *)malloc(colone*sizeof(char));
    }

    return map;
}
void Fonct_Create_Map(char **map, int ligne, int colone, Coord *food)
{
    int i,j;

    for(i = 0; i < ligne; i++) {

        for(j = 0; j < colone; j++) {
            map[i][j] = VIDE;
        }
    }

    for(i = 0; i < colone; i++) {
        // murs verticaux
        map[i][0] = BRIQUE;
        map[i][colone - 1] = BRIQUE;
    }
    for(i = 0; i < ligne; i++) {
        // murs horizontaux
        map[0][i] = BRIQUE;
        map[ligne - 1][i] = BRIQUE;
    }

    map[food->x][food->y] = POMME;


    return;
}



void FonctionScore(int scoreplayer)
{
   FILE *fichier = NULL;
    int score[3];
    char joueur1[MAX],joueur2[MAX],joueur3[MAX];

   fichier = fopen("score.txt", "r+");
   if(fichier != NULL){

       fscanf(fichier, "%s %d %s %d %s %d", joueur1, &score[0], joueur2, &score[1], joueur3, &score[2]);
     fclose(fichier);
   }

    fichier = fopen("score.txt", "w+");
    if(fichier != NULL){

        if(scoreplayer >= score[0]){

            printf("Veillez saisir votre Nom :");
            scanf(" %s",joueur1); score[0] = scoreplayer;
            rewind(fichier);
            fprintf(fichier, "%s %d\n%s %d\n%s %d", joueur1, score[0], joueur2, score[1], joueur3, score[2]);
            printf("\nBravo %s, vous etes 1e sur la liste des meilleurs score\n",joueur1);

            return;

        }else if(scoreplayer >= score[1]){
            printf("Veillez saisir votre Nom :");
            scanf(" %s",joueur2); score[1] = scoreplayer;
            rewind(fichier);
            fprintf(fichier, "%s %d\n%s %d\n%s %d", joueur1, score[0], joueur2, score[1], joueur3, score[2]);
            printf("\nBravo %s, vous etes 2e sur la liste des meilleurs score\n",joueur2);

            return;
        }else if(scoreplayer >= score[2]){
            printf("Veillez saisir votre Nom :");
            scanf(" %s",joueur3); score[2] = scoreplayer;
            rewind(fichier);
            fprintf(fichier, "%s %d\n%s %d\n%s %d", joueur1, score[0], joueur2, score[1], joueur3, score[2]);
            printf("\nBravo %s, vous etes 3e sur la liste des meilleurs score\n",joueur3);

            return;
        }

        fclose(fichier);
    }
    printf("\nMalheureusement vous n'avez battu aucun score ! Dommage !\n");

    return;
}








