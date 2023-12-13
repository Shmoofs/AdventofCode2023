#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

void countOccurances(std::string nextWord, std::string word, int count[3]) {
    if (nextWord.find("red") != std::string::npos) 
    count[0] += std::stoi(word);
    if (nextWord.find("green") != std::string::npos) 
    count[1] += std::stoi(word);
    if (nextWord.find("blue") != std::string::npos) 
    count[2] += std::stoi(word);
}

void countOccurancesMax(std::string nextWord, std::string word, int count[3]) {
    if (nextWord.find("red") != std::string::npos 
    && count[0] < std::stoi(word)){
    count[0] = std::stoi(word);
    }

    if (nextWord.find("green") != std::string::npos 
    && count[1] < std::stoi(word)){
        count[1] = std::stoi(word);
    }
    
    if (nextWord.find("blue") != std::string::npos 
    && count[2] < std::stoi(word)){
    count[2] = std::stoi(word);
    }
}

void part_1(){
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }
    std::string nextWord;
    int gameCount = 0;
    int possibleGames = 0;
    //Red, Green, Blue
    int count[3] = {0, 0, 0};
    int maxCount[3] = {12, 13, 14};
    std::string word;
    bool possible = true;

    while (word = nextWord, inputFile >> nextWord) {
        if (nextWord.find("Game") != std::string::npos) {   
            possibleGames += gameCount * possible;
            gameCount++;
            possible = true;
            count[0] = 0;
            count[1] = 0;
            count[2] = 0; 
        }
        countOccurances(nextWord, word, count);

        if(count[0] > maxCount[0] 
        || count[1] > maxCount[1] 
        || count[2] > maxCount[2]){
            possible = false;

        }

        if (nextWord.find(";") != std::string::npos) {
            count[0] = 0;
            count[1] = 0;
            count[2] = 0; 
        }
    }
    std::cout << possibleGames << std::endl;
}

void part_2(){
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }
    int total = 0;
    std::string nextWord;
    //Red, Green, Blue
    int count[3] = {0, 0, 0};
    std::string word;

    while (word = nextWord, inputFile >> nextWord) {
        if (word.find("Game") != std::string::npos) {
            total += count[0] * count[1] * count[2];
            count[0] = 0;
            count[1] = 0;
            count[2] = 0; 
        }
        countOccurancesMax(nextWord, word, count);
    }
    total += count[0] * count[1] * count[2];
    std::cout << total << std::endl;
}

int main() {

    part_1();
    part_2();

    return 0;
}