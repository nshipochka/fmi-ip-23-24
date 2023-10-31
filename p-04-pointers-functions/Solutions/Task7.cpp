#include <iostream>

//От задача 4
double distance(float x1, float y1, float x2, float y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool are_different(float x1, float y1, float x2, float y2) {
	return x1 != x2 || y1 != y2;
}
double perimeter(float x1, float y1, float x2, float y2, float x3, float y3) {
	if (!are_different(x1, y1, x2, y2) || !are_different(x1, y1, x3, y3) || !are_different(x3, y3, x2, y2)) {
		throw std::invalid_argument("These points don't make a triangle!");
	}

	return distance(x1, y1, x2, y2) + distance(x1, y1, x3, y3) + distance(x3, y3, x2, y2);
}