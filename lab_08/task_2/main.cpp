#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <set>
#include <map>
using namespace std;

bool isPalindrome(const string &word) {
    if (word.length() <= 1) return false;
    for (size_t i = 0; i < word.size() / 2; ++i) {
        if (word[i] != word[word.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int countVowels(const string &word) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
    int count = 0;
    for (char c : word) {
        if (vowels.find(tolower(c)) != vowels.end()) {
            count++;
        }
    }
    return count;
}

string duplicateVowels(const string &word) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
    string result;
    for (char c : word) {
        result += c;
        if (vowels.find(tolower(c)) != vowels.end()) {
            result += c;
        }
    }
    return result;
}

void processText(const string &inputFile, const string &outputFile) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Ошибка при открытии файлов!" << endl;
        return;
    }

    vector<string> words;
    string word;

    while (input >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return ispunct(c);
        }), word.end());
        words.push_back(word);
    }

    bool hasPalindrome = false;

    for (const auto &w : words) {
        if (isPalindrome(w)) {
            hasPalindrome = true;
            break;
        }
    }

    if (hasPalindrome) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return countVowels(a) > countVowels(b);
        });
    } else {
        for (auto &w : words) {
            w = duplicateVowels(w);
        }
        sort(words.begin(), words.end());
    }

    for (const auto &w : words) {
        output << w << "\n";
    }

    input.close();
    output.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    processText(inputFile, outputFile);

    cout << "Обработка завершена. Результаты записаны в файл " << outputFile << endl;

    return 0;
}