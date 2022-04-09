#include <utility>
#include <vector>
#include <iostream>

void selection_sort(std::vector<int> wektor){
    for (int i = 0; i < wektor.size() - 1; i++){
        int min = i;

        for (int j = i + 1; j < wektor.size(); j++) {
            if (wektor[j] < wektor[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = wektor[min];
            wektor[min] = wektor[i];
            wektor[i] = temp;
        }
    }
}
int main (){
    int a;
    std::vector<int> wektor;
        std::cin >> a;
        wektor.push_back(a);

    selection_sort(wektor);

    for (int i = 0; i < wektor.size(); i++){
        std::cout << wektor[i] << " ";
    }
}
