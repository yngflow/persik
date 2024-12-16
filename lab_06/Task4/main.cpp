#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool allDigitsUnique(int number) {
    set<int> digits;
    while (number > 0) {
        int digit = number % 10;
        if (digits.count(digit)) {
            return false;
        }
        digits.insert(digit);
        number /= 10;
    }
    return true;
}

int main() {
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;

    if (n <= 0 || n > 10000) {
        cout << "Неверное значение. Должно быть 1 <= n <= 10000\n";
        return 1;
    }

    vector<int> numbers(n);
    cout << "Введите последовательность из " << n << " чисел:\n";

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i] <= 0) {
            cout << "Все числа должны быть натуральными\n";
            return 1;
        }
    }

    vector<int> filtered;
    for (int num : numbers) {
        if (!allDigitsUnique(num)) {
            filtered.push_back(num);
        }
    }

    vector<int> result;
    for (int num : filtered) {
        result.push_back(num);
        if (num % 14 == 0) {
            result.push_back(num);
        }
    }

    cout << "Результат:\n";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
