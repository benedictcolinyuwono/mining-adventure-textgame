//
// Created by bc2-yuwono on 30/04/2024.
//

#ifndef MINI_COURSEWORK_GRID_H
#define MINI_COURSEWORK_GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int column;
} Ore;

void grid(char x, char grid[40][40], int blockx[9], int blocky[9]) {
    srand(time(NULL));
    int i, j;
    int blockrow;
    int blockcolumn;
    int blockcell = 0;

    if(x == '1') { //1st difficulty level
        Ore s1 = {0, rand() % 12}; //generate random elements
        Ore s2 = {rand() % 3, rand() % 12};
        Ore s3 = {rand() % 6 + 6, rand() % 12};

        for (i = 0; i < 12; i++) {
            for (j = 0; j < 12; j++) {
                if (s2.row == 0 && s2.column == 0) {
                    s2.column += 1;
                }
                if (s1.row == 0 && s1.column == 0) {
                    s1.column += 1;
                }

                if (i == s3.row && j == s3.column) { //3rd ore
                    if (s3.row == s2.row && s3.column == s2.column) {
                        if (s2.column == 11) {
                            s2.row += 1;
                            s2.column = 0;
                        } else {
                            s2.column = rand() % 12;
                            if (s2.column < j) {
                                s2.row += 1;
                            }
                        }
                    }
                    if (s3.row == s1.row && s3.column == s1.column) {
                        if (s1.column == 11) {
                            s1.row += 1;
                            s1.column = 0;
                        } else {
                            s1.column = rand() % 12;
                            if (s1.column < j) {
                                s1.row += 1;
                            }
                        }
                    }
                    grid[i][j] = 'G';
                } else if (i == s2.row && j == s2.column) { //2nd ore
                    if (s2.row == s1.row && s2.column == s1.column) {
                        if (s1.column == 11) {
                            s1.row += 1;
                            s1.column = 0;
                        } else {
                            s1.column = rand() % 12;
                            if (s1.column < j) {
                                s1.row += 1;
                            }
                        }
                    }
                    grid[i][j] = 'S';
                    s2.row += 2;
                    s2.column = rand() % 12;
                } else if (i == s1.row && j == s1.column) { //1st ore
                    grid[i][j] = 'B';
                    s1.row += 1;
                    s1.column = rand() % 12;
                } else { //rock
                    grid[i][j] = 'O';
                }
            }
        }
        while (blockcell != 3) {
            blockrow = rand() % 10 + 1;
            blockcolumn = rand() % 10 + 1;
            while (blockrow == s3.row && blockcolumn == s3.column || blockrow == s2.row && blockcolumn == s2.column ||
                   blockrow == s1.row && blockcolumn == s1.column) {
                blockcolumn += 1;
                if (blockcolumn > 10) {
                    blockrow += 1;
                    blockcolumn = 1;
                }
            }
            blockx[blockcell] = blockrow;
            blocky[blockcell] = blockcolumn;
            grid[blockrow][blockcolumn] = ' ';
            blockcell += 1;
        }
    } else if (x == '2') { //2nd difficulty level
        Ore s1 = {0, rand() % 24};
        Ore s2 = {rand() % 3, rand() % 24};
        Ore s3 = {rand() % 12 + 12, rand() % 24};

        for (i = 0; i < 24; i++) {
            for (j = 0; j < 24; j++) {
                if (s2.row == 0 && s2.column == 0) {
                    s2.column += 1;
                }
                if (s1.row == 0 && s1.column == 0) {
                    s1.column += 1;
                }
                if (i == s3.row && j == s3.column) { //3rd ore
                    if (s3.row == s2.row && s3.column == s2.column) {
                        if (s2.column == 23) {
                            s2.row += 1;
                            s2.column = 0;
                        } else {
                            s2.column = rand() % 24;
                            if (s2.column < j) {
                                s2.row += 1;
                            }
                        }
                    }
                    if (s3.row == s1.row && s3.column == s1.column) {
                        if (s1.column == 23) {
                            s1.row += 1;
                            s1.column = 0;
                        } else {
                            s1.column = rand() % 24;
                            if (s1.column < j) {
                                s1.row += 1;
                            }
                        }
                    }
                    grid[i][j] = 'G';
                } else if (i == s2.row && j == s2.column) { //2nd ore
                    if (s2.row == s1.row && s2.column == s1.column) {
                        if (s1.column == 23) {
                            s1.row += 1;
                            s1.column = 0;
                        } else {
                            s1.column = rand() % 24;
                            if (s1.column < j) {
                                s1.row += 1;
                            }
                        }
                    }
                    grid[i][j] = 'S';
                    s2.row += 2;
                    s2.column = rand() % 24;
                } else if (i == s1.row && j == s1.column) { //1st ore
                    grid[i][j] = 'B';
                    s1.row += 1;
                    s1.column = rand() % 24;
                } else {
                    grid[i][j] = 'O';
                }
            }
        }
        while (blockcell != 6) {
            blockrow = rand() % 22 + 1;
            blockcolumn = rand() % 22 + 1;
            while (blockrow == s3.row && blockcolumn == s3.column || blockrow == s2.row && blockcolumn == s2.column ||
                   blockrow == s1.row && blockcolumn == s1.column) {
                blockcolumn += 1;
                if (blockcolumn > 22) {
                    blockrow += 1;
                    blockcolumn = 1;
                }
            }
            blockx[blockcell] = blockrow;
            blocky[blockcell] = blockcolumn;
            grid[blockrow][blockcolumn] = ' ';
            blockcell += 1;
        }
    } else if (x == '3') { //3rd difficulty level
        Ore s1 = {0, rand() % 36};
        Ore s2 = {rand() % 3, rand() % 36};
        Ore s3 = {rand() % 18 + 18, rand() % 36};

        for (i = 0; i < 36; i++) {
            for (j = 0; j < 36; j++) {
                if (i == s3.row && j == s3.column) { //3rd ore
                    if (s2.row == 0 && s2.column == 0) {
                        s2.column += 1;
                    }
                    if (s1.row == 0 && s1.column == 0) {
                        s1.column += 1;
                    }
                    if (s3.row == s2.row && s3.column == s2.column) {
                        if (s2.column == 35) {
                            s2.row += 1;
                            s2.column = 0;
                        } else {
                            s2.column = rand() % 36;
                            if (s2.column < j) {
                                s2.row += 1;
                            }
                        }
                    }
                    if (s3.row == s1.row && s3.column == s1.column) {
                        if (s1.column == 35) {
                            s1.row += 1;
                            s1.column = 0;
                        } else {
                            s1.column = rand() % 36;
                            if (s1.column < j) {
                                s1.row += 1;
                            }
                        }
                    }
                    grid[i][j] = 'G';
                } else if (i == s2.row && j == s2.column) { //2nd ore
                    if (s2.row == s1.row && s2.column == s1.column) {
                        if (s1.column == 35) {
                            s1.row += 1;
                            s1.column = 0;
                        } else {
                            s1.column = rand() % 36;
                            if (s1.column < j) {
                                s1.row += 1;
                            }
                        }
                    }
                    grid[i][j] = 'S';
                    s2.row += 2;
                    s2.column = rand() % 36;
                } else if (i == s1.row && j == s1.column) { //1st ore
                    grid[i][j] = 'B';
                    s1.row += 1;
                    s1.column = rand() % 36;
                } else {
                    grid[i][j] = 'O';
                }
            }
        }
        while (blockcell != 9) {
            blockrow = rand() % 34 + 1;
            blockcolumn = rand() % 34 + 1;
            while (blockrow == s3.row && blockcolumn == s3.column || blockrow == s2.row && blockcolumn == s2.column ||
                   blockrow == s1.row && blockcolumn == s1.column) {
                blockcolumn += 1;
                if (blockcolumn > 34) {
                    blockrow += 1;
                    blockcolumn = 1;
                }
            }
            blockx[blockcell] = blockrow;
            blocky[blockcell] = blockcolumn;
            grid[blockrow][blockcolumn] = ' ';
            blockcell += 1;
        }
    }
    grid[0][0] = 'M';
}

#endif //MINI_COURSEWORK_GRID_H