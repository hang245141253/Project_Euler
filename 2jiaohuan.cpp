#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2;
    int sum = 2;
    while (b < 4000000) {
        b = a + b;
        a = b - a;
        if (!(b & 1))   sum += b;
    }
    cout << sum << endl;
    return 0;
}