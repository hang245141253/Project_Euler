#include <cstdio>
#define MAX_N 200000

// 暴力循环
int is_prime(int i) {
    if (i <= 1) return 0;
    for (int j = 2;  j < i; j++) { //优化 j * j <= i
        if (i % j == 0) return 0;
    }
    return 1;
}

void init(int *arr) {
    for (int i = 2; i <= MAX_N; i++) {
        if (arr[i]) continue;
        // arr[++arr[0]] = i;
        for (int j = 2 * i; j <= MAX_N; j += i) { //优化 j = i * i, 再优化(j = i; j <= MAX_N / i; j++) arr[i * j] = 1; 
            arr[j] = 1;
        }
    }
}

void linear(int *arr) {
    for (int i = 2; i <= MAX_N; i++) {
        if (!arr[i])    arr[++arr[0]] = i;
        for (int j = 1; j <= arr[0] && arr[j] * i <= MAX_N; j++) {
            arr[arr[j] * i] = 1;
            if (i % arr[j] == 0)    break;
        }
    }
}

int main() {
    int arr[MAX_N + 5] = {};
    init(arr);

    int cnt = 1, i = 1;
    while (cnt <= 10001) {
        i++;
        if (is_prime(i))    cnt++;
        // if (!arr[i])    cnt++;
    }
    printf("%d\n", i);

    // linear(arr);
    // printf("%d\n", arr[10001]); 

    return 0;
}