#include <iostream>

int sum_of_digits(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int product_of_digits(int n) {
	int prod = 1;
	while (n) {
		prod *= n % 10;
		n /= 10;
	}
}

void print_interval(int a, int b) {
	if (a > b)
		throw std::invalid_argument("No such interval!");

	for (; a <= b; ++a) {
		if (sum_of_digits(a) == product_of_digits(a))
			std::cout << a << std::endl;
	}
}