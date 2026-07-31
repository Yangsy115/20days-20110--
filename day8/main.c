#include <stdio.h>

int MazeFile(const char *filename, char maze[5][5], int *X, int *Y) {
    FILE *fp = fopen(filename, "r");
    
    if (fp == NULL) {
        return 0; 
    }

    int rows, cols;
    if (fscanf(fp, "%d %d", &rows, &cols) != 2) {
        fclose(fp);
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char tempChar;
            fscanf(fp, " %c", &tempChar);
            
            if (tempChar == '.') {
                maze[i][j] = '0';
            } else if (tempChar == '#') {
                maze[i][j] = '1';
            } else {
                maze[i][j] = tempChar;
            }

            if (maze[i][j] == 'S') {
                *X = i;
                *Y = j;
            }
        }
    }

    fclose(fp);
    return 1;
}