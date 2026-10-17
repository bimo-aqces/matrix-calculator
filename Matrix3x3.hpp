#include <iostream>
#include <cmath>

class Matrix3x3{
    public:
        Matrix3x3(double a11, double a12, double a13, 
            double a21, double a22, double a23, 
            double a31, double a32, double a33) : 
            a11(a11), a12(a12), a13(a13), 
            a21(a21), a22(a22), a23(a23), 
            a31(a31), a32(a32), a33(a33) {};

        void print() const {
            std::cout << a11 << " " << a12 << " " << a13 << "\n";
            std::cout << a21 << " " << a22 << " " << a23 << "\n";
            std::cout << a31 << " " << a32 << " " << a33 << "\n";
        }

        double get_magnitude(){
            return (((this->a11 * this->a22 * this->a33) + (this->a12 * this->a23 * this->a31) + (this->a13 * this->a21 * this->a32)) - 
                    ((this->a13 * this->a22 * this->a31) + (this->a12 * this->a21 * this->a33) + (this->a11 * this->a23 * this->a32)));
        }

        Matrix3x3 get_substraction(Matrix3x3 other_matrix){
            return Matrix3x3((this->a11 - other_matrix.a11), (this->a12 - other_matrix.a12), (this->a13 - other_matrix.a13), 
                            (this->a21 - other_matrix.a21), (this->a22 - other_matrix.a22), (this->a23 - other_matrix.a23), 
                            (this->a31 - other_matrix.a31), (this->a32 - other_matrix.a32), (this->a33 - other_matrix.a33));
        }

        Matrix3x3 get_addition(Matrix3x3 other_matrix){
            return Matrix3x3((this->a11 + other_matrix.a11), (this->a12 + other_matrix.a12), (this->a13 + other_matrix.a13),
                            (this->a21 + other_matrix.a21), (this->a22 + other_matrix.a22), (this->a23 + other_matrix.a23),
                            (this->a31 + other_matrix.a31), (this->a32 + other_matrix.a32), (this->a33 + other_matrix.a33));
        }

        Matrix3x3 get_multiplication(Matrix3x3 other_matrix) {
            return Matrix3x3(((this->a11 * other_matrix.a11) + (this->a12 * other_matrix.a21) + (this->a13 * other_matrix.a31)), ((this->a11 * other_matrix.a12) + (this->a12 * other_matrix.a22) + (this->a13 * other_matrix.a32)), ((this->a11 * other_matrix.a13) + (this->a12 * other_matrix.a23) + (this->a13 * other_matrix.a33)),
                             ((this->a21 * other_matrix.a11) + (this->a22 * other_matrix.a21) + (this->a23 * other_matrix.a31)), ((this->a21 * other_matrix.a12) + (this->a22 * other_matrix.a22) + (this->a23 * other_matrix.a32)), ((this->a21 * other_matrix.a13) + (this->a22 * other_matrix.a23) + (this->a23 * other_matrix.a33)),
                             ((this->a31 * other_matrix.a11) + (this->a32 * other_matrix.a21) + (this->a33 * other_matrix.a31)), ((this->a31 * other_matrix.a12) + (this->a32 * other_matrix.a22) + (this->a33 * other_matrix.a32)), ((this->a31 * other_matrix.a13) + (this->a32 * other_matrix.a23) + (this->a33 * other_matrix.a33)));
        }
        Matrix3x3 get_inverse(){
            double det = get_magnitude();

            return Matrix3x3(
                ((a22 * a33) - (a23 * a32)) / det, -((a12 * a33) - (a13 * a32)) / det, ((a12 * a23) - (a13 * a22)) / det,
                -((a21 * a33) - (a23 * a31)) / det, ((a11 * a33) - (a13 * a31)) / det, -((a11 * a23) - (a13 * a21)) / det,
                ((a21 * a32) - (a22 * a31)) / det, -((a11 * a32) - (a12 * a31)) / det, ((a11 * a22)- (a12 * a21)) / det);
        }

        Matrix3x3 get_division(Matrix3x3 other_matrix){
            return this->get_multiplication(other_matrix.get_inverse());
        }

    private:
        double a11;
        double a12;
        double a13;
        double a21;
        double a22;
        double a23;
        double a31;
        double a32;
        double a33;
};