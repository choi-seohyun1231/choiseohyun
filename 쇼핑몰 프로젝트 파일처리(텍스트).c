#include <stdio.h>
#include <string.h>

#define N 5
#define NAME_LEN 50
#define FILE_NAME "data.txt"

void 입고(int *in, int *left, int *totalIn, int prices[N], char names[N][NAME_LEN]);
void 판매(int *sold, int *left, int *totalSold, int prices[N], char names[N][NAME_LEN]);
void 개별현황(int *sold, int *left, int prices[N], char names[N][NAME_LEN]);
void 전체현황(int *sold, int *left, int totalSold, int totalIn, char names[N][NAME_LEN], int prices[N]);
void 파일에서_불러오기(int *in, int *sold, int *left, int *totalSold, int *totalIn, int prices[N], char names[N][NAME_LEN]);
void 파일에_저장하기(int *in, int *sold, int *left, int totalSold, int totalIn, int prices[N], char names[N][NAME_LEN]);

int main() {
    int in[N] = {0}, sold[N] = {0}, left[N] = {0};
    int prices[N] = {0}, totalSold = 0, totalIn = 0;
    char names[N][NAME_LEN] = {0};
    int menu;

    파일에서_불러오기(in, sold, left, &totalSold, &totalIn, prices, names);

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료): ");
        scanf("%d", &menu);

        if (menu == 1) {
            입고(in, left, &totalIn, prices, names);
        } else if (menu == 2) {
            판매(sold, left, &totalSold, prices, names);
        } else if (menu == 3) {
            개별현황(sold, left, prices, names);
        } else if (menu == 4) {
            전체현황(sold, left, totalSold, totalIn, names, prices);
        } else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            파일에_저장하기(in, sold, left, totalSold, totalIn, prices, names);
            break;
        } else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}

void 입고(int *in, int *left, int *totalIn, int prices[N], char names[N][NAME_LEN]) {
    int id;
    printf("입고할 상품 ID 입력 (1 ~ 5): ");
    scanf("%d", &id);

    if (id >= 1 && id <= N) {
        if (left[id - 1] == 0) {
            printf("신규 상품입니다. 상품명과 가격을 입력하세요.\n");
            printf("상품명: ");
            scanf(" %[^\n]", names[id - 1]);
            printf("가격: ");
            scanf("%d", &prices[id - 1]);
        }

        printf("상품 ID %d의 입고 수량 입력: ", id);
        scanf("%d", &in[id - 1]);
        left[id - 1] += in[id - 1];
        *totalIn += in[id - 1];
    } else {
        printf("잘못된 ID입니다.\n");
    }
}

void 판매(int *sold, int *left, int *totalSold, int prices[N], char names[N][NAME_LEN]) {
    int id;
    printf("판매할 상품 ID 입력 (1 ~ 5): ");
    scanf("%d", &id);

    if (id < 1 || id > N || left[id - 1] == 0) {
        printf("상품 ID가 없거나 존재하지 않습니다.\n");
        return;
    }

    printf("상품 ID %d의 판매 수량 입력: ", id);
    scanf("%d", &sold[id - 1]);
    if (sold[id - 1] > left[id - 1]) {
        printf("재고가 부족합니다.\n");
    } else {
        left[id - 1] -= sold[id - 1];
        *totalSold += sold[id - 1];
    }
}

void 개별현황(int *sold, int *left, int prices[N], char names[N][NAME_LEN]) {
    int id;
    printf("상세 정보를 확인할 상품 ID 입력 (1 ~ 5): ");
    scanf("%d", &id);

    if (id < 1 || id > N) {
        printf("잘못된 ID입니다.\n");
        return;
    }

    printf("상품 ID %d: 상품명: %s, 남은 재고: %d, 판매량: %d, 가격: %d\n", 
            id, names[id - 1], left[id - 1], sold[id - 1], prices[id - 1]);
}

void 전체현황(int *sold, int *left, int totalSold, int totalIn, char names[N][NAME_LEN], int prices[N]) {
    printf("\n[전체현황]\n");
    for (int i = 0; i < N; i++) {
        if (left[i] > 0) {
            printf("ID %d: 상품명: %3s, 남은 재고: %3d, 판매가: %d\n", i + 1, names[i], left[i], prices[i]);
        }
    }
    printf("\n총 판매량: %d, 총 판매율: %.2f%%\n", totalSold, (totalSold * 100.0) / totalIn);
}

void 파일에서_불러오기(int *in, int *sold, int *left, int *totalSold, int *totalIn, int prices[N], char names[N][NAME_LEN]) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("데이터 파일을 찾을 수 없습니다. 새로 생성합니다.\n");
        return;
    }

    fscanf(file, "%d %d", totalSold, totalIn);
    for (int i = 0; i < N; i++) {
        fscanf(file, "%d %d %d %d %s", &in[i], &sold[i], &left[i], &prices[i], names[i]);
    }

    fclose(file);
}

void 파일에_저장하기(int *in, int *sold, int *left, int totalSold, int totalIn, int prices[N], char names[N][NAME_LEN]) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("파일 저장에 실패했습니다.\n");
        return;
    }

    fprintf(file, "%d %d\n", totalSold, totalIn);
    for (int i = 0; i < N; i++) {
        fprintf(file, "%d %d %d %d %s\n", in[i], sold[i], left[i], prices[i], names[i]);
    }

    fclose(file);
}


