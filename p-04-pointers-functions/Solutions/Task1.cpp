#include <iostream>
int interval_sum(int m, int n) {
	if (m > n)
		throw std::invalid_argument("M is larger than N");

	int sum = 0;
	for (; m < n; ++m) {
		sum += m;
	}

	return sum;
}

int main() {
	int a, b;
	std::cin >> a >> b;

	try {
		std::cout << interval_sum(a, b);
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}

	return 0;
}