#include <iostream>

int main()
{
    int year;
    std::cin >> year;
    (year%100 != 0 && year%4 == 0 && std::cout << "true") || (year%100 == 0 && year%400 == 0 && std::cout << "true") || std::cout << "false";
}
