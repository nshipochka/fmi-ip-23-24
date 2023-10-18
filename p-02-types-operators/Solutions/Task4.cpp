#include<iostream>
int main() {
	int n;
	std::cin >> n;

	int d3 = n % 10;
	int d2 = n / 10 % 10;
	int d1 = n / 100;

	char c3 = d3 + 'a';
	char c2 = d2 + 'a';
	char c1 = d1 + 'a';

	std::cout << c1 << c2 << c3 << std::endl;

	return 0;
}