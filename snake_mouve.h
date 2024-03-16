//
// Created by zoblaigg on 03/12/22.
//

#ifndef SNAKE_PROJECT_SNAKE_MOUVE_H
#define SNAKE_PROJECT_SNAKE_MOUVE_H

#define BRIQUE 'x'
#define POMME 'o'
#define SNAKE_HEAD '@'
#define SNAKE_BODY '*'
#define VIDE '1'
#define TRUE 1
#define FALSE 0

typedef struct  {
    int x;
    int y;

}Coord ;

char Fonct_Mouve(char **map,Coord *food,int ligne,int colone,Coord *head,int val,Coord *body,int *increase,char *block,int *score);
void Fonct_Snake_Mouve(char **map,Coord *food,int ligne,int colone,int *my_score);
void Fonct_Can_mouve(char **map,Coord head, int mouve,Coord *body,int verif,int *increase);
int Fonct_verif_mouv(char **map,Coord head,Coord *food,int ligne,int colone,int *score);
void Fonct_Grow_Body(Coord *body,int *increase);
void Fonct_Bloc(char *block,char *key);
void Fonct_Reload_food(char **map,Coord *food,int ligne,int colone);
void Fonct_Affiche_Map(char **map, int ligne, int colone,Coord *food,Coord head);


#endif //SNAKE_PROJECT_SNAKE_MOUVE_H
