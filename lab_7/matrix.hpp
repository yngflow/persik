#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

namespace MatrixOperations {
    using Matrix = std::vector<std::vector<int>>;

    void readMatrix(Matrix& matrix, int& n);
    bool hasIdenticalRows(const Matrix& matrix);
    int findMaxPrime(const Matrix& matrix);
    void replaceColumnMinWithMaxPrime(Matrix& matrix, int maxPrime);
    void writeMatrix(const Matrix& matrix);
}

#endif