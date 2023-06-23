/*
Largest prime factor
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
*/
#include <cstdio>
#define N 600851475143LL

int main() {
    // 求m的最大质因数
    long long num = N;
    int i = 2; //即算法中描述的k
    while (num > 1) {
        if (!(num % i)) num /= i;
        else i++; // k是递增的
    }
    printf("%d\n", i);
    return 0;
}