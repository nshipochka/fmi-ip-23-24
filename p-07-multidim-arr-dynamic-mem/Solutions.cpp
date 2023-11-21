#include<iostream>
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

// Task 1
void scalarMultiplication(int matrix[][MAX_COLS], int rows, int cols, int scalar) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] *= scalar;
		}
	}
}

// Task 2
void sumMatrices(int m1[][MAX_COLS], int r1, int c1, int m2[][MAX_COLS], int r2, int c2) {
	if (r1 != r2 || c1 != c2)
		throw std::invalid_argument("Matrices have different dimensions");

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; ++j) {
			m1[i][j] += m2[i][j];
		}
	}
}

// Task 3
void shiftLeft(int arr[], int& size, int pos) {
	for (int i = pos; i < size - 1; ++i)
		arr[i] = arr[i + 1];
	size--;
}

void removeKthCol(int matrix[][MAX_COLS], int rows, int& cols, int k) {
	for (int i = 0; i < rows; i++) {
		shiftLeft(matrix[i], cols, k);
	}
}

// Task 4
void allocate(int* arr, int size) {
	arr = new int[size];
}

// Task 5
void copy(int* src, int size, int* dest) {
	for (int i = 0; i < size; ++i) {
		dest[i] = src[i];
	}
}

// Task 6
void copy(int matrix[][MAX_COLS], int rows, int cols, int* dest, int& size) {
	size = rows * cols;
	allocate(dest, size);

	for (int i = 0; i < rows; ++i) {
		copy(matrix[i], cols, dest + i * cols);
	}
}

// Task 7
void resize(int*& arr, int size, int& capacity, int n) {
	int* new_arr = new int[capacity + n];

	copy(new_arr, size, arr);

	capacity += n;

	delete[] arr;
	arr = new_arr;
}

// Task 8
void concat(int*& arr1, int* arr2, int& size1, int size2) {
	int* new_arr = new int[size1 + size2];

	copy(new_arr, size1, arr1);
	copy(new_arr + size1, size2, arr2);

	size1 = size1 + size2;

	delete[] arr1;
	arr1 = new_arr;
}

// Task 9
void removeAtPos(int*& arr, int& size, int pos) {
	shiftLeft(arr, size, pos);
	
	int* new_arr = new int[size];

	copy(arr, size, new_arr);

	delete[] arr;
	arr = new_arr;
}

// Task 10
void insertAtBack(int*& arr, int& size, int& capacity, int elem) {
	if (size == capacity)
		resize(arr, size, capacity, 1);

	arr[size] = elem;
	size++;
}

// Task 11
void shiftRight(int* arr, int& size, int pos) {
	for (int i = size; i >= pos; --i) {
		arr[i] = arr[i - 1];
	}
	size++;
}

void insertAt(int*& arr, int& size, int& capacity, int pos, int elem) {
	if (size == capacity)
		resize(arr, size, capacity, 1);

	shiftRight(arr, size, pos);
	arr[pos] = elem;
}

// Task 12
void subArr(int* arr, int* size, int pos, int len, int*& sub_arr) {
	allocate(sub_arr, len);
	copy(arr + pos, len, sub_arr);
}

int main() {
	// Task 5
	int arr[] = { 1,2,3,4,5 };
	int size = sizeof(arr) / sizeof(int);

	int* arr_copy;
	allocate(arr_copy, size);
	copy(arr, size, arr_copy);

	return 0;
}