#include <iostream>
#include <cmath>

class Matrix2x2{
    public:
        Matrix2x2(double a11, double a12,
                double a21, double a22) : 
                a11(a11), a12(a12), 
                a21(a21), a22(a22) {};

        void print() const
        {
            std::cout << a11 << " " << a12 << " " << "\n";
            std::cout << a21 << " " << a22 << " " << "\n";
        }

        double get_determinant(){
            return ((this->a11 * this->a22) - (this->a12 * this->a21));
        }

        Matrix2x2 get_addition(Matrix2x2 other_matrix){
            return Matrix2x2((this->a11 + other_matrix.a11), (this->a12 + other_matrix.a12), (this->a21 + other_matrix.a21), (this->a22 + other_matrix.a22));
        }

        Matrix2x2 get_substraction(Matrix2x2 other_matrix){
            return Matrix2x2((this->a11 - other_matrix.a11), (this->a12 - other_matrix.a12), (this->a21 - other_matrix.a21), (this->a22 - other_matrix.a22));
        }

        Matrix2x2 get_multiplication(Matrix2x2 other_matrix){
            return Matrix2x2(((this->a11 * other_matrix.a11) + (this->a12 * other_matrix.a21)), ((this->a11 * other_matrix.a12) + (this->a12 * other_matrix.a22)),
                             ((this->a21 * other_matrix.a11) + (this->a22 * other_matrix.a21)), ((this->a21 * other_matrix.a12) + (this->a22 * other_matrix.a22)));
        }

        Matrix2x2 get_inverse(){
            return Matrix2x2(this->a22 / get_determinant(), -this->a12 / get_determinant(), -this->a21 / get_determinant(), this->a11 / get_determinant());
        }

        Matrix2x2 get_division(Matrix2x2 other_matrix){
            return get_multiplication(other_matrix.get_inverse());
        }

    private:
        double a11;
        double a12;
        double a21;
        double a22;
};