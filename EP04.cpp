/*
Largest palindrome product
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 
2-digit numbers is 9009 = 91 x 99.

Find the largest palindrome made from the product
of two 3-digit numbers.
*/
#include <cstdio>

bool reverse(int n) {
    int re = 0, tmp = n;
    while (tmp) {
        re = re * 10 + tmp % 10;
        tmp /= 10; 
    }
    return n == re;
}

int main() {
    int ans = 0;
    for (int i = 999; i > 99; i--) {
        for (int j = i; j > 99; j--) { // 不要j = 999, 会有很多重复值
            if (reverse(i * j) && ans < i * j) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}