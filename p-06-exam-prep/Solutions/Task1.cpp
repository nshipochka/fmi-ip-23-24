#include<iostream>

void removeAtPos(int arr[], int& n, int pos, int step) {
	if (pos >= n)
		throw std::invalid_argument("Not a valid position for deletion");

	for (int i = pos; i < n - step; ++i)
		arr[i] = arr[i + step];

	n-=step;
}

void removeDuplicates(int arr[], int& n) {
	for (int i = 0; i < n - 1; ++i) {
		int repCount = 0;

		while (i + 1 + repCount < n && arr[i] == arr[i + 1 + repCount]) {
			repCount++;
		}

		if (repCount >= 1) {
			removeAtPos(arr, n, i + 1, repCount);
		}
	}
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {

	int arr[] = { 1,2,2,2,3,4,5,6,6,7,9,9,9,9,10,10,10 };
	int size = sizeof(arr) / sizeof(int);

	removeDuplicates(arr, size);
	printArr(arr, size);

	return 0;
}