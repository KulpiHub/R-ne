#include <fstream>

int main(){
    int count = 1;
    std::string line;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
        while(!input.eof())
    {
            getline(input, line);
            output << count << " " << line << "\n";
            count++;
    }
    output.close();
    input.close();
}
