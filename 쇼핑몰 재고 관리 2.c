/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    int n, id;

    // 1. 상품 개수 입력 (1 ~ 100 사이)
    printf("상품 개수 입력 (1 ~ 100): ");
    scanf("%d", &n);

    // 배열 선언: 입고 수량과 판매 수량
    int in[100], sold[100], left[100];

    // 2. 각 상품의 입고 수량을 입력받음
    printf("상품 별 입고수량 입력: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    // 3. 각 상품의 판매 수량을 입력받음
    printf("상품 별 판매수량 입력: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sold[i]);
    }

    // 4. 재고 수량 계산 (입고 수량 - 판매 수량)
    for (int i = 0; i < n; i++) {
        left[i] = in[i] - sold[i];
    }

    // 5. 특정 ID 입력 후 해당 상품의 재고 수량 출력
    printf("확인할 ID 입력 (1 ~ %d): ", n);
    scanf("%d", &id);

    if (id >= 1 && id <= n) {
        printf("ID %d 상품의 재고 수량: %d\n", id, left[id - 1]);
    } else {
        printf("잘못된 ID 입력\n");
    }

    // 6. 전체 상품의 재고 수량 출력
    printf("전체 상품의 재고 수량: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", left[i]);
    }
    printf("\n");

    // 7. 총 판매량과 총 입고량 계산
    int totalSold = 0, totalIn = 0;
    for (int i = 0; i < n; i++) {
        totalSold += sold[i];
        totalIn += in[i];
    }
    printf("총 판매량: %d\n", totalSold);

    // 8. 전체 판매율 계산 및 출력 (총 판매수량 / 총 입고수량) * 100
    if (totalIn != 0) {
        float overallSellRate = ((float) totalSold / totalIn) * 100;
        printf("전체 판매율: %.2f%%\n", overallSellRate);
    } else {
        printf("전체 판매율: 0.00%%\n");
    }

    // 9. 가장 많이, 적게 판매된 상품 출력
    int maxSold = sold[0], minSold = sold[0];
    int maxId = 1, minId = 1;
    for (int i = 1; i < n; i++) {
        if (sold[i] > maxSold) {
            maxSold = sold[i];
            maxId = i + 1;
        }
        if (sold[i] < minSold) {
            minSold = sold[i];
            minId = i + 1;
        }
    }
    printf("가장 많이 판매된 상품 ID: %d (판매량: %d)\n", maxId, maxSold);
    printf("가장 적게 판매된 상품 ID: %d (판매량: %d)\n", minId, minSold);

    // 10. 재고 부족 경고 출력 (재고 수량이 2 이하인 경우)
    int shortageFlag = 0;
    for (int i = 0; i < n; i++) {
        if (left[i] <= 2) {
            printf("상품 ID %d: 재고 부족 (%d)\n", i + 1, left[i]);
            shortageFlag = 1;
        }
    }
    if (!shortageFlag) {
        printf("재고 부족 상품이 없습니다.\n");
    }

    return 0;
}
