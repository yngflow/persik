#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <set>
using namespace std;

map<char, int> countLetters(const string &text) {
    map<char, int> frequency;
    for (char c : text) {
        if (isalpha(c)) {
            frequency[tolower(c)]++;
        }
    }
    return frequency;
}

set<char> getTop4Letters(const map<char, int> &frequency) {
    vector<pair<char, int>> sortedLetters(frequency.begin(), frequency.end());
    sort(sortedLetters.begin(), sortedLetters.end(),
              [](const pair<char, int> &a, const pair<char, int> &b) {
                  return b.second < a.second;
              });

    set<char> top4;
    for (size_t i = 0; i < min<size_t>(4, sortedLetters.size()); ++i) {
        top4.insert(sortedLetters[i].first);
    }
    return top4;
}

bool containsTwoTopLetters(const string &word, const set<char> &topLetters, string &found) {
    for (size_t i = 0; i < word.size() - 1; ++i) {
        char first = tolower(word[i]);
        char second = tolower(word[i + 1]);
        if (topLetters.count(first) && topLetters.count(second)) {
            found = {word[i], word[i + 1]};
            return true;
        }
    }
    return false;
}

void processText(const string &inputFile, const string &outputFile) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Ошибка при открытии файлов!" << endl;
        return;
    }

    string text((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());

    map<char, int> frequency = countLetters(text);

    set<char> top4 = getTop4Letters(frequency);

    string word, resultText;
    for (size_t i = 0; i < text.size(); ++i) {
        char c = text[i];
        if (isalnum(c)) {
            word += c; 
        } else {
            if (!word.empty()) {
                string foundLetters;
                if (containsTwoTopLetters(word, top4, foundLetters)) {
                    resultText += word + "(" + foundLetters + ")";
                } else {
                    resultText += word;
                }
                word.clear();
            }
            resultText += c;
        }
    }

    if (!word.empty()) {
        string foundLetters;
        if (containsTwoTopLetters(word, top4, foundLetters)) {
            resultText += word + "(" + foundLetters + ")";
        } else {
            resultText += word;
        }
    }

    output << resultText;

    input.close();
    output.close();
    cout << "Обработка завершена. Результаты записаны в файл " << outputFile << endl;
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    processText(inputFile, outputFile);

    return 0;
}