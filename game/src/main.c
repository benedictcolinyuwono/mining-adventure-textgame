#include <stdio.h>
#include "grid.h"
#include "display.h"
#include "movement.h"

int main() {
    FILE *opening;
    char intro[1000];
    opening = fopen("introduction.txt", "r");

    while(fgets(intro, 1000, opening)) {
        printf("%s", intro);
    }
    fclose(opening);

    int i, j;

    char x;
    int valid = 0;
    char arr[40][40];
    int blockx[9];
    int blocky[9];

    int money = 0;
    int *currency = &money;

    int amount = 30;
    int *moves = &amount;

    printf("\n\n1 = Easy Difficulty\n");
    printf("2 = Normal Difficulty\n");
    printf("3 = Hard Difficulty\n");
    printf("Select Difficulty:");
    scanf(" %c", &x);

    //map making
    if (x == '1' || x == '2' || x == '3') {
        grid(x, arr, blockx, blocky);
        display(x, arr, moves);
    } else {
        while (valid == 0) {
            printf("\nInvalid input. Please input correct level.\n");
            printf("\n1 = Easy Difficulty\n");
            printf("2 = Normal Difficulty\n");
            printf("3 = Hard Difficulty\n");
            printf("Select Difficulty:");
            scanf(" %c", &x);
            if (x == '1' || x == '2' || x == '3') {
                grid(x, arr, blockx, blocky);
                display(x, arr, moves);
                valid = 1;
            } else {
                valid = 0;
            }
        }
    }

    int dirx = 0;
    int diry = 0;

    FILE *history;
    history = fopen("game_history.txt", "w");

    //movement
    if (x == '1' || x == '2' || x == '3') {
        movement(x, i, j, dirx, diry, arr, blockx, blocky, moves, currency, history);
    }

    FILE *closing;
    char close[1000];

    if (*moves == 0 && *currency < 600) {
        fputs("You lost.\n", history);
        closing = fopen("lose_game_closing.txt", "r");

        printf("\n");
        while(fgets(close, 1000, closing)) {
            printf("%s", close);
        }
    } else if (*moves >= 0 && *currency >= 600) {
        fputs("You won.\n", history);
        closing = fopen("win_game_closing.txt", "r");

        printf("\n");
        while(fgets(close, 1000, closing)) {
            printf("%s", close);
        }
    }
    fclose(history);

    FILE *flex;
    char journey[1000];
    flex = fopen("game_history.txt", "r");
    int tmp = 0;

    printf("\n");
    while (tmp == 0) {
        char y;
        printf("\nY = Yes\n");
        printf("N = No\n");
        printf("Would you like to see your journey?");
        scanf(" %c", &y);
        if (y == 'y' || y == 'Y') {
            printf("\n");
            while(fgets(journey, 1000, flex)) {
                printf("%s", journey);
            }
            tmp = 1;
        } else if (y == 'n' || y == 'N') {
            printf("\nUnderstood. Enjoy your day.\n");
            tmp = 1;
        } else {
            printf("\nInvalid input. Please choose appropriate character.\n");
            tmp = 0;
        }
    }
    fclose(flex);

    return 0;
}
