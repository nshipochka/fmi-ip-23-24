#include <iostream>

float my_pow(float x, int n) {
	if (n < 0) {
		n = -n;
		x = 1 / x;
	}

	float x_powered = 1;
	for (int i = 0; i < n; ++i) {
		x_powered = x_powered * x;
	}

	return x_powered;
}

int main() {
	float number;
	int power;

	std::cin >> number >> power;
	std::cout << my_pow(number, power);

	return 0;
}