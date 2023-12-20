#include<iostream>
using std::cout;

// Задача 1
int digits_sum(int n) {
	if (n == 0)
		return 0;

	return n % 10 + digits_sum(n / 10);
}

// Задача 2
int factorial(int n) {
	if (n == 1)
		return 1;

	return n * factorial(n - 1);
}

// Задача 3
int str_len(const char* str) {
	if (*str == '\0')
		return 0;

	return 1 + str_len(str + 1);
}

// Задача 4
void str_cpy(char* dest, const char* src) {
	if (*src == '\0')
		return;

	*dest = *src;
	str_cpy(dest + 1, src + 1);
}

// Задача 5
bool is_palindrome_helper(char* str, int l, int r) {
	if (abs(l - r) <= 1) // при нечетен брой букви е 1, при четен - 0
		return true;

	if (str[l] != str[r])
		return false;

	return is_palindrome_helper(str, l + 1, r - 1);
}
bool is_palindrome(char* str) {
	return is_palindrome_helper(str, 0, strlen(str));
}

// Задача 6
int gcd(int a, int b) {
	if (a == 0)
		return b;

	if (b == 0)
		return a;

	return gcd(b, a % b);
}

// Задача 7
int binary_search(int arr[], size_t l, size_t r, int num) {
	if (l > r)
		return -1;

	size_t mid = l + (r - l) / 2;

	if (arr[mid] == num)
		return mid;

	if (arr[mid] > num)
		return binary_search(arr, l, mid - 1, num);

	return binary_search(arr, mid + 1, r, num);
}

// Задача 8
int min_element_index(int arr[], size_t i, size_t size) {
	if (i == size - 1)
		return i;

	int result = min_element_index(arr, i + 1, size);

	return (arr[i] < arr[result]) ? i : result;
}

void selection_sort_helper(int arr[], size_t i, size_t size) {
	if (i == size)
		return;

	int min_index = min_element_index(arr, i, size);
	if (min_index != i)
		std::swap(arr[i], arr[min_index]);

	selection_sort_helper(arr, i + 1, size);
}

void selection_sort(int arr[], size_t size) {
	selection_sort_helper(arr, 0, size);
}

// Задача 9
void print_boolean_vectors(int n, int* temp, size_t temp_len) {
	if (n == 0) {
		for (int i = 0; i < temp_len; i++)
			std::cout << temp[i];
		std::cout << std::endl;
		return;
	}

	temp[n - 1] = 0;
	print_boolean_vectors(n - 1, temp, temp_len);
	temp[n - 1] = 1;
	print_boolean_vectors(n - 1, temp, temp_len);
}

void print_boolean_vectors(int n) {
	int* temp = new int[n];
	print_boolean_vectors(n, temp, n);
	delete[] temp;
}

// Задача 10
bool valid_position(size_t x, size_t y, int** board, size_t size) {
	return (x >= 0 && x < size && y >= 0 && y < size
		&& board[x][y] == -1);
}

void print_solution(int** board, size_t size) {
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++)
			cout << board[x][y] << " ";
		cout << std::endl;
	}
}

bool knights_tour(size_t x, size_t y, int move_count, int** board, size_t size, size_t* xs, size_t* ys) {
	if (move_count == size * size) // ако сме стигнали края
		return false;

	for (int i = 0; i < 8; i++) {
		int next_x = x + xs[i];
		int next_y = y + ys[i];

		if (valid_position(next_x, next_y, board, size)) {
			board[next_x][next_y] = move_count;

			if (knights_tour(next_x, next_y, move_count + 1, board, size, xs, ys)) // ако сме стигналия края излизаме
				return true;

			// иначе, бактракваме
			board[next_x][next_y] = -1;
		}
	}

	//ако сме изпробвали всички ходове и няма водещ до решение
	return false;
}

void knights_tour(size_t size) {
	int** board = new int*[size];
	for (size_t i = 0; i < size; ++i) {
		board[i] = new int[size];
		for (size_t j = 0; j < size; ++j)
			board[i][j] = -1;
	}

	// Възможните ходове на коня: xs[i] съответства на ys[i]
	size_t xs[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	size_t ys[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Поставяме първия ход 
	board[0][0] = 0;

	if (!knights_tour(0, 0, 1, board, size, xs, ys)) {
		cout << "Solution does not exist";
		return;
	}
	
	print_solution(board, size);
}

int main() {
	return 0;
}