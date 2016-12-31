#include "matrix.hpp"

Matrix::Matrix(int _n, int _m) {
    n = _n;
    m = _m;
    matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int [m];
    }
}

void Matrix::fill() {
    int a; char c1, c2;
    for (int i = 0; (i < n && ((c1 = cin.get()) != '.')); i++) {
        cin.putback(c1);
        for (int j = 0; (j < m && ((c2 = cin.get()) != ',')); j++) {
            cin.putback(c2);
            cin >> a;
            matrix[i][j] = a;
        }
        cin.ignore(1);
    }
}

void Matrix::randomFill() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void Matrix::print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::swapRows(int n1, int n2) {
    int *temp = matrix[n1];
    matrix[n1] = matrix[n2];
    matrix[n2] = temp;
}

void Matrix::invertRow(int _n) {
    for (int i = 0, j = m-1; i < j; i++, j--) {
        swap(matrix[_n][i], matrix[_n][j]);
    }
}

void Matrix::deleteRow(int _n) {
    for (int i = _n; i < n-1; i++) {
        swapRows(i, i+1);
    }
    n--;
}

void Matrix::deleteColumn(int _m) {
    for (int i = 0; i < n; i++) {
        for (int j = _m; j < m-1; j++) {
            swap(matrix[i][j], matrix[i][j+1]);
        }
    }
    m--;
}

void Matrix::min(int &a, int &b) {
    int min = matrix[0][0];
    a = 0;
    b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                a = i;
                b = j;
            }
        }
    }
}

const Matrix operator *(Matrix &a, Matrix &b) {
    if (a.m != b.n) {
        throw exception();
    }
    Matrix c(a.n, b.m);
    for(int i = 0; i < c.n; i++) {
        for(int j = 0; j < c.m; j++) {
            for(int k = 0; k < a.m; k++)
                c.matrix[i][j] += a.matrix[i][k] *b.matrix[k][j];
        }
    }
    return c;
}
