#include <iostream>
using namespace std;

int main() {
    int arr[3] = {1, 2, 0};
    int sum = 2;
    for (int i = 2; arr[(i - 1) % 3] + arr[(i - 2) % 3] < 4000000; i++) {
        arr[i % 3] = arr[(i - 1) % 3] + arr[(i - 2) % 3];
        if (!(arr[i % 3] & 1))  sum += arr[i % 3];
    }
    cout << sum << endl;
    return 0;
}