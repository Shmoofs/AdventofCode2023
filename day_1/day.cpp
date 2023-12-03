#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    int total = 0;
    int number = 0;
    
    std::string line;
    std::string strnum = "00";
    while (std::getline(inputFile, line)) {
       std::string digits;
        for (char c : line) {
            if (std::isdigit(c)) {
                digits += c;
            }
        }
        if(digits.length() > 0) {
            strnum[0] = digits[0];
            strnum[1] = digits[digits.length() - 1];
            total += stoi(strnum);
            }
        }
    
    std::cout << "Total: " << total << std::endl;
    inputFile.close();
    return 0;
}

