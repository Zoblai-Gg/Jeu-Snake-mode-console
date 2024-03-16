//
// Created by zoblaigg on 03/12/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "snake_mouve.h"
#include "gestion_clavier.h"
#include "snake_affichage.h"

void Fonct_Reload_food(char **map,Coord *food,int ligne,int colone)
{
    do{
        food->x = (rand()%(colone-2));
        food->y = (rand()%(ligne-2));

    }while(map[food->x][food->y] == BRIQUE ||
           map[food->x][food->y] == SNAKE_HEAD ||
           map[food->x][food->y] == SNAKE_BODY);

    map[food->x][food->y] = POMME;


    return ;
}

void Fonct_Affiche_Map(char **map, int ligne, int colone, Coord *food,Coord head){

    int i,j;
    for(i = 0; i < ligne; i++) {
        for(j = 0; j < colone; j++) {
            if(map[i][j] == BRIQUE ){
                printf("%c ",map[i][j]);
            }
            else if(food->x == i && food->y == j && map[i][j] == POMME){
                printf("%c ",map[i][j]);
            }
            else if(map[i][j] == SNAKE_BODY){
                printf("%c ",map[i][j]);
            }
            else if(head.x == i && head.y == j){
                printf("%c ",map[i][j]);
            }
            else{
                printf("  ");

            }
        }
        printf("\n");
    }

    return;
}

void Fonct_Bloc(char *block,char *key)
{

    if (*key == 'Q' || *key == 'q') {

        if(*block  == 'D' || *block == 'd' ){

            *key = NO_KEY;
            return;
        }
    } else if (*key == 'Z' || *key == 'z') {
        if(*block  == 'S' || *block == 's' ){

            *key = NO_KEY;
            return;
        }
    } else if (*key == 'S' || *key == 's') {
        if(*block  == 'Z' || *block == 'z' ){

            *key = NO_KEY;
            return;
        }
    } else if (*key == 'D' || *key == 'd') {
        if(*block  == 'Q' || *block == 'q' ){

            *key = NO_KEY;
            return;
        }
    }
    else{

        *key = 'p';
    }
    return;
}


void Fonct_Grow_Body(Coord *body,int *increase)
{
    *increase = *increase+1;
    Coord *tmp;

    tmp =(Coord *)realloc(body,(*increase)*sizeof(Coord));
    if(tmp == NULL){
        free(body);
        printf("ERREUR Relloc  dans fonction Fonct_Grow_Body\n");
        exit(EXIT_FAILURE);
    }
    return ;

}

void Fonct_Can_mouve(char **map,Coord head, int mouve,Coord *body,int verif,int *increase)
{
    map[head.x][head.y] = SNAKE_HEAD;

    Coord tmp,base;
    int i, taille ;


    if(verif == 2){

        Fonct_Grow_Body(body,increase);
        taille = *increase-1;

        if (mouve == 1) {

            body[taille].x = head.x;
            body[taille].y = head.y+1;
            map[body[taille].x][body[taille].y] =SNAKE_BODY;
        }
        else if (mouve == 2) {

            body[taille].x = head.x+1;
            body[taille].y =head.y;
            map[body[taille].x][body[taille].y] =SNAKE_BODY;
        }
        else if (mouve == 3) {

            body[taille].x = head.x;
            body[taille].y =head.y-1;
            map[body[taille].x][body[taille].y] =SNAKE_BODY;
        }
        else if (mouve == 4) {

            body[taille].x = head.x-1;
            body[taille].y = head.y;
            map[body[taille].x][body[taille].y] =SNAKE_BODY;
        }
    }
    else
    {
        taille =*increase-1;

        //   printf("\n\n\n\n\n Coor de head x=%d et y =%d et map =%c\n\n\n\n\n",head.x,head.y,map[head.x][head.y]);


        if (mouve == 1) {
            base.x = head.x;
            base.y = head.y+1;
            map[base.x][base.y] =VIDE;

            for (i = taille ; i >=0 ; i--) {

                tmp =body[i];
                map[tmp.x][tmp.y] = map[body[i].x][body[i].y] ;
                body[i]=base;
                map[body[i].x][body[i].y] = SNAKE_BODY;
                base = tmp;
                map[base.x][base.y] = VIDE;
            }
        }
        else if (mouve == 2) {
            base.x = head.x+1;
            base.y =head.y;
            map[base.x][base.y] =VIDE;

            for (i = taille ; i >=0 ; i--) {
                tmp =body[i];
                map[tmp.x][tmp.y] = map[body[i].x][body[i].y] ;
                body[i]=base;
                map[body[i].x][body[i].y] = SNAKE_BODY;
                base = tmp;
                map[base.x][base.y] = VIDE;
            }
        }
        else if (mouve == 3){
            base.x = head.x;
            base.y =head.y-1;
            map[base.x][base.y] =VIDE;
            // printf("\n\n\n\n\n Coor de base x=%d et y =%d et map =%c\n\n\n\n\n",base.x,base.y,map[base.x][base.y]);
            //printf("\n\n\n\n\n Coor de body x=%d et y =%d et map =%c\n\n\n\n\n",body[0].x,body[0].y,map[body[0].x][body[0].y]);


            for (i = taille ; i >=0 ; i--) {

                tmp =body[i];
                map[tmp.x][tmp.y] = map[body[i].x][body[i].y] ;
                body[i]=base;
                map[body[i].x][body[i].y] = SNAKE_BODY;
                base = tmp;
                map[base.x][base.y] = VIDE;
            }
        }
        else if (mouve == 4) {
            base.x = head.x-1;
            base.y = head.y;
            map[base.x][base.y] =VIDE;

            for (i = taille ; i >=0 ; i--) {

                tmp =body[i];
                map[tmp.x][tmp.y] = map[body[i].x][body[i].y] ;
                body[i]=base;
                map[body[i].x][body[i].y] = SNAKE_BODY;
                base = tmp;
                map[base.x][base.y] = VIDE;
            }
        }
    }

    return;

}

int Fonct_verif_mouv(char **map,Coord head,Coord *food,int ligne,int colone,int *score)
{
    int val = 0;

    // prochain emplacement de la tête

    if( map[head.x][head.y] ==  POMME){
        val =2;
        *score = *score +1;
        Fonct_Reload_food(map,food, ligne, colone);
        return val ;
    }
    if( map[head.x][head.y] ==  SNAKE_BODY){

        val = 0;
        return val;
    }
    if( map[head.x][head.y] !=  BRIQUE){
        val = 1;
    }

    return val;
}

void Fonct_Snake_Mouve(char **map,Coord *food,int ligne,int colone,int *my_score)
{
    Coord head = {5,5};
    char key = 'd',block ='d';
    int val,*score = NULL; score = my_score;
    int var_init = 1;
    int *increase = &var_init;
    Coord *body = (Coord *) malloc( var_init*sizeof(Coord));
    body[0].x =5;
    body[0].y =4;

    map[body[0].x][body[0].y] = SNAKE_BODY;

    map[head.x][head.y] = SNAKE_HEAD;

    do{

        if (key == 'Q' || key == 'q') {

            val = 1;
        }
        else if (key == 'Z' || key == 'z') {

            val = 2;
        }
        else if (key == 'D' || key == 'd') {
            val = 3;
        }
        else if (key == 'S' || key == 's') {
            val = 4 ;
        }

        key = Fonct_Mouve(map,food,ligne,colone,&head,val,body,increase,&block,score);


    }while( key != 'p');
    printf("GAME OVER\n");
    free(body);


    return;
}


char Fonct_Mouve(char **map,Coord *food,int ligne,int colone,Coord *head,int val,Coord *body,int *increase,char *block,int *score)
{
    int i = 0, init, nb, verif;
    int  score_tmp = *score;
    char key , tmp ='a';

    if (val== 1) {
        init = head->y ;
    }
    else if (val == 2) {
        init = head->x;
    }
    else if (val == 3) {
        init = head->y ;
    }
    else if (val == 4) {
        init = head->x ;
    }
    // head -> x = (rand()%(colone-2)); pour faire que la tete puisse commencé a sortir n'importe où
    // head -> y = (rand()%(ligne-2));

    do {
        i++;
        nb = val;


        if (nb == 1) {
            head->y = init - i;
        } else if (nb == 2) {
            head->x = init - i;
        }
        else if (nb == 3) {
            head->y = init + i;
        }
        else if (nb == 4) {
            head->x = init + i;
        }
        key = pressing_key();

        if(key != NO_KEY){
            Fonct_Bloc(block,&key);
        }

        verif = Fonct_verif_mouv(map, *head,food,ligne,colone,&score_tmp);
        if (verif == FALSE){
            key = 'p';
            //  break;
        }
        if (key == NO_KEY) {

            Fonct_Can_mouve(map, *head,nb,body,verif,increase);
            system("clear");
            Fonct_Affiche_Map(map, ligne, colone, food, *head);
            Fonct_Affich_Score(score_tmp);
        } else {
            if (key == 'Q' || key == 'q') {

                Fonct_Can_mouve(map, *head,nb,body,verif,increase);
                system("clear");
                Fonct_Affiche_Map(map, ligne, colone, food, *head);
                Fonct_Affich_Score(score_tmp);
                tmp = 'p';
            } else if (key == 'Z' || key == 'z') {

                Fonct_Can_mouve(map, *head,nb,body,verif,increase);
                system("clear");
                Fonct_Affiche_Map(map, ligne, colone, food, *head);
                Fonct_Affich_Score(score_tmp);
                tmp = 'p';
            } else if (key == 'S' || key == 's') {


                Fonct_Can_mouve(map, *head,nb,body,verif,increase);;
                system("clear");
                Fonct_Affiche_Map(map, ligne, colone, food, *head);
                Fonct_Affich_Score(score_tmp);
                tmp = 'p';
            } else if (key == 'D' || key == 'd') {
                ;
                Fonct_Can_mouve(map, *head,nb,body,verif,increase);
                system("clear");
                Fonct_Affiche_Map(map, ligne, colone, food, *head);
                Fonct_Affich_Score(score_tmp);
                tmp = 'p';
            }else if (key == 'P' || key == 'p') {

                tmp = 'p';
            }
        }
    } while(tmp != 'p');
    *block = key;
    *score = score_tmp;
    return key;
}





