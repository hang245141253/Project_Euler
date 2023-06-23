#include <iostream>
#define MIN 143

long long Triangle(long long n) {
	return n * (n + 1) >> 1;
}

long long Pentagonal(long long n) {
	return n * (3 * n - 1) >> 1;
}

long long Hexagonal(long long n) {
	return n * (2 * n - 1);
}

//函数指针版本二分查找 找到返回1 没找到返回0 
long long binary_search(long long (*arr)(long long), int max, long long x) {
	int min = MIN, mid;
	while (min <= max) {
		mid = (min + max) >> 1;
		if (arr(mid) == x)	return 1;
		if (arr(mid) < x)	min = mid + 1;
		else				max = mid - 1;
	}
	return 0;	
}

int main() {
	int n = MIN; //六边形的项数
	while (n++) {
		long long num = Hexagonal(n);
		if (!binary_search(Pentagonal, n * 2, num)) continue;
		printf("%lld\n", num);
		break;
	} 
	return 0;
}