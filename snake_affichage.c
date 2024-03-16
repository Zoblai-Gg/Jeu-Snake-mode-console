//
// Created by zoblaigg on 11/12/22.
//
#include <stdio.h>
#include "snake_affichage.h"
#include <stdlib.h>

void Fonct_welcome(void)
{
    int i;
    printf("\n\n");
    for (i = 0; i < 38; ++i)
        printf("x ");
    printf("\n");

    printf("x\t  __      __       .__                                            x\n"
           "x\t/  \\    /  \\ ____ |  |   ____  ____   _____   ____                x\n"
           "x\t\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\               x\n"
           "x\t\\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/                x\n"
           "x\t  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >              x\n"
           "x\t       \\/       \\/          \\/            \\/     \\/               x\n"
           "x\t   __                                                             x\n"
           "x\t _/  |_  ____                                by Gg                x\n"
           "x\t \\   __\\/  _ \\        __    __    __    __                        x\n"
           "x\t  |  | (  <_> )      /  \\  /  \\  /  \\  /  \\                       x\n"
           "x\t  |__|  \\____/ "
           "_____/  __\\/  __\\/  __\\/  __\\______________________x\n"
           "x\t___________________/  /__/  /__/  /__/  /________________________ x\n"
           "x\t                   | / \\   / \\   / \\   / \\  \\____                 x\n"
           "x\t                   |/   \\_/   \\_/   \\_/   \\    o \\                x\n"
           "x\t                                           \\_____/--<             x\n"
           "x\t                      __                                          x\n"
           "x\t  ______ ____ _____  |  | __ ____                                 x\n"
           "x\t /  ___//    \\\\__  \\ |  |/ // __ \\        _________________       x\n"
           "x\t \\___ \\|   |  \\/ __ \\|    <\\  ___/       [ Press O to play ]      x\n"
           "x\t/____  >___|  (____  /__|_ \\\\___  >      -------------------      x\n"
           "x\t     \\/     \\/     \\/     \\/    \\/                                x\n"
           "");
    for (i = 0; i <38; ++i)
        printf("x ");
    printf("\n\n");

    return;
}

void Fonct_menu(void)
{

    int i;
    printf("\n\n");
    for (i = 0; i < 38; ++i)
        printf("x ");
    printf("\n");

    printf("x                   \t\t\t\t                          x\n"
           "x                          \t\t                                  x\n"
           "x                 \t\t\t                                  x\n"
           "x\t    __                                      __      \t\t  x\n"
           "x\t   {0O}                                    {0O}  \t          x\n"
           "x\t   \\__/                                    \\__/    \t\t  x\n"
           "x\t   /^/                                     /^/      \t\t  x\n"
           "x\t  ( (                  1- Started          ( (      \t\t  x\n"
           "x\t  \\_\\_____                                  \\_\\_____\t          x\n"
           "x\t (_______)             2- Bests scores      (_______)   \t  x\n"
           "x\t (_________()Oo                             (_________()Oo        x\n"
           "x                  \t       3- Settings                      \t  x\n"
           "x                  __                                                     x\n"
           "x\t          {OO}         4- About this game                         x\n"
           "x\t          \\__/                                                    x\n"
           "x\t           |^|         5- Leave                            /\\     x\n"
           "x\t           | |____________________________________________/ /     x\n"
           "x\t           \\_______________________________________________/      x\n"
           "x                                                                         x\n"
           "x                                                                         x\n"
           "x                                                                         x\n");

    for (i = 0; i <38; ++i)
        printf("x ");
    printf("\n\n");

    return;

}

void Fonct_Affich_Score(int score){

    printf("---------------------------|\n"
           "|| Score : %d\n"
           "---------------------------|\n",score);
    printf("Appuyez sur P pour revenir au menu !\n");
    return;
}

