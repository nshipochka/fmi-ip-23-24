#include<iostream>
const int MAX_SIZE = 100;

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void shiftRight(int arr[], int& n) {
	//проверка дали можем да вместим още една цифра
	for (int i = n - 1; i > 0; --i) {
		arr[i] = arr[i - 1];
	}
	n++;
}

void increment(int arr[], int& n) {

	int i = n - 1;
	for (; i >= 0; --i) {
		if (arr[i] < 9) {
			arr[i]++;
			return;
		}

		arr[i] = 0;
	}

	if (i < 0) {
		shiftRight(arr, n);
		arr[0] = 1;
	}
}

int main() {
	int arr[MAX_SIZE] = { 1,8,9 };
	int size = 3;

	increment(arr, size);
	printArr(arr, size);

	return 0;
}
