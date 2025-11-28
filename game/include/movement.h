//
// Created by bc2-yuwono on 30/04/2024.
//

#ifndef MINI_COURSEWORK_MOVEMENT_H
#define MINI_COURSEWORK_MOVEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "outlet.h"
#include "durability.h"
#include "refresh.h"

void movement(char x, int i, int j, int dirx, int diry, char arr[40][40], int blockx[9], int blocky[9], int *moves, int *currency, FILE *history) { //movement
    char m;
    i = dirx;
    j = diry;
    int tempi;
    int tempj;

    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int *gold = &value1;
    int *silver = &value2;
    int *bronze = &value3;

    int total;

    int state = 0;

    while (state == 0) {
        printf("\nW/A/S/D = Movement\n");
        printf("I = Inventory\n");
        printf("O = Outlet\n");
        printf("M = Moves\n");
        printf("What do you want to do?");
        scanf(" %c", &m);
        if (m == 'w' || m == 'W') { //w movement
            if (i == 0) {
                fputs("You moved up.\nBut you were blocked by the border.\n", history);
                printf("\nBlocked by Border.\n");
            } else {
                i -= 1;
                *moves -= 1;
                if (arr[i][j] == '.') {
                    *moves += 1;
                }
                fputs("You moved up.\n", history);
                if(x == '1') {
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2]) {
                        i += 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                } else if (x == '2') {
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2] || i == blockx[3] && j == blocky[3] || i == blockx[4] && j == blocky[4] || i == blockx[5] && j == blocky[5]) {
                        i += 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                } else if (x == '3') {
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2] || i == blockx[3] && j == blocky[3] || i == blockx[4] && j == blocky[4] || i == blockx[5] && j == blocky[5] || i == blockx[6] && j == blocky[6] || i == blockx[7] && j == blocky[7] || i == blockx[8] && j == blocky[8]) {
                        i += 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                }
            }
            if (arr[i][j] == 'G') {
                *gold += 1;
                fputs("You mined gold.\n", history);
            } else if (arr[i][j] == 'S') {
                *silver += 1;
                fputs("You mined silver.\n", history);
            } else if (arr[i][j] == 'B') {
                *bronze += 1;
                fputs("You mined bronze.\n", history);
            }

            tempi = dirx;
            tempj = diry;
            dirx = i;
            diry = j;

            arr[tempi][tempj] = '.';
            arr[i][j] = 'M';
            display(x, arr, moves);
        } else if (m == 'a' || m == 'A') { //a movement
            if (j == 0) {
                fputs("You moved left.\nBut you were blocked by the border.\n", history);
                printf("\nBlocked by Border.\n");
            } else {
                j -= 1;
                *moves -= 1;
                if (arr[i][j] == '.') {
                    *moves += 1;
                }
                fputs("You moved left.\n", history);
                if(x == '1') {
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2]) {
                        j += 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                } else if (x == '2') {
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2] || i == blockx[3] && j == blocky[3] || i == blockx[4] && j == blocky[4] || i == blockx[5] && j == blocky[5]) {
                        j += 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                } else if (x == '3') {
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2] || i == blockx[3] && j == blocky[3] || i == blockx[4] && j == blocky[4] || i == blockx[5] && j == blocky[5] || i == blockx[6] && j == blocky[6] || i == blockx[7] && j == blocky[7] || i == blockx[8] && j == blocky[8]) {
                        j += 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                }
            }
            if (arr[i][j] == 'G') {
                *gold += 1;
                fputs("You mined gold.\n", history);
            } else if (arr[i][j] == 'S') {
                *silver += 1;
                fputs("You mined silver.\n", history);
            } else if (arr[i][j] == 'B') {
                *bronze += 1;
                fputs("You mined bronze.\n", history);
            }

            tempi = dirx;
            tempj = diry;
            dirx = i;
            diry = j;

            arr[tempi][tempj] = '.';
            arr[i][j] = 'M';
            display(x, arr, moves);
        } else if (m == 's' || m == 'S') { //s movement
            if (x == '1') {
                if (i == 11) {
                    fputs("You moved down.\nBut you were blocked by the border.\n", history);
                    printf("\nBlocked by Border.\n");
                } else {
                    i += 1;
                    *moves -= 1;
                    if (arr[i][j] == '.') {
                        *moves += 1;
                    }
                    fputs("You moved down.\n", history);
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2]) {
                        i -= 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                }
            } else if (x == '2') {
                if (i == 23) {
                    fputs("You moved down.\nBut you were blocked by the border.\n", history);
                    printf("\nBlocked by Border.\n");
                } else {
                    i += 1;
                    *moves -= 1;
                    if (arr[i][j] == '.') {
                        *moves += 1;
                    }
                    fputs("You moved down.\n", history);
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2] || i == blockx[3] && j == blocky[3] || i == blockx[4] && j == blocky[4] || i == blockx[5] && j == blocky[5]) {
                        i -= 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                }
            } else if (x == '3') {
                if (i == 35) {
                    fputs("You moved down.\nBut you were blocked by the border.\n", history);
                    printf("\nBlocked by Border.\n");
                } else {
                    i += 1;
                    *moves -= 1;
                    if (arr[i][j] == '.') {
                        *moves += 1;
                    }
                    fputs("You moved down.\n", history);
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2] || i == blockx[3] && j == blocky[3] || i == blockx[4] && j == blocky[4] || i == blockx[5] && j == blocky[5] || i == blockx[6] && j == blocky[6] || i == blockx[7] && j == blocky[7] || i == blockx[8] && j == blocky[8]) {
                        i -= 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                }
            }
            if (arr[i][j] == 'G') {
                *gold += 1;
                fputs("You mined gold.\n", history);
            } else if (arr[i][j] == 'S') {
                *silver += 1;
                fputs("You mined silver.\n", history);
            } else if (arr[i][j] == 'B') {
                *bronze += 1;
                fputs("You mined bronze.\n", history);
            }

            tempi = dirx;
            tempj = diry;
            dirx = i;
            diry = j;

            arr[tempi][tempj] = '.';
            arr[i][j] = 'M';
            display(x, arr, moves);
        } else if (m == 'd' || m == 'D') { //d movement
            if (x == '1') {
                if (j == 11) {
                    fputs("You moved right.\nBut you were blocked by the border.\n", history);
                    printf("\nBlocked by Border.\n");
                } else {
                    j += 1;
                    *moves -= 1;
                    if (arr[i][j] == '.') {
                        *moves += 1;
                    }
                    fputs("You moved right.\n", history);
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2]) {
                        j -= 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                }
            } else if (x == '2') {
                if (j == 23) {
                    fputs("You moved right.\nBut you were blocked by the border.\n", history);
                    printf("\nBlocked by Border.\n");
                } else {
                    j += 1;
                    *moves -= 1;
                    if (arr[i][j] == '.') {
                        *moves += 1;
                    }
                    fputs("You moved right.\n", history);
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2] || i == blockx[3] && j == blocky[3] || i == blockx[4] && j == blocky[4] || i == blockx[5] && j == blocky[5]) {
                        j -= 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                }
            } else if (x == '3') {
                if (j == 35) {
                    fputs("You moved right.\nBut you were blocked by the border.\n", history);
                    printf("\nBlocked by Border.\n");
                } else {
                    j += 1;
                    *moves -= 1;
                    if (arr[i][j] == '.') {
                        *moves += 1;
                    }
                    fputs("You moved right.\n", history);
                    if (i == blockx[0] && j == blocky[0] || i == blockx[1] && j == blocky[1] || i == blockx[2] && j == blocky[2] || i == blockx[3] && j == blocky[3] || i == blockx[4] && j == blocky[4] || i == blockx[5] && j == blocky[5] || i == blockx[6] && j == blocky[6] || i == blockx[7] && j == blocky[7] || i == blockx[8] && j == blocky[8]) {
                        j -= 1;
                        fputs("But you were blocked by an obstacle.\n", history);
                        printf("\nBlocked by Obstacle.\n");
                    }
                }
            }
            if (arr[i][j] == 'G') {
                *gold += 1;
                fputs("You mined gold.\n", history);
            } else if (arr[i][j] == 'S') {
                *silver += 1;
                fputs("You mined silver.\n", history);
            } else if (arr[i][j] == 'B') {
                *bronze += 1;
                fputs("You mined bronze.\n", history);
            }

            tempi = dirx;
            tempj = diry;
            dirx = i;
            diry = j;

            arr[tempi][tempj] = '.';
            arr[i][j] = 'M';
            display(x, arr, moves);
        } else if (m == 'i' || m == 'I') { //inventory
            fputs("You opened your inventory.\n", history);
            printf("\nInventory\n");
            printf("Gold: %d\n", *gold);
            printf("Silver: %d\n", *silver);
            printf("Bronze: %d\n", *bronze);
            printf("Money: %d\n", *currency);
        } else if (m == 'o' || m == 'O') { //outlet
            fputs("You opened the outlet.\n", history);
            outlet(gold, silver, bronze, currency, history);
            if (*currency >= 600) {
                state = 1;
            } else {
                state = 0;
            }
        } else if (m == 'm' || m == 'M') { //moves
            fputs("You opened the repair shop.\n", history);
            durability(moves, currency, history);
        } else {
            printf("\nInvalid input. Please input a valid movement key.\n");
        }
        total = *gold + *silver + *bronze;
        if (total == 10) {
            fputs("Your backpack was full.\n", history);
            printf("\nBackpack is full. Must sell item before mining other ores.\n");
            outlet(gold, silver, bronze, currency, history);
        }
        if (refresh(x, arr) == 0) {
            fputs("You went to another cave.\n", history);
            printf("\nYou went to another cave.\n");
            dirx = 0;
            diry = 0;
            i = 0;
            j = 0;
            srand(time(NULL));
            grid(x, arr, blockx, blocky);
            display(x, arr, moves);
        }
        if (*moves == 0) {
            fputs("You broke your pickaxe.\n", history);
            printf("\nYou broke your pickaxe.\n");
            outlet(gold, silver, bronze, currency, history);
            state = 1;
        }
    }
}

#endif //MINI_COURSEWORK_MOVEMENT_H