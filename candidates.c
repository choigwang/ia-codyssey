#include <stdio.h>
#include <stdlib.h>

// 후보자 정보를 저장하는 구조체 정의
typedef struct {
    char name[50];
    char birthdate[11];  // YYYY/MM/DD 형식
    char gender;
    char email[50];
    char nationality[30];
    float bmi;
    char main_skill[30];
    char sub_skill[30];
    int topik;
    char mbti[5];
    char introduction[255];
    int age;  // 만 나이 저장
} Candidate;

// 나이를 계산하는 함수 (만 나이)
int calculate_age(const char* birthdate) {
    int birth_year, birth_month, birth_day;
    int current_year = 2024, current_month = 10, current_day = 7; // 현재 날짜 하드코딩

    // 생년월일을 YYYY/MM/DD 형식으로 분리하여 저장
    sscanf_s(birthdate, "%d/%d/%d", &birth_year, &birth_month, &birth_day);

    // 만 나이 계산
    int age = current_year - birth_year;
    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        age--;  // 생일이 지나지 않았으면 나이를 1 줄임
    }

    return age;
}

// 후보자 정보를 입력하는 함수
void input_candidate(Candidate* candidate, int index) {
    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");
    printf("첫 번째 후보자의 정보를 입력합니다.\n");
    printf("---------------------------------\n");

    printf("1. 성명: ");
    fgets(candidate->name, sizeof(candidate->name), stdin);
    candidate->name[strcspn(candidate->name, "\n")] = '\0';  // 개행 문자 제거

    printf("2. 생일(YYYY/MM/DD 형식): ");
    fgets(candidate->birthdate, sizeof(candidate->birthdate), stdin);
    candidate->birthdate[strcspn(candidate->birthdate, "\n")] = '\0';  // 개행 문자 제거

    printf("3. 성별(여성이면 F 또는 남성이면 M): ");
    scanf_s(" %c", &candidate->gender, 1);  // 크기 1 추가
    getchar();  // 버퍼 정리

    printf("4. 메일 주소: ");
    fgets(candidate->email, sizeof(candidate->email), stdin);
    candidate->email[strcspn(candidate->email, "\n")] = '\0';  // 개행 문자 제거

    printf("5. 국적: ");
    fgets(candidate->nationality, sizeof(candidate->nationality), stdin);
    candidate->nationality[strcspn(candidate->nationality, "\n")] = '\0';  // 개행 문자 제거

    printf("6. BMI: ");
    scanf_s("%f", &candidate->bmi);
    getchar();  // 버퍼 정리

    printf("7. 주 스킬: ");
    fgets(candidate->main_skill, sizeof(candidate->main_skill), stdin);
    candidate->main_skill[strcspn(candidate->main_skill, "\n")] = '\0';  // 개행 문자 제거

    printf("8. 보조 스킬: ");
    fgets(candidate->sub_skill, sizeof(candidate->sub_skill), stdin);
    candidate->sub_skill[strcspn(candidate->sub_skill, "\n")] = '\0';  // 개행 문자 제거

    printf("9. 한국어 등급(TOPIK): ");
    scanf_s("%d", &candidate->topik);
    getchar();  // 버퍼 정리

    printf("10. MBTI: ");
    fgets(candidate->mbti, sizeof(candidate->mbti), stdin);
    candidate->mbti[strcspn(candidate->mbti, "\n")] = '\0';  // 개행 문자 제거

    printf("11. 소개: ");
    fgets(candidate->introduction, sizeof(candidate->introduction), stdin);
    candidate->introduction[strcspn(candidate->introduction, "\n")] = '\0';  // 개행 문자 제거

    // 만 나이 계산 및 저장
    candidate->age = calculate_age(candidate->birthdate);
}

// 후보자 정보를 출력하는 함수
void display_candidates(Candidate candidates[], int count, const char* group_name) {
    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 조회\n", group_name);
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일   | 성별 | 메   일            | 국적   | BMI  | 주스킬  | 보조스킬 | TOPIK  | MBTI |\n");
    printf("=============================================================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%s(%d) | %s | %c   | %s | %s | %.1f | %s  | %s  | %d | %s |\n", 
                candidates[i].name, candidates[i].age, candidates[i].birthdate, candidates[i].gender, 
                candidates[i].email, candidates[i].nationality, candidates[i].bmi, 
                candidates[i].main_skill, candidates[i].sub_skill, candidates[i].topik, 
                candidates[i].mbti);
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%s\n", candidates[i].introduction);
        printf("---------------------------------------------------------------------------------------------\n");
    }
}

int main() {
    Candidate candidates[6];
    char group_name[50];

    // 오디션 그룹명 입력
    printf("지원하는 오디션 그룹명을 입력하세요: ");
    fgets(group_name, sizeof(group_name), stdin);
    group_name[strcspn(group_name, "\n")] = '\0';  // 개행 문자 제거

    // 후보자 정보 입력
    for (int i = 0; i < 6; i++) {
        input_candidate(&candidates[i], i + 1);
    }

    // 후보자 정보 출력
    display_candidates(candidates, 6, group_name);

    return 0;
}
