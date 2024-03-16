//
// Created by zoblaigg on 21/11/22.
//


#ifndef GESTION_CLAVIER_H
#define GESTION_CLAVIER_H

/*Macro utilisée par la fonction "pressing_key()" */
#define DELAY_KEY_DETECTION 100
#define HIT_KEY 1
#define NO_KEY -1

/* Fonctions permettant de changer le flot d'entrée et de le réinitialiser*/
void   init_keyboard(void);
void   close_keyboard(void);
int    keyboard_hit(void);
char   readch(void);
void my_delay(int i);

/*Fonction qui renvoie une touche pressée par l'utilisateur
 * Renvoie la valeur NO_KEY si aucune touche n'a été appuyée
 * pendant le temps DELAY_KEY_DETECTION (en secondes)*/
char pressing_key(void);

#endif

