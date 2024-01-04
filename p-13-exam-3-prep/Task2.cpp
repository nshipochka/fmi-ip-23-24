#include<iostream>

bool diff_digits(int curr_digit, int rest_of_n) {
	if (!rest_of_n)
		return true;

	if (curr_digit == rest_of_n % 10)
		return false;

	return diff_digits(curr_digit, rest_of_n / 10) // цифрата, за която сега проверяваме, дали се среща по-натам в числото
		&& diff_digits(rest_of_n % 10, rest_of_n / 10); // проверяваме за следващата цифра
}

bool diff_digits(int n) {
	return diff_digits(n % 10, n / 10);
}

int main() {
	std::cout << std::boolalpha << diff_digits(102) << std::endl;
	std::cout << std::boolalpha << diff_digits(101) << std::endl;
	return 0;
}