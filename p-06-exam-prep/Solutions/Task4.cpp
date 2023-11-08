#include<iostream>

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

int main() {
	int arr[] = { 1, 8, 9, 9, 4, 5 };
	int size = sizeof(arr)/sizeof(int);
	int k = 4;

	//проверка дали k e подходяща позиция в масива изобщо

	insertionSort(arr, size);
	printArr(arr, size);
	std::cout << arr[size - k];

	return 0;
}
