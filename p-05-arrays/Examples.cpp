#include<iostream>
const int MAX_SIZE = 1024;

void printBackwards(int* a, int size) {
	for (int i = size - 1; i >= 0; --i)
		std::cout << a[i] << " ";
}

int main() {
	// Въвеждат се n реални числа (n ≤ 1000). Да се изкарат в обратен ред с помощта на масив.
	int n;
	std::cin >> n;

	int arr[MAX_SIZE];

	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	/*for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";*/

	
	printBackwards(arr, n);

	return 0;
}