#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

typedef struct {
    char name[20]; 
    int level;     
    int hp;        
    int atk;       
} Character;

Character stats;

void charName() {
    printf("캐릭터의 이름을 입력하세요: ");
    scanf("%19s", stats.name);

    stats.level = 1;
    stats.hp = rand() % 51 + 100;
    stats.atk = rand() % 11 + 10;
}

void printStatus() {
    printf("\n 캐릭터 상태창\n");
    printf("=============================\n");
    printf(" 이름   : %s\n", stats.name);
    printf(" 레벨   : %d\n", stats.level);
    printf(" 체력   : %d\n", stats.hp);
    printf(" 공격력 : %d\n", stats.atk);
    printf("=============================\n");
}

void levelUp() {
    stats.level += 1;
    stats.hp += 50;
    stats.atk += 10;
}

int main() {
    srand((unsigned int)time(NULL)); 
    
    int choice;
    
    charName();
    
    while (1) {
        printf("1. 레벨업\n");
        printf("2. 스탯보기\n");
        printf("3. 프로그램 종료\n");
        printf("무엇을 할지 선택하세요: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n숫자가 아닌 잘못된 입력입니다.\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (choice == 1) {
            levelUp();
        } else if (choice == 2) {
            printStatus();
        } else if (choice == 3) {
            printf("\n종료합니다.\n");
            break;
        } else {
            printf("\n1, 2, 3번 중에서 선택해주세요.\n");
        }
    }
    
    return 0;
}