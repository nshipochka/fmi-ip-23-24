#include<iostream>
int main() {
	int n;
	std::cin >> n;

	//вариант 1
	std::cout << n * n * n << std::endl;

	//вариант 2 (по-уместен за по-големи степени)
	std::cout << pow(n, 3) << std::endl;

	return 0;
}