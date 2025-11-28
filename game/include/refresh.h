//
// Created by bc2-yuwono on 30/04/2024.
//

#ifndef MINI_COURSEWORK_REFRESH_H
#define MINI_COURSEWORK_REFRESH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int refresh(char x, char arr[40][40]) {
    int i, j;

    int refresh = 0;

    if(x == '1') {
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 12; j++) {
                if (arr[i][j] == 'G' || arr[i][j] == 'S' || arr[i][j] == 'B') {
                    refresh += 1;
                }
            }
        }
    } else if(x == '2') {
        for (i = 0; i < 24; i++) {
            for (j = 0; j < 24; j++) {
                if (arr[i][j] == 'G' || arr[i][j] == 'S' || arr[i][j] == 'B') {
                    refresh += 1;
                }
            }
        }
    } else if(x == '3') {
        for (i = 0; i < 36; i++) {
            for (j = 0; j < 36; j++) {
                if (arr[i][j] == 'G' || arr[i][j] == 'S' || arr[i][j] == 'B') {
                    refresh += 1;
                }
            }
        }
    }
    return refresh;
}

#endif //MINI_COURSEWORK_REFRESH_H