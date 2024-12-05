#include <iostream>
using namespace std;

int main(){
    int h, a;
    cin >> h >> a;
    if (h > 0 && a < 100000000){
        cout << h * a * 0.5;
    }
    else cout << "Числа не подходят";
    return 0;
}