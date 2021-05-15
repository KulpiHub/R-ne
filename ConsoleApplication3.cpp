#include <utility>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
void selection_sort(std::vector<int> &wektor) {
    for (unsigned i = 0; i < wektor.size() - 1; i++) {
        unsigned min = i;

        for (unsigned j = i + 1; j < wektor.size(); j++) {
            if (wektor[j] < wektor[min]) {
                min = j;
            }
        }
        std::swap(wektor[min], wektor[i]);
        for (int i : wektor)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> wektor;
    for (int a; cin >> a;) 
        wektor.push_back(a);

    selection_sort(wektor);

    for (unsigned i = 0; i < wektor.size(); i++) {
        std::cout << wektor[i] << " ";
    }
}
