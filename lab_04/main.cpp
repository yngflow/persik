#include <iostream>
using namespace std;

int main() {
    // Задание 1
    cout << "Введите числа A, B, C: ";
    int A, B, C;
    cin >> A >> B >> C;

    if (C != 0 && A % C == 0 && B % C == 0) {
        cout << "(A + B) / C = " << (A + B) / C << endl;
    } else if (C != 0 && A % C == 0) {
        cout << "A / C + B = " << A / C + B << endl;
    } else {
        cout << "A - B - C = " << A - B - C << endl;
    }

    // Задание 2
    int N;
    bool validInput = false;
    do {
        cout << "\nВведите число от 1 до 7 включительно: ";
        cin >> N;

        switch (N) {
            case 1: cout << "Monday" << endl; validInput = true; break;
            case 2: cout << "Tuesday" << endl; validInput = true; break;
            case 3: cout << "Wednesday" << endl; validInput = true; break;
            case 4: cout << "Thursday" << endl; validInput = true; break;
            case 5: cout << "Friday" << endl; validInput = true; break;
            case 6: cout << "Saturday" << endl; validInput = true; break;
            case 7: cout << "Sunday" << endl; validInput = true; break;
            default: 
                cout << "Error: число не подходит, попробуйте ввести число от 1 до 7." << endl;
        }
    } while (!validInput);

    // Задание 3
    int X;
    do {
        cout << "\nВведите число -1 или 1: ";
        cin >> X;

        if (X == -1) {
            cout << "Negative number" << endl;
        } else if (X == 1) {
            cout << "Positive number" << endl;
        } else {
            cout << "Error: необходимо ввести только число -1 или 1." << endl;
        }
    } while (X != -1 && X != 1);

    return 0;
}
