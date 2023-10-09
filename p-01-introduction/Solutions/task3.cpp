#include<iostream>
int main() {
	double side, h;
	std::cin >> side >> h;

	std::cout << side * h / 2;

	double a, b, c;
	std::cin >> a >> b >> c;

	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));

	std::cout << s << std::endl;

	return 0;
}