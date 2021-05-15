#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>

bool bernoulli(double p);
bool bernoulli(double p)
{
    if(p>=0 && p<=1)
    {
        if((rand()/(double)(RAND_MAX)) < p)
            return true;
        else
            return false;
    }
    else return 0;
}

int main() {
std::srand(std::time(nullptr));
std::cout << std::boolalpha;
for (int counter = 0; counter < 10; ++counter) {
    std::cout << bernoulli(0.2) << " "; }
std::cout << std::endl; }
