#include <stdio.h>

typedef struct {
    int stack;         
    double probability;
} GachaInfo;

GachaInfo gacha = {0, 0.0};

void inputInitStack() {
    int input;
    
    while (1) {
        printf("현재 6성을 뽑지 못한 스택을 입력하세요.\n");
        
        if (scanf("%d", &input) != 1) {
            printf("숫자가 아닌 잘못된 입력입니다.\n");
            while (getchar() != '\n'); // 잘못받은거 지우기
            continue;
        }
        
        if (input < 0) {
            printf("스택은 0보다 작을 수 없습니다. 다시 입력해주세요.\n");
            continue;
        }
        
        gacha.stack = input;
        break;
    }
}

void Probabilitycalculate() {
    if (gacha.stack <= 50) {
        // 1 ~ 50 스택: 기본 확률 2%
        gacha.probability = 2.0;
    } 
    else if (gacha.stack < 99) {
        // 51 ~ 98 스택: 2% + (초과한 스택 * 2%)
        gacha.probability = 2.0 + (gacha.stack - 50) * 2.0;
    } 
    else {
        // 99 스택 이상: 100%
        gacha.probability = 100.0;
    }
}

void printResult() {
    printf("=============================\n");
    printf("명일방주 확률 분석 결과\n");
    printf("=============================\n");
    printf(" 현재 스택 : %d\n", gacha.stack);
    printf(" 6성 등장 확률 : %.1f%%\n", gacha.probability);
}

int main() {
    
    inputInitStack();
    Probabilitycalculate();
    printResult();
    
    return 0;
}