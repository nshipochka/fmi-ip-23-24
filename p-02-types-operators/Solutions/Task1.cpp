#include<iostream>
int main() {
	int cm;
	std::cin >> cm;

	double m = (double)cm / 100;
	double km = m / 1000;

	std::cout << "m: " << m << ", km: " << km << std::endl;

	return 0;
}