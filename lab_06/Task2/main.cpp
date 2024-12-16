#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

int ProductOfDigits(int num) {
    int product = 1;
    while (num > 0) {
        product *= (num % 10);
        num /= 10;
    }
    return product;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int &num : numbers) {
        cin >> num;
    }

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        int firstA = FirstDigit(a), firstB = FirstDigit(b);
        int prodA = ProductOfDigits(a), prodB = ProductOfDigits(b);

        if (firstA != firstB) return firstA < firstB;
        if (prodA != prodB) return prodA < prodB;
        
        return a < b;
    });

    for (int num : numbers) {
        cout << num << " ";
    }
    return 0;
}
