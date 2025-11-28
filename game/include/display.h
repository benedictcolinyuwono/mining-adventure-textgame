//
// Created by bc2-yuwono on 30/04/2024.
//

#ifndef MINI_COURSEWORK_DISPLAY_H
#define MINI_COURSEWORK_DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(char x, char map[][40], int *moves) { //print map
    int i, j;

    if (x == '1') { //1st difficulty level map with borders
        printf("\nMap\n");
        printf("|||||||||||||||||||||||||||\n| ");
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 12; j++) {
                printf("%c", map[i][j]);
                printf(" ");
                if (i == 11 && j == 11) {
                    printf("|\n|||||||||||||||||||||||||||\n");
                    printf("Remaining Moves: %d\n", *moves);
                } else if (j == 11) {
                    printf("|\n| ");
                }
            }
        }
    } else if (x == '2') { //2nd difficulty level map with borders
        printf("\nMap\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n| ");
        for (i = 0; i < 24; i++) {
            for(j = 0; j < 24; j++) {
                printf("%c", map[i][j]);
                printf(" ");
                if (i == 23 && j == 23) {
                    printf("|\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                    printf("Remaining Moves: %d\n", *moves);
                } else if (j == 23) {
                    printf("|\n| ");
                }
            }
        }
    } else if (x == '3') { //3rd difficult level map with borders
        printf("\nMap\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n| ");
        for (i = 0; i < 36; i++) {
            for(j = 0; j < 36; j++) {
                printf("%c", map[i][j]);
                printf(" ");
                if (i == 35 && j == 35) {
                    printf("|\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                    printf("Remaining Moves: %d\n", *moves);
                } else if (j == 35) {
                    printf("|\n| ");
                }
            }
        }
    }
}

#endif //MINI_COURSEWORK_DISPLAY_H
