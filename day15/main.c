#include <stdio.h>

typedef struct {
    int stack;         
    double probability;
} GachaInfo;



// 매개변수로 GachaInfo의 주소를 받기
void inputInitStack(GachaInfo *info) {
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
        
        // 알맞은 주소로 이동하기 위해서 -> 이용
        info->stack = input;
        break;
    }
}

void calculateProbability(GachaInfo *info) {
    if (info->stack <= 50) {
        // 1 ~ 50 스택: 기본 확률 2%
        info->probability = 2.0;
    } 
    else if (info->stack < 99) {
        // 51 ~ 98 스택: 2% + (초과한 스택 * 2%)
        info->probability = 2.0 + (info->stack - 50) * 2.0;
    } 
    else {
        // 99 스택 이상: 100%
        info->probability = 100.0;
    }
}

void printResult(GachaInfo *info) {
    printf("=============================\n");
    printf("명일방주 확률 분석 결과\n");
    printf("=============================\n");
    printf(" 현재 스택 : %d\n", info->stack);
    printf(" 6성 등장 확률 : %.1f%%\n", info->probability);
}

int main() {
    // main 함수의 지역 변수로 원본 주소를 만든다.
    GachaInfo gacha = {0, 0.0};
    
    // 함수들을 호출할 때 원본 주소(&)를 넘긴다.
    inputInitStack(&gacha);
    calculateProbability(&gacha);
    printResult(&gacha);
    
    return 0;
}