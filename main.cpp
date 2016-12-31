#include "matrix.hpp"

int main(void) {
    //Создание произвольной матрицы
    unsigned int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    Matrix ma(n, m);
    ma.randomFill();
    ma.print();
    
    //Поменять местами первую и последнюю строки, развернув их
    ma.swapRows(0, n-1);
    ma.invertRow(0);
    ma.invertRow(n-1);
    ma.print();
    
    //Удалить строку и столбец, на пересечении которых находится минимальный элемент
    int a, b;
    ma.min(a, b);
    ma.deleteRow(a);
    ma.deleteColumn(b);
    ma.print();

    //Ввести вторую матрицу с клавиатуры
    int q, w;
    cout << "n = ";
    cin >> q;
    cout << "m = ";
    cin >> w;
    Matrix ma2(q, w);
    ma2.fill();
    ma2.print();
 
    //Умножить матрицы
    Matrix c(ma.m, ma2.n);
    try {
        c = ma * ma2;
        cout << "Итоговая матрица:\n";
        c.print();
    } catch (exception e) {
        cout << "Умножить матрицы невозможно!\n";
    }
   
    return 0;
}
