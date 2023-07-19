#include <cstdio>
#define MAX_N 150000

void shu_init(int* arr) {
    for (int i = 2; i < MAX_N; i++) {
        if (arr[i]) continue;
        arr[++arr[0]] = i;
        for (int j = i; j <= MAX_N / i; j++) {
            arr[j * i] = 1;
        }
    }
    return ;
}

void xian_init(int *arr) {
	for (int M = 2; M < MAX_N; M++) {
		if (!arr[M]) arr[++arr[0]] = M;
		for (int P = 1; P <= arr[0] && arr[P] * M < MAX_N; P++) {
			arr[arr[P] * M] = 1;
			if (!(M % arr[P])) break;
		}
	}
}


void init(int* arr) {
    for (int i = 2; i < MAX_N; i++) {  //标记用的最大因子M
        if (!arr[i]) arr[++arr[0]] = i;
        for (int j = 1; j <= arr[0] && arr[j] * i < MAX_N; j++) { // 遍历质数表P
            arr[arr[j] * i] = 1;
            if (i % arr[j] == 0) break;
        }
    }
}

int main() {
    int arr[MAX_N] = {0};
    init(arr);
    printf("arr[%d]= %d\n", 10001, arr[10001]);
    return 0;
}