#include<iostream>
void print_pascal_triangle(int row) {
	int binomial_coeff = 1;

	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= row - i; ++j)
			std::cout << ' ';
		
		for (int j = 1; j <= i; ++j) {
			if (i == 1 || j == 1)
				binomial_coeff = 1;

			else
				binomial_coeff = binomial_coeff * (i - j + 1) / (j - 1);
			
			std::cout << binomial_coeff << ' ';
		}

		std::cout << std::endl;
	}
}

int main() {
	print_pascal_triangle(5);
	return 0;
}