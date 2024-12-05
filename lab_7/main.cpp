#include "matrix.hpp"
#include "matrix.cpp"
#include <iostream>

int main() {
    MatrixOperations::Matrix matrix;
    int n;

    MatrixOperations::readMatrix(matrix, n);

    if (!MatrixOperations::hasIdenticalRows(matrix)) {
        std::cout << "Одинаковые строки не найдены. Матрица остаётся без изменений." << std::endl;
        MatrixOperations::writeMatrix(matrix);
        return 0;
    }

    int maxPrime = MatrixOperations::findMaxPrime(matrix);
    if (maxPrime == -1) {
        std::cout << "Простых чисел в матрице нет. Замена невозможна." << std::endl;
        return 0;
    }

    MatrixOperations::replaceColumnMinWithMaxPrime(matrix, maxPrime);

    MatrixOperations::writeMatrix(matrix);

    return 0;
}