#include <iostream>

using namespace std;

class Matrix3D {
private:
    double matrix[3][3];

public:
    Matrix3D(const double data[3][3] = {0}) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                matrix[i][j] = data[i][j];
            }
        }
    }

    double det() const {
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
               matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
               matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    }

    Matrix3D determinantMatrix() const {
        Matrix3D result;

        result.matrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
        result.matrix[0][1] = matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2];
        result.matrix[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];

        result.matrix[1][0] = matrix[2][1] * matrix[0][2] - matrix[2][2] * matrix[0][1];
        result.matrix[1][1] = matrix[2][2] * matrix[0][0] - matrix[2][0] * matrix[0][2];
        result.matrix[1][2] = matrix[2][0] * matrix[0][1] - matrix[2][1] * matrix[0][0];

        result.matrix[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
        result.matrix[2][1] = matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2];
        result.matrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

        return result;
    }

    Matrix3D inverse() const {
        Matrix3D result;
        result = determinantMatrix();

        double determinant = det();

        if (determinant == 0.0) {
            cerr << "Matrix is singular, cannot find the inverse." << endl;
            return result;
        }

        double invDet = 1.0 / determinant;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.matrix[i][j] *= invDet;
            }
        }

        return result;
    }

    Matrix3D operator+(const Matrix3D& mat2) const {
        Matrix3D result;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.matrix[i][j] = matrix[i][j] + mat2.matrix[i][j];
            }
        }
    }

    Matrix3D operator-(const Matrix3D& mat2) const {
        Matrix3D result;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.matrix[i][j] = matrix[i][j] - mat2.matrix[i][j];
            }
        }

        return result;
    }


    Matrix3D operator*(const Matrix3D& mat2) const {
        Matrix3D result;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.matrix[i][j] = 0.0;
                for (int k = 0; k < 3; ++k) {
                    result.matrix[i][j] += matrix[i][k] * mat2.matrix[k][j];
                }
            }
        }

        return result;
    }

    void print() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    double data1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double data2[3][3] = {{9.0, 8.0, 7.0}, {6.0, 5.0, 4.0}, {3.0, 2.0, 1.0}};

    Matrix3D mat1(data1);
    Matrix3D mat2(data2);

    cout << "Matrix 1:" << endl;
    mat1.print();

    cout << "Matrix 2:" << endl;
    mat2.print();

    Matrix3D mat3 = mat1 + mat2;
    Matrix3D mat4 = mat1 - mat2;
    Matrix3D mat5 = mat1 * mat2;

    cout << "Matrix 1 + Matrix 2:" << endl;
    mat3.print();

    cout << "Matrix 1 - Matrix 2:" << endl;
    mat4.print();

    cout << "Matrix 1 * Matrix 2:" << endl;
    mat5.print();

    return 0;
}
