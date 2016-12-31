#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
public:
    unsigned int n, m;
    int **matrix;
    Matrix(int, int);
    void fill(void);
    void randomFill(void);
    void print(void);
    void swapRows(int, int);
    void invertRow(int);
    void deleteRow(int);
    void deleteColumn(int);
    void min(int&, int&);
    friend const Matrix operator *(Matrix &a, Matrix &b);
};

#endif /* matrix_hpp */
