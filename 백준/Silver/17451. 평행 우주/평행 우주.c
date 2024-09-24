#include <stdio.h>

int n;
int arr[300001];

int main(void) {
    // n 입력 받기
    scanf("%d", &n);

    // 배열 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // res에 마지막 값 저장
    long long res = arr[n - 1];

    // 뒤에서 두번째부터 역순으로 계산
    for (int i = n - 2; i >= 0; i--) {
        if (res % arr[i] == 0)
            continue; // 이미 배수면 그대로 넘어감
        long long m = res / arr[i] + 1; // 배수가 되도록 업데이트
        res = arr[i] * m;
    }

    // 결과 출력
    printf("%lld\n", res);

    return 0;
}
