#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int &num : numbers) cin >> num;

    unordered_set<int> unique(numbers.begin(), numbers.end());
    if (unique.size() < n) {
        sort(numbers.begin(), numbers.end(), [](int a, int b) {
            return (a % 10) > (b % 10);
        });
    }

    for (int num : numbers) cout << num << " ";
    return 0;
}
