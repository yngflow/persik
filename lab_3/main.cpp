#include <iostream>
using namespace std;

void clearBit(int &x, int i) {
    for (int j = 0; j < i; ++j) {
        x = x >> 1; 
    }

    if (x & 1) { 
        x = x >> 1; 
    }
}

int main() {
    int x, i;

    cin >> x >> i;

    if (x <= 0 || x >= 1000000000) {
        cerr << "Число x должно быть в диапазоне (0, 10^9)" << endl;
        return 1;
    }

    if (i < 0 || i >= 32) {
        cerr << "Индекс бита i должен быть в диапазоне [0, 32)" << endl;
        return 1;
    }

    clearBit(x, i);
    cout << x;

    return 0;
}
