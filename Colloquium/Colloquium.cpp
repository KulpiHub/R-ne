#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<float> pointsSum (std::string stream){

    std::istringstream isstream(stream);
    std::vector<float> num;
    float number;
    float sum = 0;
    std::string line;

    isstream >> line;

    while(!isstream.eof()){
        isstream >> number;
        num.push_back(number);
    }
    for (int i = 0; i < num.size(); i++){
        sum += num[i];
    }
    std::cout << line << " " << sum << "\n";
    return num;
}
int main (int argc, char *argv[]){
    std::vector<std::vector<float>> matrix;
    float avg;
    float avg2;
    std::string line;
    std::ifstream input(argv[1]);
    std::getline(input, line);
    while(!input.eof()){
        std::getline(input, line);
        std::vector<float> lines = pointsSum(line);
        matrix.push_back(lines);
    }
    std::cout << std::endl;
    for(int j = 0; j < matrix[0].size();){
        for(int i = 0; i < matrix.size(); i++){
            avg += matrix[i][j];
    }
        avg2 = avg / matrix.size();
        std::cout << j + 1 << " " << avg2 << " ";
        std::cout << std::endl;
    j++;
    avg = 0;
    avg2 = 0;
    }
}