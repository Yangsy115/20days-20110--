#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == NULL || 2 > n) {
        printf("배열 생성에 실패했습니다. 2이상의 정수값을 입력해 다시시도해주세요.\n");
        scanf("%d", &n);
    }
    
    int *arr = malloc(sizeof(int) * n);
    int max = arr[0];

    arr[7] = 1;
    arr[8] = 2;
    arr[9] = 1;

    
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) { 
            max = arr[i];   
        }
    }
    
    return 0;
}