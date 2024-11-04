#include "Matrix.h"
#include <iostream>
using namespace std;

int main() {
    Matrix mat1, mat2;

    // Read Matrix 1 from a file
    mat1.readFromFile("matrix_data.txt");
    cout << "Matrix 1 (read from file):" << endl;
    mat1.display();

    // Read Matrix 2 from standard input
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
