#include <stdio.h>

int factorial(int n) {
    if (n < 0) {
        return -1; 
    }
    
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 0) {
        
        return 1;
    }

    int result = factorial(n);
    printf("%d! = %d\n", n, result);

    return 0;
}