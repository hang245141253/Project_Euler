#include <iostream>
using namespace std;

#define MAX_N 10

int fac[MAX_N + 5]; // 阶乘表
int num[MAX_N + 5]; // 标记为1表示没用过，标记为0表示用过了

void init(int n) {
    fac[0] = 1;
    num[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    } return ;
}

int get_num(int k, int fac, int &idx) {
    int step = k / fac;
    idx = 0;
    // 扫描num标记，使得idx跳跃到没有被标记的数字
    for (int t = 0; t <= step; idx += (t <= step)) { // 技巧：idx += (t <= step),防止最后多+1
        t += num[idx];  // 如果num[]=0 相当于continue, idx始终会++
        // if (!num[idx])  continue;
        // t++;
    }
    k %= fac;           // 获取剩余次数
    num[idx] = 0;       // 将已经用过的位数标记掉
    return k;
}

int main() {
    init(MAX_N);
    int k = 999999; // 100w - 1次跳跃
    for (int i = MAX_N - 1; i >= 0; i--) {
        int idx;
        k = get_num(k, fac[i], idx);
        printf("%d", idx);
    }
    putchar('\n');  // 2783915460
    
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