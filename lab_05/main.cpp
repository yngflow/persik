#include <iostream>
using namespace std;

//Задание 1
int main() {
    double A[] = {10.5, -8.3, 7.1, 20.0, 15.2, -7.0, 19.0};
    int size_A = sizeof(A) / sizeof(A[0]); 
    double sum = 0, maxValue = -1000000000;
    int maxNumber = -1;

    for (int i = 0; i < size_A; i++) {
        if (A[i] >= -7 && A[i] <= 19) {
            sum += A[i];
            if (A[i] > maxValue) {
                maxValue = A[i];
                maxNumber = i;
            }
        }
    }

    cout << "Сумма чисел на отрезке [-7, 19]: " << sum << endl;
    if (maxNumber != -1) {
        cout << "Максимальное число: " << maxValue << endl;
        cout << "Его номер: " << maxNumber << endl;
    } else {
        cout << "Нет чисел на отрезке [-7, 19]." << endl;
    }

//Задание 2
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;

    if (N <= 0 || N >= 1000000000) {
        cerr << "Ошибка: число N должно быть натуральным и меньше 10^9." << endl;
        return 1;
    }

    int sumOfDigits = 0;
    while (N > 0) {
        sumOfDigits += N % 10;
        N /= 10;
    }

    cout << "Сумма цифр числа: " << sumOfDigits << endl;

    return 0;
}