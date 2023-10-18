#include<iostream>
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    double d = sqrt(b * b - 4 * a * c);

    double x1 = (-b - d) / (2 * a);
    double x2 = (-b + d) / (2 * a);

    std::cout << x1 << std::endl;
    std::cout << x2 << std::endl;
	return 0;
}