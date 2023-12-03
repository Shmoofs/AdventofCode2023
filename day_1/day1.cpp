#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    int total = 0;
    std::string line;
    std::string strnum = "00";
    std::string all_digits[9] = {"o1e", "t2o", "t3e", "f4r", "f5e", "s6x", "s7n", "e8t", "n9e"};
    std::string all_digits_string[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    while (std::getline(inputFile, line)) {
       std::string digits;
        for (int i = 0; i < 9; i++) {
           line = ReplaceAll(line, all_digits_string[i], all_digits[i]);
        }

        for(char c : line){
            if (isdigit(c)) digits += c;
        }

        if(digits.length() > 0) {
            strnum[0] = digits[0];
            strnum[1] = digits[digits.length() - 1];
            total += std::stoi(strnum);
        }
    }
    std::cout << total << std::endl;
    return 0;
}

