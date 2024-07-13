#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

string cleanWord(string word) {
    string clean_word;
    for (char c : word) {
        if (isalpha(c)) {
            clean_word += tolower(c);
        }
    }
    return clean_word;
}

int main() {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";
    ifstream inputFile;
    inputFile.open(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Failed to open file " << inputFileName << endl;
        return 1;
    }

    map<string, int> wordFrequency;
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            word = cleanWord(word);
            if (!word.empty()) {
                wordFrequency[word]++;
            }
        }
    }
    inputFile.close();

    string mostFrequentWord;
    int maxFrequency = 0;
    for (auto pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentWord = pair.first;
        }
    }
    cout << "Frequency dictionary:" << endl;
    for (auto pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Most frequent word: " << mostFrequentWord << " (" << maxFrequency << " times)" << endl;

    ofstream outputFile;
    outputFile.open(outputFileName);

    if (!outputFile.is_open()) {
        cerr << "Failed to open file " << outputFileName << endl;
        return 1;
    }

    outputFile << "Frequency dictionary:" << endl;
    for (auto pair : wordFrequency) {
        outputFile << pair.first << ": " << pair.second << endl;
    }

    outputFile << "Most frequent word: " << mostFrequentWord << " (" << maxFrequency << " times)" << endl;
    outputFile.close();

    return 0;
}
