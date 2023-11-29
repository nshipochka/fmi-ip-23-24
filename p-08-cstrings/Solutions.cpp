#include <iostream>

//1
void allocate(int**& arr, size_t rows, size_t cols) {
	arr = new int* [rows];
	for (size_t i = 0; i < rows; ++i)
		arr[i] = new int[cols];
}

//2
void deallocate(int**& arr, size_t rows) {
	for (size_t i = 0; i < rows; ++i)
		delete[] arr[i];

	delete[] arr;
}

// 3
size_t str_len(const char* str) {
	size_t length = 0;
	while (*str) {
		length++;
		str++;
	}
	return length;
}

// 4
void str_cpy(char* dest, const char* src) {
	while (*src) {
		*dest = *src;
		++dest;
		++src;
	}

	*dest = '\0';
}

void str_n_cpy(char* dest, int n, const char* src) {
	for (int i = 0; i < n && src[i] != '\0'; ++i) {
		dest[i] = src[i];
	}
}

//5
void str_cat(char* dest, const char* src) {
	while (*dest)
		++dest;

	str_cpy(dest, src);
}

void str_n_cpy(char* dest, int n, const char* src) {
	while (*dest)
		++dest;
	str_n_cpy(dest, n, src);
}

// Задача на лист
bool isLower(char c) {
	return c >= 'a' && c <= 'z';
}

bool isUpper(char c) {
	return c >= 'A' && c <= 'Z';
}

void getLowercase(const char* str, char* lower) {
	while (*str) {
		if (isLower(*str)) {
			*lower = *str;
			++lower;
		}
		++str;
	}
}

void getUppercase(const char* str, char* upper) {
	while (*str) {
		if (isUpper(*str)) {
			*upper = *str;
			++upper;
		}
		++str;
	}
}

// И после strcat(lower, upper);

// 6
int str_cmp(const char* str1, const char* str2) {
	while (*str1 && *str2 && *str1 == *str2) {
		++str1;
		++str2;
	}

	if (*str1 < *str2)
		return -1;

	if (*str1 > *str2)
		return 1;

	return 0;
}

//7
const char* str_chr(const char* str, char c) {
	while (*str && *str != c)
		++str;

	if (*str)
		return str;

	return nullptr;
}

//8
const char* str_str(const char* str1, const char* str2) {
	
}

int main() {


	return 0;
}