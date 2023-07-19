#include <cstdio>

bool F(int x) {
    int tmp = x, sum = 0, num;
    while (tmp) {
        num = tmp % 10;
        sum += num * num * num * num * num;
        tmp /= 10;
    }
    return sum == x;
}

int main(void) {
    int sum = 0;
    for (int i = 2; i <= 354294; i++) {
        F(i) && (sum += i);
    }
    printf("%d\n", sum); // 443839
    return 0;
}