#include<iostream>
int main() {
	int n;
	std::cin >> n;

	std::cout << n % 10 << '-' 
		<< n / 10 % 10 << '-' 
		<< n / 100 % 10 << '-' 
		<< n / 1000 << std::endl;

	return 0;
}