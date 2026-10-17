#include <iostream>
#include <cmath>
#include "Matrix3x3.hpp"

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
    
    std::cout << matrix1.get_magnitude() << '\n';
    std::cout << matrix2.get_magnitude() << '\n';
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
}