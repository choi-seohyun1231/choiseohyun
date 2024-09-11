/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
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

    return 0;
}


