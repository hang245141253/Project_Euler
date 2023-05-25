/*
Largest prime factor
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
*/
#include <stdio.h>

int main() {
    // 求m的最大质因数
    long long m = 600851475143;
    int k = 2; //即算法中描述的k
    while (m > 1){
        if (m % k == 0){
            m /= k;
        }
        else{
            ++k; // k是递增的
        }
    }
    printf("%d", k);
    return 0;
}