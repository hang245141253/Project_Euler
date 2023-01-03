/*
If we list all the natural numbers below 10 that are multiples of 3 or 5,
 we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>

int is_value(int x) {
    if (x % 3 == 0 || x % 5 == 0) return 1;
    return 0;
}

int main() {
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        if (!is_value(i)) continue; // 炫技 节约一个缩进
        sum += i;
    }
    printf("%d\n", sum);

    //  等差数列
    int sum3 = (3 + 999) * 333 / 2;
    int sum5 = (5 + 995) * 199 / 2;
    int sum15 = (15 + (1000 / 15) * 15) * (1000/ 15) / 2;
    printf("%d\n", sum3 + sum5 - sum15);

    return 0;
}