#include<iostream>

void print_paths(int** matrix, int m, int n, int curr_x, int curr_y, int* path, int path_size) {
	// Това го слагаме в началото, за да може и последното квадратче да добавим в пътя
	path[path_size] = matrix[curr_x][curr_y];
	path_size++;
	
	if (curr_x == m - 1 && curr_y == n - 1) {
		//print path
		return;
	}

	if (curr_x + 1 < m)
		print_paths(matrix, m, n, curr_x + 1, curr_y, path, path_size);

	if (curr_y + 1 < n)
		print_paths(matrix, m, n, curr_x, curr_y + 1, path, path_size);
}



int main() {
	return 0;
}