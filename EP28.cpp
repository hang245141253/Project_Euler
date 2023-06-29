#include <cstdio>
#define MAX_N 1001

void show(int (*arr)[MAX_N + 5]) {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            j && printf(" ");
            printf("%4d", arr[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int arr[MAX_N + 5][MAX_N + 5] = {};
    int n = 1, cnt = 1;
    int i = MAX_N / 2, j = MAX_N / 2;
    while (1) {
        for (int k = 0, tmp = ++cnt; k < tmp / 2; k++, j++) {
            arr[i][j] = n++;
        }
        // printf("n = %d\ni = %d, j = %d\n", n, i, j);
        if (n > MAX_N * MAX_N)  break;
        for (int k = 0, tmp = ++cnt; k < tmp / 2; k++, i++) {
            arr[i][j] = n++;
        }
        for (int k = 0, tmp = ++cnt; k < tmp / 2; k++, j--) {
            arr[i][j] = n++;
        }
        for (int k = 0, tmp = ++cnt; k < tmp / 2; k++, i--) {
            arr[i][j] = n++;
        }
    }
    // show(arr);
    int sum = 0;
    for (int x = 0, y = MAX_N - 1; x < MAX_N; x++, y--) {
        sum += arr[x][x] + arr[x][y];
    }
    printf("sum = %d\n", sum - arr[MAX_N / 2][MAX_N / 2]);

    //-----------------------船长方法-----------------------//

    // O(n)找规律, 四角求和4 * m * m - 6 * m + 6
    int ans = 1;
    for (int m = 3; m <= 1001; m += 2) {
        ans += 4 * m * m - 6 * m + 6;
    }
    printf("ans = %d\n", ans);
    
    // O(1)展开for循环 sum = 4*(3^2+5^2+...+1001^2) - 6*(3+5+...+1001) + C(一共500项)
    // 奇数平方和:Σ(2k - 1)^2, k∈[1, n] = n(n + 1)(n + 2) / 6
    printf("O(1)= %d\n",  1 + 4 * (1001 * 1002 * 1003 / 6 - 1) - 6 * ((3 + 1001) * 250) + 6 * 500);
    return 0;
}