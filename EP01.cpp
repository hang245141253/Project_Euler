/*
If we list all the natural numbers below 10 that are multiples of 3 or 5,
 we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <iostream>

using namespace std;

int is_val(int i) {
    if (!(i % 3) || !(i % 5)) return 1;
    return 0;
}

int is_val2(int n) {
    int sum3 = (3 + (--n / 3) * 3) * (n / 3) / 2;
    int sum5 = (5 + (n / 5) * 5) * (n / 5) / 2;
    int sum15 = (15 + (n / 15) * 15) * (n / 15) / 2;
    return sum3 + sum5 - sum15;
}

int main() {
    int sum = 0;
    int n = 1000;
    for (int i = 0; i < n; i++) {
        if (!is_val(i)) continue; // 节约一个缩进
        sum += i;
    }
    cout << sum << endl;
    cout << is_val2(n) << endl;

    return 0;
}
