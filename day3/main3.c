#include <stdio.h>

int fibonacci(int n) {
    if (n < 0) {
        return -1;
    }
    
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 0) {

        return 1;
    }

    int result = fibonacci_rec(n);
    printf("피보나치 수열의 %d번째 값: %d\n", n, result);

    return 0;
}