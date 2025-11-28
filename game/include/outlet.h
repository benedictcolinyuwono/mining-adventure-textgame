//
// Created by bc2-yuwono on 30/04/2024.
//

#ifndef MINI_COURSEWORK_OUTLET_H
#define MINI_COURSEWORK_OUTLET_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void outlet(int *gold, int *silver, int *bronze, int *currency, FILE *history) {
    char item;
    int check = 0;

    if (*gold == 0 && *silver == 0 && *bronze == 0) {
        fputs("But your backpack was empty.\n", history);
        printf("\nBackpack is empty. Must mine ores first.\n");
    } else {
        while (check == 0) {
            printf("\nOutlet\n");
            printf("G = Gold (100 money)\n");
            printf("S = Silver (50 money)\n");
            printf("B = Bronze (20 money)\n");
            printf("A = All\n");
            printf("N = None\n");
            printf("Sell:");
            scanf(" %c", &item);

            if (item == 'g' || item == 'G') {
                *gold -= 1;
                *currency += 100;
                fputs("You sold gold.\n", history);
                printf("\nGold: %d\n", *gold);
                printf("Silver: %d\n", *silver);
                printf("Bronze: %d\n", *bronze);
                printf("Money: %d\n", *currency);
                check = 1;
            } else if (item == 's' || item == 'S') {
                *silver -= 1;
                *currency += 50;
                fputs("You sold silver.\n", history);
                printf("\nGold: %d\n", *gold);
                printf("Silver: %d\n", *silver);
                printf("Bronze: %d\n", *bronze);
                printf("Money: %d\n", *currency);
                check = 1;
            } else if (item == 'b' || item == 'B') {
                *bronze -= 1;
                *currency += 20;
                fputs("You sold bronze.\n", history);
                printf("\nGold: %d\n", *gold);
                printf("Silver: %d\n", *silver);
                printf("Bronze: %d\n", *bronze);
                printf("Money: %d\n", *currency);
                check = 1;
            } else if (item == 'a' || item == 'A') {
                *currency += (*gold * 100) + (*silver * 50) + (*bronze * 20);
                *gold -= *gold;
                *silver -= *silver;
                *bronze -= *bronze;
                fputs("You sold all items.\n", history);
                printf("\nGold: %d\n", *gold);
                printf("Silver: %d\n", *silver);
                printf("Bronze: %d\n", *bronze);
                printf("Money: %d\n", *currency);
                check = 1;
            } else if (item == 'n' || item == 'N') {
                fputs("You didn't sell anything.\n", history);
                printf("\nGold: %d\n", *gold);
                printf("Silver: %d\n", *silver);
                printf("Bronze: %d\n", *bronze);
                printf("Money: %d\n", *currency);
                check = 1;
            } else {
                printf("\nInvalid ore. Please choose another.\n");
                check = 0;
            }
        }
    }
}

#endif //MINI_COURSEWORK_OUTLET_H