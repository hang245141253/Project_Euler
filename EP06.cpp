/*
Sum square difference
The sum of the squares of the first ten natural numbers is,
    pow(1, 2) + pow(2, 2) + ... + pow(10, 2) = 385

The square of the sum of the first ten natural numbers is,
    pow((1 + 2 + ... + 10), 2) = pow(55, 2) = 3025

Hence the difference between the sum of the squares of the first 
ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first 
one hundred natural numbers and the square of the sum.
*/
#include <cstdio>

int main() {
    int pow_s = 0, sum_p = 0;
    sum_p = (1 + 100) * 100 / 2;
    // f^2(i) = (2n^3 + 3n^2 + n) / 6
    pow_s = (2 * (100 * 100 * 100) + 3 * (100 * 100) + 100) / 6;  
    // 暴力循环
    // for (int i = 1; i < 101; i++) {
    //     pow_s += i * i;
    //     sum_p += i;
    // }
    printf("%d\n", sum_p * sum_p - pow_s);
    return 0; 
}