#include <iostream>
using namespace std;

#define MAX_N 10

int fac[MAX_N + 5];
int num[MAX_N + 5]; // 标记为1表示可用，标记为0表示不可用

void init(int n) {
    fac[0] = 1;
    num[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    }

    // // output
    // for (int i = 0; i < MAX_N; i++) {
    //     printf("fac[%d] = %d\n", i, fac[i]);
    // }
    // for (int i = 0; i < MAX_N; i++) {
    //     printf("num[%d] = %d\n", i, num[i]);
    // }

    return ;
}

int get_num(int k, int n, int &x) {
    int step = k / n;
    x = 0;
    for (int t = 0; t <= step; x += (t <= step)) {
        t += num[x];
    }
    k %= n;
    num[x] = 0;
    return k;
}

int main() {
    init(MAX_N);
    int k = 999999; // 100w - 1次跳跃
    for (int i = MAX_N - 1; i >= 0; i--) {
        int x;
        k = get_num(k, fac[i], x);
        cout << x;
    }
    cout << endl;
    
    return 0;
}

/*
#include <iostream>  
#include <algorithm>  
using namespace std;  

int main() {
    int k = 1000000;
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  
    do {  
        for (int i = 0; i < 10; i++) {
            printf("%d", num[i]);
        } putchar('\n');
        k--;
        if (!k) break;
    } while (next_permutation(num, num + 10));  
    
    return 0;  
}
*/