#include <iostream>

double less(double a, double b)
double less(double a, double b)
{
    return (a < b ? a : b);
}
int main()
{

    double a;
    double b;
    std::cin>>a;
    std::cin>>b;
    std::cout << less(a, b) << std::endl;

}
