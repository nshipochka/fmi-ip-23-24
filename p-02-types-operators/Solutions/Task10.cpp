#include <iostream>
int main() {
	int n;
	std::cin >> n;

	int d3 = n % 10;
	int d2 = n / 10 % 10;
	int d1 = n / 100;

	int res1 = (d1 * 10 + d2) * d3;
	int res2 = d1 * (d2 * 10 + d3);

	std::cout << (res1 > res2) ? res1 : res2;

	return 0;
}