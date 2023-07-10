#include <cstdio>
#include <cstdlib>

char* DtoB(int x) {
    int sum = 0;
    char *arr = (char *)malloc(sizeof(char) * 64);
    arr[0] = 0;
    while (x) {
        arr[++arr[0]] = x % 2 + '0';
        x >>= 1;
    }
    // for (int j = arr[0]; j >= 1; j--) {
    //     printf("%c", arr[j]);
    // }
    // putchar('\n');
    return arr;
}

bool Dec_Palindromic(unsigned int x) {
    unsigned int tmp = x, sum = 0;
    while (tmp) {
        sum = sum * 10 + tmp % 10;
        tmp /= 10;
    }
    return sum == x;
}

bool Bin_Palindromic(char* arr) {
    for (int i = 1, j = arr[0]; i <= j; i++, j--) {
        if (arr[i] == arr[j])   continue;
        return false;
    }
    return true;
}


int main() {
    int sum = 0;
    for (int i = 1; i <= 1000000; i++) {
        Dec_Palindromic(i) && Bin_Palindromic(DtoB(i)) && (sum += i);
    }
    printf("sum is = %d\n", sum);  // 872187
    return 0;
}