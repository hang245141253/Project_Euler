#include <cstdio>
#define MAX_N 2000000

long long init(int *arr) {
    long long sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!arr[i])    arr[++arr[0]] = i, sum += i;
        for (int j = 1; j <= arr[0] && arr[j] * i < MAX_N; j++) {
            arr[arr[j] * i] = 1;
            if (i % arr[j] == 0)    break;
        }
    }
    return sum;
}

int main() {
    int arr[MAX_N] = {};
    printf("sum = %lld\n", init(arr));
    return 0;
}