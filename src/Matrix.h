#pragma once

#include <exception>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;


template<typename T>
using twoD = std::vector<std::vector<T>>;
//more info on the above: http://stackoverflow.com/a/16861385/3255842

template<class T>
class Matrix {
private:
    int rows;
    int cols;
    twoD<T> matrix;
protected:
    void validSizeCheck(int rows, int cols);

public:
    Matrix(int rows, int cols);

    Matrix(int rows, int cols, twoD<T> newMatrix);

    twoD<T> getMatrix();

    int getRows();

    int getCols();

    void operator=(const Matrix<T> &);

    Matrix<T> &operator+=(const Matrix<T> &);

    Matrix<T> &operator-=(const Matrix<T> &);

    Matrix<T> &operator*=(const Matrix<T> &);

    Matrix<T> &operator*=(const T &);


    friend void operator<<(ostream &os, const Matrix<T> &m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                os << m.matrix[i][j] << " ";
            }
            os << endl;
        }
        os << endl;
        os << endl;
    }


    void printMatrix();

    // Implement the functions below

    Matrix<T> operator+(const Matrix<T> &);//Matrix Addition

    Matrix<T> operator-(const Matrix<T> &);//Matrix Subtraction

    Matrix<T> operator*(const Matrix<T> &);//Matrix Multiplication

    Matrix<T> operator*(const T &);//Matrix Multiplication with a Scalar

};



template<class T>
void Matrix<T>::validSizeCheck(int rows, int cols) {
    //DO NOT MODIFY
    //This is a helper function for checking invalid size.
    if (rows < 1 || cols < 1) {
        throw exception();
    }
}


template<class T>
twoD<T> Matrix<T>::getMatrix() {
    //DO NOT MODIFY
    return matrix;
}

template<class T>
int Matrix<T>::getRows() {
    //DO NOT MODIFY
    return rows;
}

template<class T>
int Matrix<T>::getCols() {
    //DO NOT MODIFY
    return cols;
}


template<class T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    //DO NOT MODIFY
    validSizeCheck(rows, cols);
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
            //cout << "Writing: i: " << i << " j: " << j << " val: " << matrix[i][j] << endl;
        }
    }

}

template<class T>
Matrix<T>::Matrix(int rows, int cols, twoD<T> newMatrix) : rows(rows), cols(cols) {
    //DO NOT MODIFY
    validSizeCheck(rows, cols);
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }


}

template<class T>
void Matrix<T>::operator=(const Matrix<T> &rhs) {
    //DO NOT MODIFY

    if (rows != rhs.rows || cols != rhs.cols) {
        //throw exception
    }
    Matrix<T> newMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix.matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

template<class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this + rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this - rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this * rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(const T &rhs) {
    //DO NOT MODIFY
    *this = *this * rhs;
    return *this;
}

template<class T>
void Matrix<T>::printMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}


// Implement the functions here.
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs){
   Matrix<T> result(rows, cols);
    if(rows!=rhs.rows || cols!=rhs.cols){
        throw exception();
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return result;
}


template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs){
    Matrix<T> result(rows, cols);
    if(rows!=rhs.rows || cols!=rhs.cols){
        throw exception();
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = matrix[i][j] -  rhs.matrix[i][j];
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs){
    Matrix<T> result(rows, rhs.cols);
    if(cols!=rhs.rows){
        throw exception();
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const T &rhs){ //scalar multiplication
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = matrix[i][j] * rhs;
        }
    }
    return result;
}




