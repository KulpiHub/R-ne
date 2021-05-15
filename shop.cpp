#include <iostream>

int main(){

    int hours, minutes;

    std::cin >> hours;
    hours *= 100;

    std::cin >> minutes;

    int time = hours + minutes;
    std::cout << std::boolalpha << (time>=1030 && time<1830);
}
