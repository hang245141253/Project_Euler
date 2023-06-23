#include <iostream>
using namespace std;

int fib[44];

int main() {
    fib[1] = 1, fib[2] = 2;
    int sum = 2;
    for (int i = 3; i < 44 && fib[i - 1] + fib[i - 2] < 4000000; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // & 1 <==> % 2 （二进制偶数0 & 1 = 0 二进制奇数1 & 1 = 1）
        if (!(fib[i] & 1)) sum += fib[i];
    }
    cout << sum << endl;
    for (int i = 1; i < 44; i++) {
        cout << fib[i] << endl;
    }
    return 0;
}