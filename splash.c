#include <stdio.h>
#include <stdlib.h>

#define MESSAGE "풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아, 사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳, 마그라테아에 오신걸 환영합니다."

void print_triangle(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size - i; j++) {
            putchar(' ');
        }
        for (int j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

void print_reverse_triangle(int size) {
    for (int i = size; i >= 1; i--) {
        for (int j = 1; j <= size - i; j++) {
            putchar(' ');
        }
        for (int j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

int main() {
    char name[50];
    char date[11];

    // 사용자로부터 날짜 입력 받기
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    fgets(date, sizeof(date), stdin);
    date[strlen(date) - 1] = '\0'; // 개행 문자 제거

    // 사용자로부터 이름 입력 받기
    printf("[당신의 이름을 입력하세요]: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0'; // 개행 문자 제거

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // 3초 대기
    for (int i = 0; i < 3; i++) {
        system("sleep 1"); // Unix-like 시스템에서 1초 대기
    }

    // 화면 지우기
    system("clear"); // Unix-like 시스템에서 화면 지우기
    // Windows에서는 system("cls") 사용 가능.

    // 스플래시 화면 출력
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    print_triangle(5); // 정 삼각형 출력
    printf("                         [마그라테아 ver 0.1]                               \n");
    printf("           %s\n", MESSAGE);
    print_reverse_triangle(5); // 역 삼각형 출력
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s                                   [실행 시간]:%s\n", name, date);
    printf("================================================================================\n");

    return 0;
}
