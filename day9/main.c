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

    if (rows <= 0 || rows > 5 || cols <= 0 || cols > 5) {
        fclose(fp);
        return 0;
    }

    *X = -1;
    *Y = -1;
    int foundEnd = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char tempChar;
            if (fscanf(fp, " %c", &tempChar) != 1) {
                fclose(fp);
                return 0;
            }
            
            if (tempChar == '.') {
                maze[i][j] = '0';
            } else if (tempChar == '#') {
                maze[i][j] = '1';
            } else if (tempChar == 'S' || tempChar == 'E') {
                maze[i][j] = tempChar;
            } else {
                fclose(fp);
                return 0;
            }

            if (maze[i][j] == 'S') {
                *X = i;
                *Y = j;
            } else if (maze[i][j] == 'E') {
                foundEnd = 1;
            }
        }
    }

    fclose(fp);

    if (*X == -1 || *Y == -1 || foundEnd == 0) {
        return 0;
    }

    return 1;
}