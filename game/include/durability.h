//
// Created by bc2-yuwono on 30/04/2024.
//

#ifndef MINI_COURSEWORK_DURABILITY_H
#define MINI_COURSEWORK_DURABILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void durability(int *moves, int *currency, FILE *history) {
    char item;
    int check = 0;

    if (*currency < 40) {
        fputs("But you didn't have sufficient funds.\n", history);
        printf("\nInsufficient funds. Please mine ores and get money first.\n");
    } else {
        while (check == 0) {
            printf("\nBuy 5 Moves?\n");
            printf("Y = Yes\n");
            printf("N = No\n");
            printf("Buy:");
            scanf(" %c", &item);

            if (item == 'y' || item == 'Y') {
                *moves += 10;
                *currency -= 50;
                fputs("You repaired your pickaxe.\n", history);
                printf("\nMoves: %d\n", *moves);
                printf("Money: %d\n", *currency);
                check = 1;
            } else if (item == 'n' || item == 'N') {
                fputs("You didn't repair your pickaxe.\n", history);
                printf("\nMoves: %d\n", *moves);
                printf("Money: %d\n", *currency);
                check = 1;
            } else {
                printf("\nInvalid decision. Please choose another.\n");
                check = 0;
            }
        }
    }
}

#endif //MINI_COURSEWORK_DURABILITY_H