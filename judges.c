#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 5
#define MAX_JSON_LEN 512

void inputJudges(char judges_array[][MAX_JSON_LEN], int judge_count);
void displayJudges(char judges_array[][MAX_JSON_LEN], int judge_count);
int checkInput(char *input);

int main() {
    char judges_array[MAX_JUDGES][MAX_JSON_LEN];
    int judge_count = 0;
    int selected_members;
    char project_name[50];
    char input_check;
    
    // 프로젝트 및 인원 정보 입력
    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    scanf("%s", project_name);
    
    printf("> 심사 풀 인원: ");
    scanf("%d", &judge_count);
    
    if (judge_count > MAX_JUDGES) {
        printf("심사 풀 인원은 최대 %d명입니다.\n", MAX_JUDGES);
        return 1;
    }
    
    printf("> 선발 멤버 수: ");
    scanf("%d", &selected_members);
    
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", judge_count);
    printf("++++++++++++++++++++++++++++++++++++\n");
    
    // 심사자 정보 입력
    inputJudges(judges_array, judge_count);
    
    // 입력된 정보 확인 여부
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("“심사자 풀을 확인할까요?” (Y/N): ");
    scanf(" %c", &input_check);
    
    if (input_check == 'Y') {
        // 심사자 정보 출력
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");
        displayJudges(judges_array, judge_count);
    } else {
        printf("프로그램을 종료합니다.\n");
    }
    
    return 0;
}

// 심사자 정보 입력 함수
void inputJudges(char judges_array[][MAX_JSON_LEN], int judge_count) {
    char buffer[MAX_JSON_LEN];
    int i;
    
    for (i = 0; i < judge_count; i++) {
        while (1) {
            printf("*심사자 %d: ", i + 1);
            fgets(buffer, MAX_JSON_LEN, stdin);
            
            if (checkInput(buffer)) {
                snprintf(judges_array[i], MAX_JSON_LEN, "%s", buffer);
                break;
            } else {
                printf("입력 항목이 정확하지 않습니다. 다시 입력해주세요.\n");
            }
        }
    }
}

// 심사자 정보 출력 함수
void displayJudges(char judges_array[][MAX_JSON_LEN], int judge_count) {
    int i;
    
    for (i = 0; i < judge_count; i++) {
        printf("[심사자 %d]\n%s", i + 1, judges_array[i]);
        printf("-----------------------------------\n");
    }
}

// 입력 데이터 검증 함수
int checkInput(char *input) {
    int count = 0;
    char *p = input;
    
    // 입력 항목 개수를 확인 (이름, 성별, 소속, 직함, 전문분야, 메일, 전화)
    while (*p) {
        if (*p == ':') count++;
        p++;
    }
    
    return (count == 7); // 항목 수가 7개인지 확인
}
