#include<iostream>
int main() {
	int a, b;
	std::cin >> a >> b;

	int temp = a;
	a = b;
	b = temp;

	std::cout << "a: " << a << ", b: " << b << std::endl;

	a = a - b;
	b = b + a;
	a = b - a;

	std::cout << "a: " << a << ", b: " << b << std::endl;

	return 0;
}