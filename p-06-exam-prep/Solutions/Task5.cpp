#include<iostream>

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int countSmallerAfterPos(int arr[], int size, int pos) {
	if (pos == size - 1)
		return 0;

	int count = 0;
	for (int i = pos + 1; i < size; ++i)
		if (arr[i] < arr[pos])
			count++;
	
	return count;
}

void printSmallerToTheRight(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << countSmallerAfterPos(arr, size, i) << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[] = { 1, 8, 9, 9, 4, 5 };
	int size = sizeof(arr) / sizeof(int);
	
	printSmallerToTheRight(arr, size);

	return 0;
}
