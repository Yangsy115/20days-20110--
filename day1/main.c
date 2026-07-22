#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n < 2) {
        printf("배열 생성에 실패했습니다. 2이상의 정수값을 입력해 다시시도해주세요.\n");
        scanf("%d", &n);
    }
    
    int *arr = malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max1, max2;
    if (arr[0] > arr[1]) {
        max1 = arr[0];
        max2 = arr[1];
    } else {
        max1 = arr[1];
        max2 = arr[0];
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] >= max1) { 
            max2 = max1;    
            max1 = arr[i];  
        } 
        else if (arr[i] > max2) { 
            max2 = arr[i];  
        }
    }
    
    printf("가장 큰 수: %d\n", max1);
    printf("두 번째로 큰 수: %d\n", max2);

    free(arr);
    
    return 0;
}