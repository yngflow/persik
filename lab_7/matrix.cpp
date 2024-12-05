#include "matrix.hpp"
#include <iostream>
#include <cmath>
#include <set>

namespace MatrixOperations {
    void readMatrix(Matrix& matrix, int& n) {
        std::cout << "Введите размер матрицы (n <= 100): ";
        std::cin >> n;

        matrix.resize(n, std::vector<int>(n));
        std::cout << "Введите элементы матрицы:" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }

    bool hasIdenticalRows(const Matrix& matrix) {
        std::set<std::vector<int>> uniqueRows;
        for (const auto& row : matrix) {
            if (!uniqueRows.insert(row).second) {
                return true; 
            }
        }
        return false;
    }

    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= std::sqrt(num); ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int findMaxPrime(const Matrix& matrix) {
        int maxPrime = -1;
        for (const auto& row : matrix) {
            for (int num : row) {
                if (isPrime(num)) {
                    maxPrime = std::max(maxPrime, num);
                }
            }
        }
        return maxPrime;
    }

    void replaceColumnMinWithMaxPrime(Matrix& matrix, int maxPrime) {
        int n = matrix.size();
        for (int j = 0; j < n; ++j) {
            int minRow = 0;
            for (int i = 1; i < n; ++i) {
                if (matrix[i][j] < matrix[minRow][j]) {
                    minRow = i;
                }
            }
            matrix[minRow][j] = maxPrime;
        }
    }

    void writeMatrix(const Matrix& matrix) {
        std::cout << "Результирующая матрица:" << std::endl;
        for (const auto& row : matrix) {
            for (int num : row) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
}