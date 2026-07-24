#include <stdio.h>

int fibonacci(int n) {
    if (n < 0) return -1;
    
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int prev2 = 0;
    int prev1 = 1;
    int current = 0;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

int main() {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 0) {

        return 1;
    }

    int result = fibonacci_loop(n);
    printf("피보나치 수열의 %d번째 값: %d\n", n, result);

    return 0;
}