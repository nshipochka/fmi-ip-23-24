#include<iostream>

void sort(int* arr, size_t sz) {
	for (size_t i = 0; i < sz - 1; ++i) {
		size_t min_ind = i;

		for (size_t j = i + 1; j < sz; ++j) {
			if (arr[min_ind] < arr[j])
				min_ind = j;
		}

		if (min_ind != i)
			std::swap(arr[min_ind], arr[i]);
	}
}

bool are_permutations(int* arr1, int* arr2, size_t sz) {
	sort(arr1, sz);
	sort(arr2, sz);

	for (size_t i = 0; i < sz; ++i) {
		if (arr1[i] != arr2[i])
			return false;
	}

	return true;
}

bool has_permuting_rows(int** matrix, size_t sz) {
	for (size_t i = 0; i < sz - 1; ++i) 
		for (size_t j = i + 1; j < sz; ++j)
			if (are_permutations(matrix[i], matrix[j], sz))
				return true;
	return false;
}

bool has_permuting_diags(int** matrix, size_t sz) {
	int* principal_diag = new int[sz];
	int* secondary_diag = new int[sz];
	size_t p_sz = 0;
	size_t s_sz = 0;

	for (size_t i = 0; i < sz; ++i) {
		for (size_t j = 0; j < sz; ++j) {
			if (i == j)
				principal_diag[p_sz++] = matrix[i][j];
			if (i == sz - 1 - j)
				secondary_diag[s_sz++] = matrix[i][j];
		}
	}

	bool result = are_permutations(principal_diag, secondary_diag, sz);

	delete[] principal_diag;
	delete[] secondary_diag;

	return result;
}

void print(int* arr, size_t sz) {
	for (size_t i = 0; i < sz; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void print(int** matrix, size_t sz) {
	for (size_t i = 0; i < sz; ++i)
		print(matrix[i], sz);
}

int main() {
	

	return 0;
}