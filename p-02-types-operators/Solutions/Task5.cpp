#include<iostream>
int main() {
	int n;
	std::cin >> n;

	std::cout << (n % 10 == 7) + (n / 10 % 10 == 7) + (n / 100 % 10 == 7);

	return 0;
}