#include <utility>
#include <vector>
#include <iostream>

void selection_sort(std::vector<int> vector);
void selection_sort(std::vector<int> vector){
    for (unsigned i = 0; i < vector.size() - 1; i++){
        unsigned min = i;

        for (unsigned j = i + 1; j < vector.size(); j++) {
            if (vector[j] < vector[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = vector[min];
            vector[min] = vector[i];
            vector[i] = temp;
        }
    }
}
int main (){
    int a;
    std::vector<int> vector;
        std::cin >> a;
        vector.push_back(a);

    selection_sort(vector);

    for (unsigned i = 0; i < vector.size(); i++){
        std::cout << vector[i] << " ";
    }
}
