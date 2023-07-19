/*
2520 is the smallest number that can be divided by each of the numbers from 
1 to 10  without any remainder.

What is the smallest positive number that is evenly divisible by all of the
numbers from 1 to 20 ?
*/
#include <cstdio>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int ans = 1;
    for (int i = 1; i <= 20; i++) {
        if (ans % i == 0) continue;  // 已经是倍数了不要乘，否则不是最小公倍数
        ans *= i / gcd(ans, i);
    }
    printf("ans = %d\n", ans); // 232792560
    return 0;
}