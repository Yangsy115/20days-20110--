#include <stdio.h>
#include <stdlib.h>

void Sum_Avg(int *arr, int n, int *sum, double *avg) {
    *sum = 0; 
    
    for (int i = 0; i < n; i++) {
        *sum += arr[i];
    }
    *avg = (double)(*sum) / n; //평균값인데 정확도를 올리기위한 소수점구하기
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    if (n <= 0) {
        return 1;
    }
    
    int *arr = malloc(sizeof(int) * n);
    
    if (arr == NULL) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int totalSum;
    double totalAvg;
    
    Sum_Avg(arr, n, &totalSum, &totalAvg);
    
    printf("배열의 합: %d\n", totalSum);
    printf("배열의 평균: %.2f\n", totalAvg);
    
    free(arr);
    
    return 0;
}