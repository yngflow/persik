#include <iostream>
using namespace std;

int getFirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

int getSumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int firstDigitA = getFirstDigit(A[j]);
            int firstDigitB = getFirstDigit(A[j + 1]);

            if (firstDigitA > firstDigitB || 
               (firstDigitA == firstDigitB && getSumOfDigits(A[j]) > getSumOfDigits(A[j + 1])) || 
               (firstDigitA == firstDigitB && getSumOfDigits(A[j]) == getSumOfDigits(A[j + 1]) && A[j] > A[j + 1])) 
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Введите количество чисел (n <= 1000): ";
    cin >> n;

    if (n <= 0 || n > 1000) {
        cout << "Ошибка: n должно быть от 1 до 1000." << endl;
        return 1;
    }

    int A[n];
    cout << "Введите последовательность из " << n << " натуральных чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    bubbleSort(A, n);

    cout << "Отсортированная последовательность:" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}