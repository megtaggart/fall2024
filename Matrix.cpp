// Matrix.cpp
#include "Matrix.h"

void Matrix::readFromStdin() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> data[i][j];
        }
    }
}

void Matrix::readFromFile(const string& filename) {
    ifstream infile(filename);
    if (infile.is_open()) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                infile >> data[i][j];
            }
        }
        infile.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}


void Matrix::display() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

int Matrix::sumOfDiagonals() const {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += data[i][i]; // Main diagonal
        sum += data[i][SIZE - 1 - i]; // Secondary diagonal
    }
    return sum;
}

void Matrix::swapRows(int row1, int row2) {
    if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
        for (int i = 0; i < SIZE; ++i) {
            swap(data[row1][i], data[row2][i]);
        }
    } else {
        cerr << "Invalid row indices." << endl;
    }
}
