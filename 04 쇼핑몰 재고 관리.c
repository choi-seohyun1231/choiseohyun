#include <stdio.h>
#include <string.h>

#define N 5  // 상품 개수 (5개 고정)
#define NAME_LEN 50  // 상품명 최대 길이 (50자로 제한)

// 함수 선언
void 입고(int *in, int *left, int *totalIn);
void 판매(int *sold, int *left, int *totalSold);
void 상품현황(int *sold, int *left, int totalSold, int totalIn, char names[N][NAME_LEN]);
void 상품명입력(char names[N][NAME_LEN]);

int main() {
    int in[N] = {0}, sold[N] = {0}, left[N] = {0};
    int menu, totalSold = 0, totalIn = 0;
    char names[N][NAME_LEN] = {0};  // 상품명을 저장할 배열

    while (1) {
        // 메뉴 출력
        printf("\n[쇼핑몰 관리 프로그램]\n원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료): ");
        scanf("%d", &menu);

        if (menu == 1) {
            // 입고 메뉴
            입고(in, left, &totalIn);
        } else if (menu == 2) {
            // 판매 메뉴
            판매(sold, left, &totalSold);
        } else if (menu == 3) {
            // 상품 현황 메뉴
            상품현황(sold, left, totalSold, totalIn, names);
        } else if (menu == 4) {
            // 상품명 입력 메뉴
            상품명입력(names);
        } else if (menu == 5) {
            // 종료 메뉴
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}

// 입고 함수
void 입고(int *in, int *left, int *totalIn) {
    int subMenu, id;

    printf("입고수량 입력: 전체 상품 입고수량 입력(1), 개별 상품 입력(2): ");
    scanf("%d", &subMenu);

    if (subMenu == 1) {
        // 전체 상품 입고수량 입력
        printf("전체 상품의 입고수량을 입력하세요: ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &in[i]);
            left[i] += in[i];
            *totalIn += in[i];
        }
    } else if (subMenu == 2) {
        // 개별 상품 입고수량 입력
        printf("입고할 상품 ID 입력 (1 ~ 5): ");
        scanf("%d", &id);
        if (id >= 1 && id <= 5) {
            printf("상품 ID %d의 입고 수량 입력: ", id);
            scanf("%d", &in[id - 1]);
            left[id - 1] += in[id - 1];
            *totalIn += in[id - 1];
        } else {
            printf("잘못된 ID입니다.\n");
        }
    }
}

// 판매 함수
void 판매(int *sold, int *left, int *totalSold) {
    int subMenu, id;

    printf("판매수량 입력: 전체 상품 판매수량 입력(1), 개별 상품 입력(2): ");
    scanf("%d", &subMenu);

    if (subMenu == 1) {
        // 전체 상품 판매수량 입력
        printf("전체 상품의 판매수량을 입력하세요: ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &sold[i]);
            if (sold[i] > left[i]) {
                printf("상품 %d의 재고가 부족합니다.\n", i + 1);
            } else {
                left[i] -= sold[i];
                *totalSold += sold[i];
            }
        }
    } else if (subMenu == 2) {
        // 개별 상품 판매수량 입력
        printf("판매할 상품 ID 입력 (1 ~ 5): ");
        scanf("%d", &id);
        if (id >= 1 && id <= 5) {
            printf("상품 ID %d의 판매 수량 입력: ", id);
            scanf("%d", &sold[id - 1]);
            if (sold[id - 1] > left[id - 1]) {
                printf("재고가 부족합니다.\n");
            } else {
                left[id - 1] -= sold[id - 1];
                *totalSold += sold[id - 1];
            }
        } else {
            printf("잘못된 ID입니다.\n");
        }
    }
}

// 상품현황 함수 (상품명 포함)
void 상품현황(int *sold, int *left, int totalSold, int totalIn, char names[N][NAME_LEN]) {
    printf("\n[상품현황]\n재고현황: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", left[i]);
    }

    printf("\n총 판매량: %d (총 판매율: %.2f%%)", totalSold, (totalSold * 100.0) / totalIn);

    int maxSold = sold[0], minSold = sold[0];
    int maxId = 0, minId = 0;

    // 가장 많이/적게 판매된 상품 찾기
    for (int i = 1; i < N; i++) {
        if (sold[i] > maxSold) {
            maxSold = sold[i];
            maxId = i;
        }
        if (sold[i] < minSold) {
            minSold = sold[i];
            minId = i;
        }
    }

    // ID, 상품명, 판매량 순으로 출력
    printf("\n가장 많이 판매된 상품: ID %d, 상품명: %s, 판매량: %d", maxId + 1, names[maxId], maxSold);
    printf("\n가장 적게 판매된 상품: ID %d, 상품명: %s, 판매량: %d", minId + 1, names[minId], minSold);

    // 재고 부족 경고를 가장 적게 판매된 상품 아래에 출력
    for (int i = 0; i < N; i++) {
        if (left[i] <= 2) {  // 재고가 2 이하인 경우
            printf("\n상품 ID %d: 상품명: %s 재고부족 (재고 %d)", i + 1, names[i], left[i]);
        }
    }
}

// 상품명 입력 함수
void 상품명입력(char names[N][NAME_LEN]) {
    printf("상품명을 순서대로 입력하세요:\n");
    for (int i = 0; i < N; i++) {
        printf("상품 ID %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // 공백 포함 입력 받기
    }
}

