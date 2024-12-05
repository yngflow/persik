#include <iostream>
using namespace std;
void clearBit(int &x, int i) {
    x &= ~(1 << i); 
}

int main() {
    int x, i; 
    cin >> x >> i;    
    clearBit(x, i);
    cout << x;
    return 0;
}
