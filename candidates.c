#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 6
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50
#define NATIONALITY_LENGTH 30
#define SKILL_LENGTH 30
#define INTRO_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    char birthdate[11]; // YYYY/MM/DD 형식
    char gender;        // 'F' 또는 'M'
    char email[EMAIL_LENGTH];
    char nationality[NATIONALITY_LENGTH];
    float bmi;
    char main_skill[SKILL_LENGTH];
    char sub_skill[SKILL_LENGTH];
    int korean_level;   // 한국어 등급 (TOPIK)
    char mbti[5];
    char introduction[INTRO_LENGTH];
    int age;            // 만 나이 추가
} Candidate;

void calculate_age(Candidate *candidate) {
    // 생일을 기준으로 만 나이를 계산
    struct tm birth_tm = {0};
    strptime(candidate->birthdate, "%Y/%m/%d", &birth_tm);
    time_t now = time(NULL);
    struct tm *current_tm = localtime(&now);

    candidate->age = current_tm->tm_year + 1900 - (birth_tm.tm_year + 1900);
    if (current_tm->tm_mon < birth_tm.tm_mon || 
       (current_tm->tm_mon == birth_tm.tm_mon && current_tm->tm_mday < birth_tm.tm_mday)) {
        candidate->age--;
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    char group_name[NAME_LENGTH];

    // 오디션 그룹명 입력
    printf("오디션 그룹명을 입력하세요: ");
    fgets(group_name, sizeof(group_name), stdin);
    group_name[strcspn(group_name, "\n")] = 0; // 개행문자 제거

    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 입력\n", group_name);
    printf("####################################\n");

    int i = 0;
    while (i < MAX_CANDIDATES) {
        printf("%d번째 후보자의 정보를 입력합니다.\n", i + 1);
        printf("---------------------------------\n");
        
        printf("1. 성명: ");
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // 개행문자 제거

        printf("2. 생일(YYYY/MM/DD 형식): ");
        fgets(candidates[i].birthdate, sizeof(candidates[i].birthdate), stdin);
        candidates[i].birthdate[strcspn(candidates[i].birthdate, "\n")] = 0;

        printf("3. 성별(여성이면 F 또는 남성이면 M): ");
        scanf(" %c", &candidates[i].gender);
        getchar(); // 개행 문자 제거

        printf("4. 메일 주소: ");
        fgets(candidates[i].email, sizeof(candidates[i].email), stdin);
        candidates[i].email[strcspn(candidates[i].email, "\n")] = 0;

        printf("5. 국적: ");
        fgets(candidates[i].nationality, sizeof(candidates[i].nationality), stdin);
        candidates[i].nationality[strcspn(candidates[i].nationality, "\n")] = 0;

        printf("6. BMI: ");
        scanf("%f", &candidates[i].bmi);
        getchar(); // 개행 문자 제거

        printf("7. 주 스킬: ");
        fgets(candidates[i].main_skill, sizeof(candidates[i].main_skill), stdin);
        candidates[i].main_skill[strcspn(candidates[i].main_skill, "\n")] = 0;

        printf("8. 보조 스킬: ");
        fgets(candidates[i].sub_skill, sizeof(candidates[i].sub_skill), stdin);
        candidates[i].sub_skill[strcspn(candidates[i].sub_skill, "\n")] = 0;

        printf("9. 한국어 등급(TOPIK): ");
        scanf("%d", &candidates[i].korean_level);
        getchar(); // 개행 문자 제거

        printf("10. MBTI: ");
        fgets(candidates[i].mbti, sizeof(candidates[i].mbti), stdin);
        candidates[i].mbti[strcspn(candidates[i].mbti, "\n")] = 0;

        printf("11. 소개: ");
        fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);
        candidates[i].introduction[strcspn(candidates[i].introduction, "\n")] = 0;

        calculate_age(&candidates[i]); // 만 나이 계산

        printf("=================================\n");
        i++;
    }

    // 후보자 데이터 출력
    printf("\n####################################\n");
    printf("[%s] 오디션 후보자 데이터 조회\n", group_name);
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
    printf("=============================================================================================\n");

    for (int j = 0; j < MAX_CANDIDATES; j++) {
        printf("%s (%d) | %s | %c | %s | %s | %.1f | %s | %s | %s | %s |\n",
            candidates[j].name, candidates[j].age,
            candidates[j].birthdate, candidates[j].gender,
            candidates[j].email, candidates[j].nationality,
            candidates[j].bmi, candidates[j].main_skill,
            candidates[j].sub_skill, (candidates[j].korean_level == 0) ? "원어민" : "비원어민",
            candidates[j].mbti);
        printf("        -------------------------------------------------------------------------------------\n");
        printf("%s\n", candidates[j].introduction);
        printf("---------------------------------------------------------------------------------------------\n");
    }

    return 0;
}
