#include<iostream>
void print_tuples(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			std::cout << "(" << i << ", " << j << ")\n";
		}
	}
}

int main() {
	print_tuples(5);
	return 0;
}