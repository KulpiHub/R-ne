#include <iostream>
#include <cctype>
#include <vector>

int main() {
    std::vector<char> sentence;
    for (char Letter; std::cin >> Letter;)
        sentence.push_back(Letter);
   int i = 0;
   std::vector<int> alphabet(26);
   int emptyArray;
   while (sentence[i] != '\0') {
      if (sentence[i] >= 'A' && sentence[i] <= 'Z')
            {
                emptyArray = sentence[i]-'A';
                ++alphabet[j];
            }
            else if (sentence[i] >= 'a' && sentence[i] <= 'z')
            {
                emptyArray = sentence[i]-'a';
                ++alphabet[j];
            }
      ++i;
   }
   for (i = 0; i < 26; i++)
   std::cout << alphabet[i] << " ";
}
