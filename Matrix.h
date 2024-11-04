#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 4;

class Matrix {
private:
    int data[SIZE][SIZE];

public:
    void readFromStdin();
    void readFromFile(const string& filename);
    void display() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    int sumOfDiagonals() const;
    void swapRows(int row1, int row2);
};

#endif // MATRIX_H
