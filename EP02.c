/*
Each new term in the Fibonacci sequence is generated by adding the previous two
terms. By starting with 1 and 2, the first 10 terms will be:

                1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed
four million, find the sum of the even-valued terms.
*/

#include <stdio.h>
#define N 4000000

int main() {
    // 方法一:用数组遍历
    printf("方法一:用数组\n");
    int fib[35];
    fib[0] = 1;
    fib[1] = 2;
    int sum1 = 0;
    for (int i = 2; i <= 35; i++) {
        if (fib[i - 1] + fib[i - 2] > N) break;
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i <= 35; i++) {
        if (fib[i] & 1) continue;  // & 1 <==> % 2 （二进制偶数0 & 1 = 0 二进制奇数1 & 1 = 1）
        sum1 += fib[i];
        printf("%d n=%d\n", fib[i], i);
    }
    printf("sum=%d\n\n", sum1);

    // 方法二:变量交替
    printf("方法二:变量交替\n");
    int a = 1, b = 2;
    int sum2 = 2;
    while (a + b < N) {
        b = a + b;
        a = b - a;
        if (b & 1) continue;
        sum2 += b;
    }
    printf("a=%d, b=%d\n", a, b);
    printf("sum=%d\n\n", sum2);

    // 方法三：滚动数组
    printf("方法三：滚动数组\n");
    int loop[3] = {1, 2};
    int sum3 = 2;
    for (int i = 2; loop[(i - 1) % 3] + loop[(i - 2) % 3] < N; i++) {
        loop[i % 3] = loop[(i - 1) % 3] + loop[(i - 2) % 3];
        if (!(loop[i % 3] & 1)) sum3 += loop[i % 3];
        // for (int i = 0; i < 3; i++) {   // 遍历数组
        //     printf("%d ", loop[i % 3]);
        // }
        // printf("\n");
    }
    printf("sum=%d\n\n", sum3);

    return 0;
}