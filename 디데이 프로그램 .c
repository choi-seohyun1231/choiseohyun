#include <stdio.h>
#include <time.h>

void calculate_d_day(int year, int month, int day) {
    // 목표일을 설정
    struct tm target_date = {0};
    target_date.tm_year = year - 1900;  // 연도는 1900년 기준
    target_date.tm_mon = month - 1;     // 월은 0부터 시작
    target_date.tm_mday = day;

    // 현재 날짜와 시간 가져오기
    time_t now = time(NULL);
    struct tm *today = localtime(&now);

    // 목표일을 time_t로 변환
    time_t target_time = mktime(&target_date);
    double diff_in_seconds = difftime(target_time, now);

    // 일 수 계산
    int remaining_days = (int)(diff_in_seconds / (60 * 60 * 24));

    // 결과 출력
    if (remaining_days > 0) {
        printf("D-%d일 남았습니다.\n", remaining_days);
    } else if (remaining_days == 0) {
        printf("오늘이 D-Day입니다!\n");
    } else {
        printf("D+%d일이 지났습니다.\n", -remaining_days);
    }
}

int main() {
    int year, month, day;
    printf("목표 연도, 월, 일을 입력하세요 (예: 2024 12 25): ");
    scanf("%d %d %d", &year, &month, &day);

    calculate_d_day(year, month, day);
    return 0;
}
