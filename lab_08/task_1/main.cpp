#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

bool hasLetterThreeTimes(const string &word) {
    map<char, int> freq;
    for (char c : word) {
        if (isalpha(c)) {
            c = tolower(c);
            freq[c]++;
            if (freq[c] >= 3) {
                return true;
            }
        }
    }
    return false;
}

void processFile(const string &inputFile, const string &outputFile) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Ошибка при открытии файлов!" << endl;
        return;
    }

    set<string> uniqueWords; 
    string word;

    while (input >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return ispunct(c);
        }), word.end());

        if (hasLetterThreeTimes(word)) {
            uniqueWords.insert(word);
        }
    }

    multimap<size_t, string> sortedWords;
    for (const auto &w : uniqueWords) {
        sortedWords.insert({w.size(), w});
    }

    for (const auto &[length, w] : sortedWords) {
        output << w << "\n";
    }

    input.close();
    output.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    processFile(inputFile, outputFile);

    cout << "Обработка завершена. Результаты записаны в файл " << outputFile << endl;

    return 0;
}