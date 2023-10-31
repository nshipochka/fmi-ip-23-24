#include <iostream>

int fact(int n) {
	int res = 1;
	while (n) {
		res *= n;
		n--;
	}
	return res;
}