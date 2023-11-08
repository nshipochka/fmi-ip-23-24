#include<iostream>

void removeAtPos(int arr[], int& n, int pos) {
	if (pos >= n)
		throw std::invalid_argument("Not a valid position for deletion");

	for (int i = pos; i < n - 1; ++i)
		arr[i] = arr[i + 1];

	n--;
}

void insertAtEnd(int arr[], int& size, int element) {
	//По принцип проверка дали не надвишаваме максимум размера
	//В случая не ни трябва, защото само местим число от едно място на друго
	arr[size] = element;
	size++;
}

void moveZeros(int arr[], int& n) {
	int zerosCount = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0) {
			removeAtPos(arr, n, i);
			zerosCount++;
			i--;
		}
	}
	for (; zerosCount > 0; --zerosCount)
		insertAtEnd(arr, n, 0);
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {

	int arr[] = { 0, 1, 0, 0, 0, 0, 5, 0 };
	int size = sizeof(arr) / sizeof(int);

	moveZeros(arr, size);
	printArr(arr, size);

	return 0;
}