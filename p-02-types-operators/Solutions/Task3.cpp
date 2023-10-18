#include<iostream>
int main() {
	char c1, c2, c3;
	std::cin >> c1 >> c2 >> c3;

	int n = (c1 - '0') * 100 + (c2 - '0') * 10 + (c3 - '0');
	std::cout << n;
	return 0;
}