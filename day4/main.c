#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int score;
} Student;

int main() {
    int N = 0;
    if (scanf("%d", &N) != 1 || N <= 0) return 1; 

    Student students[N]; 

    for (int i = 0; i < N; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if ( (students[j].score < students[j+1].score) || 
                 (students[j].score == students[j+1].score && strcmp(students[j].name, students[j+1].name) > 0) ) {
                
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }

    return 0;
}