#include<iostream>

int next_row_size(const char* curr_row) {
	int size = 0;
	char curr_char = *curr_row++;

	while (curr_char) {
		if (curr_char != *curr_row)
			size++;
		curr_char = *curr_row;
		curr_row++;
	}

	return size * 2;
}

char* generate_next_row(const char* curr_row) {
	int size = next_row_size(curr_row);
	char* next_row = new char[size + 1];
	int count = 0;

	char curr_char = *curr_row++;
	int curr_char_count = 1;

	while (curr_char) {
		if (curr_char == *curr_row)
			curr_char_count++;
		else {
			next_row[count++] = curr_char_count + '0';
			next_row[count++] = curr_char;
			curr_char_count = 1;
		}

		curr_char = *curr_row;
		curr_row++;
	}

	next_row[count] = '\0';
	return next_row;
}

char* generate_level(int n) {
	const char* curr_level = "1"; // 1
	char* next_level = generate_next_row(curr_level); // 2
	n -= 2;

	while (n) {
		curr_level = next_level;
		next_level = generate_next_row(curr_level);
		delete[] curr_level;
		n--;
	}

	return next_level;
}

int main() {
	//std::cout << generate_level(1);
	std::cout << generate_level(2) << std::endl;
	std::cout << generate_level(3) << std::endl;
	std::cout << generate_level(4) << std::endl;
	std::cout << generate_level(5) << std::endl;
	std::cout << generate_level(6) << std::endl;
	std::cout << generate_level(7) << std::endl;
	return 0;
}