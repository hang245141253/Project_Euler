/*
Largest prime factor
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
*/
#include <cstdio>
#define N 600851475143LL

int main() {
    long long num = N;
    int i = 2;
    while (i * i <= num) {
        while(!(num % i))   num /= i;
        i++;
    }
    if (num == 1)  num = --i; // num为平方数时会被算成1
    printf("%d\n", num);
    return 0;
}

// 暴力循环
// int main() {
//     long long num = N;
//     int i = 2, ans = 0;
//     while (num > 1) {
//         if (!(num % i)) num /= i, ans++;
//         else i++, ans++; // k是递增的
//     }
//     printf("%d, cut = %d\n", i, ans);
//     return 0;
// }