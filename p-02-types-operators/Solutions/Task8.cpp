#include <iostream>

int main() {
    int year;
    std::cin >> year;

    //С std::boolalpha извеждаме true/false вместо 1/0 за булевите променливи
    std::cout << std::boolalpha << (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

    return 0;
}