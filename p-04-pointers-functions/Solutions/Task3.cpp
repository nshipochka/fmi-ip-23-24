#include <iostream>
int absolute_value(int x) {
	return x > 0 ? x : -x;
}

char to_uppercase(char c) {
	if (c < 'a' && c > 'z')
		throw std::invalid_argument("Not a lowercase character");

	return c = c - ('a' - 'A');
}

int main() {
	return 0;
}