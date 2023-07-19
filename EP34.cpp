#include <cstdio>
#define MAX_N 2540160 //9! * 7

int num[10];

void init(int* num) {
    num[0] = 1;
    for (int i = 1; i < 10; i++) {
        num[i] = i * num[i - 1];
    } return ;
}

bool fac_sum(int n) {
    int sum = 0, tmp = n;
    while (n) {
        sum += num[n % 10];
        n /= 10;
    }
    return tmp == sum;
}

int main() {
    init(num);
    for (int i = 0; i < 10; i++) {
        printf("num[%d] = %d\n", i, num[i]);
    }
    int sum = 0;
    for (int i = 3; i < MAX_N; i++)  fac_sum(i) && (sum += i);
    printf("sum = %d\n", sum); // 40730
    return 0;
}