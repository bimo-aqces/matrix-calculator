#include <iostream>
#include <cmath>
#include "Matrix3x3.hpp"
#include "Matrix2x2.hpp"

int main(){
    Matrix3x3 matrix1(
        2, 1, 3, 
        1, 3, 2, 
        3, 2, 1
    );
    Matrix3x3 matrix2(
        3, 1, 2,
        2, 4, 1,
        1, 2, 5
    );

    Matrix2x2 matrix3(
        5, 2,
        7, 3
    );
    Matrix2x2 matrix4(
        4, 1,
        6, 2
    );
    std::cout << " MATRIX 3X3\n";
    std::cout << matrix1.get_determinant() << '\n';
    std::cout << matrix2.get_determinant() << '\n';
    Matrix3x3 substraction_matrix1_matrix2 = matrix1.get_substraction(matrix2);
    substraction_matrix1_matrix2.print();
    std::cout << "\n\n";

    Matrix3x3 addition_matrix1_matrix2 = matrix1.get_addition(matrix2);
    addition_matrix1_matrix2.print();
    std::cout << "\n\n";

    Matrix3x3 multiplication_matrix1_matrix2 = matrix1.get_multiplication(matrix2);
    multiplication_matrix1_matrix2.print();
    std::cout << "\n\n";

    Matrix3x3 matrix1_inverse = matrix1.get_inverse();
    matrix1_inverse.print();
    std::cout << "\n\n";

    Matrix3x3 division_matrix1_matrix2 = matrix1.get_division(matrix2);
    division_matrix1_matrix2.print();
    std::cout << "\n\n";

    std::cout << " MATRIX 2X2\n";
    std::cout << matrix3.get_determinant() << '\n';
    std::cout << matrix4.get_determinant() << '\n';

    Matrix2x2 substraction_matrix3_matrix4 = matrix3.get_substraction(matrix4);
    substraction_matrix3_matrix4.print();
    std::cout << "\n\n";

    Matrix2x2 addition_matrix3_matrix4 = matrix3.get_addition(matrix4);
    addition_matrix3_matrix4.print();
    std::cout << "\n\n";

    Matrix2x2 multiplication_matrix3_matrix4 = matrix3.get_multiplication(matrix4);
    multiplication_matrix3_matrix4.print();
    std::cout << "\n\n";

    Matrix2x2 matrix3_inverse = matrix3.get_inverse();
    matrix1_inverse.print();
    std::cout << "\n\n";

    Matrix2x2 division_matrix3_matrix4 = matrix3.get_division(matrix4);
    division_matrix3_matrix4.print();
    std::cout << "\n\n";
}