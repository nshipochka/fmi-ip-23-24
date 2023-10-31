#include <iostream>

int gcd(int a, int b) {
	if (a == 0)
		return b;

	if (b == 0)
		return a;

	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	return 0;
}