#include <iostream>

void read_until_100(int& x) {
	do {
		std::cin >> x;
	} while (x <= 100);
}

int main() {
	int x;
	read_until_100(x);
	std::cout << x;
}