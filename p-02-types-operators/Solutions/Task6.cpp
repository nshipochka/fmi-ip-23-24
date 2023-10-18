#include<iostream>
int main() {
	char c;
	std::cin >> c;

	if ('a' < c && c < 'z') {
		std::cout << "Small letter\n";
	}
	else if ('A' < c && c < 'Z') {
		std::cout << "Capital letter\n";
	}
	else if ('0' < c && c < '9') {
		std::cout << "Digit\n";
	}
	else {
		std::cout << "Another symbol\n";
	}

	return 0;
}