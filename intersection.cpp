#include <vector>
#include <iostream>

std::vector<int> intersection(std::vector<int> vector1,std::vector<int> vector2){
std::vector<int> temp;
	int i = 0;
	int j = 0;
  while (i < vector1.size() && j < vector2.size())
    {
      if (vector1[i] < vector2[j])
	i++;
      else if (vector2[j] < vector1[i])
	j++;
      else
	{
	  temp.push_back(vector2[j]);
	  i++;
	  j++;
	}
    }
    for (i = 0; i < temp.size(); i++)
    return temp;
}
int main() {
const std::vector<int> vector1 {-7, 2, 3, 7, 15, 18, 23};
const std::vector<int> vector2 {-8, 3, 5, 8, 15, 23, 30};
std::vector<int> result = intersection(vector1, vector2);
for (int element: result) {
    std::cout << element << " "; }
std::cout << std::endl; }
