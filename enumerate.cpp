#include <fstream>

int main(){
    int counter = 1;
    std::string line;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
        while(!input.eof())
    {
            getline(input, line);
            output << counter << " " << line << "\n";
            counter++;
    }
    output.close();
    input.close();
}
