#include <cstdio>
#define MAX_N 5

void show(int (*arr)[MAX_N]) {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            j && printf("_");
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[MAX_N + 5][MAX_N] = {};
    show(arr);
    return 0;
}