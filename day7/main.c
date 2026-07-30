#include <stdio.h>

void initMaze(char maze[5][5], int *X, int *Y) {
    char temp[5][5] = {
        {'1', '1', '1', '1', '1'},
        {'S', '0', '0', '0', '1'},
        {'1', '1', '1', '0', '1'},
        {'1', '0', '0', '0', '1'},
        {'1', '1', '1', 'E', '1'}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            maze[i][j] = temp[i][j];
            if (maze[i][j] == 'S') {
                *X = i; 
                *Y = j; 
            }
        }
    }
}

int EscapeDFS(char maze[5][5], int visited[5][5], int r, int c) {
    if (r < 0 || r >= 5 || c < 0 || c >= 5) {
        return 0;
    }
    
    if (maze[r][c] == '1' || visited[r][c] == 1) {
        return 0;
    }
    
    if (maze[r][c] == 'E') {
        return 1;
    }
    
    visited[r][c] = 1;
    
    if (EscapeDFS(maze, visited, r - 1, c) == 1) return 1; 
    if (EscapeDFS(maze, visited, r + 1, c) == 1) return 1; 
    if (EscapeDFS(maze, visited, r, c - 1) == 1) return 1; 
    if (EscapeDFS(maze, visited, r, c + 1) == 1) return 1; 
    
    return 0;
}

int main() {
    char maze[5][5];
    int visited[5][5] = {0}; 
    int X, Y;
    
    initMaze(maze, &X, &Y);
    
    if (EscapeDFS(maze, visited, X, Y) == 1) {
        printf("성공");
    } else {
        printf("실패");
    }
    
    return 0;
}