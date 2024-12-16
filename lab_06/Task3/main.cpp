#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int minSum = numeric_limits<int>::max();
    int minColumn = -1;

    for (int j = 0; j < m; j++) {
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += matrix[i][j];
        }

        if (currentSum < minSum) {
            minSum = currentSum;
            minColumn = j;
        }
    }

    for (int i = 0; i < n; i++) {
        matrix[i][minColumn] += 3;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
