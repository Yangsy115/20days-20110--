#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char string[100];
    
    if (fgets(string, sizeof(string), stdin) == NULL) {
        return 0;
    }

    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
        len--;
    }

    int left = 0;
    int right = (int)len - 1;
    int is_palindrome = 1; // 1이면 회문, 0이면 회문 아님

    while (left < right) {
        if (isspace((unsigned char)string[left])) {
            left++;
        } 
        else if (isspace((unsigned char)string[right])) {
            right--;
        } 
        else {
            if (tolower((unsigned char)string[left]) != tolower((unsigned char)string[right])) {
                is_palindrome = 0; 
                break;
            }
            left++;
            right--;
        }
    }

    if (is_palindrome) {
        printf("회문입니다.\n");
    } else {
        printf("회문이 아닙니다.\n");
    }

    return 0;
}