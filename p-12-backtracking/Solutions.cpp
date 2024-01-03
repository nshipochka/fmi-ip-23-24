#include<iostream>
const size_t MOVES_CNT = 4;
// Ходовете са в следния ред: НАЛЯВО, НАДЯСНО, НАДОЛУ, НАГОРЕ
const int moves_x[MOVES_CNT] = { -1, 1, 0, 0 };
const int moves_y[MOVES_CNT] = { 0, 0, 1, -1 };

bool is_valid_position(size_t n, size_t m, int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void add_to_array(int* path, size_t& size, int element) {
	path[size] = element;
	size++;
}

void print(int* path, size_t size) {
	for (size_t i = 0; i < size; ++i)
		std::cout << path[i] << " ";
	std::cout << std::endl;
}

// Задача 1
void print_paths(int** matrix, size_t n, size_t m, int* path, size_t path_size, size_t x, size_t y) {
	if (x + 1 == n && y + 1 == m) { // ако сме стигнали края
		add_to_array(path, path_size, matrix[x][y]);
		print(path, path_size);
		return;
	}

	add_to_array(path, path_size, matrix[x][y]);

	if (is_valid_position(n, m, x + 1, y)) {
		print_paths(matrix, n, m, path, path_size, x + 1, y);
	}

	if (is_valid_position(n, m, x, y + 1)) {
		print_paths(matrix, n, m, path, path_size, x, y + 1);
	}

	// При приключване на функцията, промяната на path_size няма да бъде отразена навън, така че все едно
	// сме махнали последния елемент който сме добавили
}

void print_paths(int** matrix, int n, int m) {
	int* path = new int[n * m + 1]; // ще е достатъчно голям да побере всеки път
	size_t path_size = 0;
	print_paths(matrix, n, m, path, path_size, 0, 0);
	delete[] path;
}

void print_matrix(int** matrix, int m, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

// Задача 2
void print_power_set(int* set, int curr_element, int* subset, size_t subset_size) {
	if (curr_element < 0) {
		print(subset, subset_size);
		return;
	}

	// Не добавяме текущия елемент към подмножеството
	print_power_set(set, curr_element - 1, subset, subset_size);

	// Добавяме текущия елемент към подмножеството
	subset[subset_size] = set[curr_element];
	print_power_set(set, curr_element - 1, subset, subset_size + 1);
}

void print_power_set(int* set, size_t set_size) {
	int subset_max_size = pow(2, set_size);
	int* subset = new int[subset_max_size];

	print_power_set(set, set_size - 1, subset, 0);

	delete[] subset;
}

// Задача 3
void print_sum_combinations(int k, int n, int* combination, size_t combination_size) {
	if (n == 0) { // ако сме направили точната сума
		print(combination, combination_size);
		return;
	}

	for (int i = k; i <= n; i++) {
		add_to_array(combination, combination_size, i);
		print_sum_combinations(i, n - i, combination, combination_size);
		combination_size--; // Все едно махаме последния от комбинацията
	}
}

void print_sum_combinations(int n) {
	int* combination = new int[n];
	print_sum_combinations(1, n, combination, 0);
	delete[] combination;
}

// Задача 4
void path_count(int** maze, int n, int x, int y, int xE, int yE, bool** visited, int& count) {
	if (x == xE && y == yE) {
		count++;
		return;
	}

	// Отбелязваме си, че от тук сме минали за текущия път
	visited[x][y] = true;

	for (int i = 0; i < MOVES_CNT; ++i) {
		int next_x = x + moves_x[i]; // пресмятаме си следващите x и y
		int next_y = y + moves_y[i];

		if (is_valid_position(n, n, next_x, next_y) && maze[next_x][next_y] == 1 && !visited[next_x][next_y]) // Ако е валидна позиция и не сме минавали от там
			path_count(maze, n, next_x, next_y, xE, yE, visited, count); // Проверяваме за пътища през следващите клетки
	}

	// Освобождаваме клетката, ако ще се ползва в други пътища
	visited[x][y] = false;
}

int path_count(int** maze, int n, int x0, int y0, int xE, int yE) {
	bool** visited = new bool* [n];
	for (int i = 0; i < n; ++i) {
		visited[i] = new bool[n];
		for (int j = 0; j < n; ++j)
			visited[i][j] = false;
	}

	int count = 0;
	path_count(maze, n, x0, y0, xE, yE, visited, count);

	for (int i = 0; i < n; ++i)
		delete[] visited[i];
	delete[] visited;

	return count;
}

// Задача 5
void shortest_path(int** maze, int n, int x, int y, int xE, int yE, bool** visited, int distance, int& min_distance) {
	if (x == xE && y == yE) {
		min_distance = std::min(distance, min_distance);
		return;
	}

	// Отбелязваме си, че от тук сме минали за текущия път
	visited[x][y] = true;

	for (int i = 0; i < MOVES_CNT; ++i) {
		int next_x = x + moves_x[i]; // пресмятаме си следващите x и y
		int next_y = y + moves_y[i];

		if (is_valid_position(n, n, next_x, next_y) && maze[next_x][next_y] == 1 && !visited[next_x][next_y]) // Ако е валидна позиция и не сме минавали от там
			shortest_path(maze, n, next_x, next_y, xE, yE, visited, distance + 1, min_distance); // Проверяваме за пътища през следващите клетки
	}

	// Освобождаваме клетката, ако ще се ползва в други пътища
	visited[x][y] = false;
}

int shortest_path(int** maze, int n, int x0, int y0, int xE, int yE) {
	bool** visited = new bool* [n];
	for (int i = 0; i < n; ++i) {
		visited[i] = new bool[n];
		for (int j = 0; j < n; ++j)
			visited[i][j] = false;
	}

	int distance = 0;
	int min_distance = INT_MAX;
	shortest_path(maze, n, x0, y0, xE, yE, visited, distance, min_distance);

	for (int i = 0; i < n; ++i)
		delete[] visited[i];
	delete[] visited;

	return min_distance;
}

int main() {
	// Задача 1
	int** matrix = new int* [3];
	for (int i = 0; i < 3; ++i) {
		matrix[i] = new int[3];
		for (int j = 0; j < 3; ++j)
			matrix[i][j] = i * 3 + j + 1;
	}

	print_matrix(matrix, 3, 3);
	print_paths(matrix, 3, 3);
	for (int i = 0; i < 3; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;

	// Задача 2
	/*int set[] = { 1, 2, 3 };
	size_t size = sizeof(set) / sizeof(int);

	print_power_set(set, size);*/

	// Задача 3
	//print_sum_combinations(5);

	// Задача 4, 5
	/*int n;
	std::cin >> n;

	int x0, y0;
	int xE, yE;
	std::cin >> x0 >> y0 >> xE >> yE;

	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; ++j)
			std::cin >> matrix[i][j];
	}

	std::cout << path_count(matrix, n, x0, y0, xE, yE) << std::endl;
	std::cout << shortest_path(matrix, n, x0, y0, xE, yE) << std::endl;

	for (int i = 0; i < n; ++i)
		delete[] matrix[i];
	delete[] matrix;*/


	return 0;
}