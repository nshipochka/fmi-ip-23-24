#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	temp = b;
	b = a;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}