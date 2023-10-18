#include <iostream>

int main() {
    int x1, y1;
    int x2, y2;
    int x3, y3;

    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    std::cin >> x3 >> y3;

    //вариант 1
    if (x1 < x2 && x1 < x3) std::cout << x1 << " ";
    else if (x2 < x1 && x2 < x3) std::cout << x2 << " ";
    else std::cout << x3 << " ";

    if (y1 < y2 && y1 < y3) std::cout << y1 << std::endl;
    else if (y2 < y1 && y2 < y3) std::cout << y2 << std::endl;
    else std::cout << y3 << std::endl;


    //вариант 2
    std::cout << std::min(x1, std::min(x2, x3)) << " " 
              << std::min(y1, std::min(y2, y3)) << std::endl;
	return 0;
}